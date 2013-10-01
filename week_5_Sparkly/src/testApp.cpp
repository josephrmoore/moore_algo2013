#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
    
	for (int i=0; i < particleList.size(); i++){
		particleList[i].resetForces();
		particleList[i].addDampingForce();
		particleList[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofFill();
    ofSetColor(0);
    for (int i=0; i < particleList.size(); i++){
        particleList[i].draw();
    }
    
    ofNoFill();
    
	ofBeginShape();
	for (int i = 0; i < particleList.size(); i++){
		ofVertex(particleList[i].pos.x, particleList[i].pos.y);
	}
	ofEndShape();
}

void testApp::addParticle() {
    Particle myParticle;
    
    float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    myParticle.setParams(300,300,vx, vy);
    
    particleList.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    
    ofPoint difference = ofPoint(x,y) - lastMousePos;
    
    Particle myParticle;
    
    //    float vx = ofRandom(-4,4);
    //    float vy = ofRandom(-4,4);
    myParticle.setParams(x, y, difference.x, difference.y);
    
    particleList.push_back(myParticle);
    
    
    lastMousePos.set(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    particleList.clear();
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

float testApp::s(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * sin(ofGetElapsedTimeMillis()/period);
    }
    return f;
}

float testApp::c(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * cos(ofGetElapsedTimeMillis()/period);
    }
    return f;
}

float testApp::xeno(float target, float speed, float current){
    return (speed*target) + ((1-speed)*current);
}

ofPoint testApp::xeno(ofPoint p, float catchX, float catchY, float cX, float cY){
    p.x = (cX*catchX) + ((1-cX)*p.x);
    p.y = (cY*catchY) + ((1-cY)*p.y);
    return p;
}