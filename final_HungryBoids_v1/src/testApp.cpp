#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box.init();
	box.setGravity(0, 5);
	box.setFPS(30.0);
    box.createGround();
//    ofRectangle bounds(0, 0, ofGetWidth(), ofGetHeight());
//    box.createBounds(bounds);
//    box.setBounds(ofVec2f(0,0),ofVec2f(ofGetWidth(),ofGetHeight()));

    box.enableGrabbing();
    box.registerGrabbing();
    level.setup(box.getWorld());
    center.set(ofGetWidth()/2,ofGetHeight()/2);
    level.flocker.x = center.x;
    level.flocker.y = center.y;
    level.copter.bait.setPhysics(9.0, 0.01, 0.001);
    level.copter.bait.setup(box.getWorld(), 0, 0, 10);
    noise.loadSound("boids_noise.wav");
    noise.setLoop(true); //Sound will loop
    noise.setMultiPlay(true);
    noise.play();
    ofVec2f dist;
    dist = level.flocker.center-ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    center_perc = dist.length();
}

//--------------------------------------------------------------
void testApp::update(){
    box.update();
    level.update(checkBricks());
    level.copter.bait.update();
    level.flocker.x = level.copter.bait.pos.x;
    level.flocker.y = level.copter.bait.pos.y;
    b2World* b = box.getWorld();
    ofVec2f dist;
    dist = level.flocker.center-ofVec2f(ofGetWidth()/2,ofGetHeight()/2);
    center_perc = dist.length();
    cout<<center_perc<<endl;
    trill.setVolume(ofClamp(ofMap(center_perc, 500, 100, 0, 1.0), 0, 1.0));
}

//--------------------------------------------------------------
void testApp::draw(){
    level.draw();
    if(level.level>0  && !level.won){
        for(int i=0; i<boxes.size(); i++){
            boxes[i].draw();
        }
        if(!level.copter.bait.eaten){
            level.copter.bait.draw();
        }
    }
}

void testApp::makeShape(float x, float y, float w, float h){
    Brick r;
    r.setPhysics(3.0, 0.03, 1.0);
    r.setup(box.getWorld(), x, y, w*B2D, h*B2D);
    boxes.push_back(r);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    if(level.level>0 && !level.won && key=='z'){
        level.copter.drop();
    }
    
    
    if(level.won){
        if(key == ' '){

            ++level.level;
            level.load(level.level);
            for(int i=0; i<boxes.size(); i++){
                boxes[i].destroy();
            }
            boxes.clear();
            makeShape(100.0, ofGetHeight()-100);
            makeShape(200.0, ofGetHeight()-100);
            makeShape(300.0, ofGetHeight()-100);
            makeShape(400.0, ofGetHeight()-100);
            makeShape(500.0, ofGetHeight()-100);
            makeShape(600.0, ofGetHeight()-100);
            makeShape(700.0, ofGetHeight()-100);
            makeShape(800.0, ofGetHeight()-100);
            makeShape(200.0, ofGetHeight()-220);
            makeShape(400.0, ofGetHeight()-240);
            makeShape(800.0, ofGetHeight()-220);
            makeShape(600.0, ofGetHeight()-240);
            makeShape(100.0, ofGetHeight()-220);
            makeShape(300.0, ofGetHeight()-240);
            makeShape(500.0, ofGetHeight()-220);
            makeShape(700.0, ofGetHeight()-240);
        }
    }
    if(level.level == 0 || level.level == -1){
        noise.stop();
        all.loadSound("boids_notrill.wav");
        all.setLoop(true); //Sound will loop
        all.setMultiPlay(true);
        all.play();
        trill.loadSound("boids_trill.wav");
        trill.setLoop(true); //Sound will loop
        trill.setMultiPlay(true);
        trill.play();
        level.copter.bait.lifetime=0.001;
        level.copter.bait.drop(ofVec2f(-ofGetWidth(), -ofGetHeight()));
        level.load(1);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(200.0, ofGetHeight()-100);
        makeShape(400.0, ofGetHeight()-100);
        makeShape(600.0, ofGetHeight()-100);
        makeShape(800.0, ofGetHeight()-100);
        makeShape(200.0, ofGetHeight()-220);
        makeShape(400.0, ofGetHeight()-240);
        makeShape(800.0, ofGetHeight()-220);
        makeShape(600.0, ofGetHeight()-240);
        if(level.level == -1){
            if(key == 'q' || key == 'Q'){
                level.load(0);
                for(int i=0; i<boxes.size(); i++){
                    boxes[i].destroy();
                }
                boxes.clear();
            }
        }
    }
}

bool testApp::checkBricks(){
    bool anyhigh = false;
    int totalin = 0;
    for(int i=0; i<boxes.size(); i++){
//        cout<<"box"<<i<<" "<<"pos y: "<<boxes[i].getPosition().y<<endl;
//        cout<<"ofHeight: "<<ofGetHeight()<<" level height: "<<level.height<<endl;
//        cout<<"ofHeight-levelheight: "<<ofGetHeight()-level.height<<endl;
//        cout<<"height: "<<boxes[i].getHeight()<<" width: "<<boxes[i].getWidth()<<endl;

        if(boxes[i].getPosition().y<ofGetHeight()-level.height){
            anyhigh = true;
        }
        if(boxes[i].getPosition().x>0&&boxes[i].getPosition().x<ofGetWidth()){
            float h = boxes[i].getHeight()/B2D;
            float w = boxes[i].getWidth()/B2D;
            if(w>h){
                totalin += w;
            } else {
                totalin += h;
            }
        }
        if(boxes[i].getVelocity().y>0.1){
            return false;
        }
    }
//    cout<<"totalin: "<<totalin<<endl;
    if(totalin<level.height){
        return false;
    }
    return anyhigh;
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    level.flocker.reset();
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
