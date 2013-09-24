ArrayList <TimePoint> pointList = new ArrayList<TimePoint>();      // we called this "points" during class. Renamed for clarity.
float startTime;
float playbackStartTime;
boolean bIsRecording;

void setup() {
  size(800, 600);
  bIsRecording = false;
  playbackStartTime = 0;
  startTime = 0;
}

void draw() {
  background(255);
  noFill();
  beginShape();
  for (int i = 0; i < pointList.size(); i++) {
    vertex(pointList.get(i).x, pointList.get(i).y);
  }

  endShape();

  PVector pos = getPositionForTime(millis()/1000.0 - playbackStartTime);
  PVector vel = getVelocityForTime(millis()/1000.0 - playbackStartTime);

  float angle = atan2( vel.y, vel.x );    // remember that y comes before x. It also works because velocity has a direction. Pos does not.
  float vecLen = vel.mag();            // the length of our velocity vector

  fill(255, 0, 0); 
  rectMode(CENTER);

  pushMatrix();
  {
    translate(pos.x, pos.y);
    rotate( degrees(angle) );
    rect(0, 0, 50 + vecLen*0.5, 50);
  }
  popMatrix();
}

void mousePressed() {
  bIsRecording = true;
  pointList = new ArrayList();
  startTime = millis()/1000.0;
  TimePoint temp = new TimePoint(mouseX, mouseY, 0);
  pointList.add(temp);
}

void mouseReleased() {
  bIsRecording = false;
  playbackStartTime = millis()/1000.0;
  println(playbackStartTime);
}

void mouseDragged(){
  TimePoint temp = new TimePoint(0,0,0);
  temp.x = mouseX;
  temp.y = mouseY;
  temp.t = millis()/1000.0 - startTime;
  pointList.add(temp);
}

PVector getPositionForTime(float time) {
  if (bIsRecording == true || pointList.size() < 2) {
    PVector t = new PVector(0, 0);
    return t;
  }

  TimePoint p = pointList.get(pointList.size()-1);

  while (time > p.t) {
    time -= p.t;
  }

  PVector pos = new PVector();

  for (int i = 0; i < pointList.size()-1; i++) {

    if (time >= pointList.get(i).t && time < pointList.get(i+1).t) {

      float part = time - pointList.get(i).t;
      float whole = pointList.get(i+1).t - pointList.get(i).t;
      float pct = part / whole;

      pos.x = (1-pct) * pointList.get(i).x + (pct) * pointList.get(i+1).x;
      pos.y = (1-pct) * pointList.get(i).y + (pct) * pointList.get(i+1).y;
    }
  }

  return pos;
}
PVector getVelocityForTime(float time) {
  PVector prevPt = getPositionForTime( max(time - 0.09f, 0));    // Where we were 0.09 seconds ago. 
  PVector currPt = getPositionForTime(time);                      // Where we are now!

  PVector diff = new PVector();
  diff.x = currPt.x - prevPt.x;
  diff.y = currPt.y - prevPt.y;

  return diff;
}

