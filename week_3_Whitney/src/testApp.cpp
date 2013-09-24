#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    R = 0;
    r = 0;
    p = 10;
    ofBackground(0);
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
//    R = mouseX;
//    r = mouseY;
    R = ofMap(sin(ofGetElapsedTimeMillis()), -1, 1, 0, 1)*300;
    r = ofMap(sin(ofGetElapsedTimeMillis()), -1, 1, 0, 1)*300;
    pos.x=(R+r)*cos(ofGetElapsedTimeMillis()) + p*cos((R+r)*(ofGetElapsedTimeMillis())/r);
    pos.y=(R+r)*sin(ofGetElapsedTimeMillis()) + p*sin((R+r)*(ofGetElapsedTimeMillis())/r);
    pts.push_back(pos);
    if (pts.size() > (10*(sin(ofGetElapsedTimef())))){
		pts.erase(pts.begin());
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(ofRandom(255));
    ofFill();
    ofTranslate(512,384);
    ofRotate(ofGetElapsedTimeMillis()/10.0);
    for(int i=0; i<pts.size(); i++){
        ofCircle(pts[i], 2);
    }
    ofNoFill();
    ofSetLineWidth(5.0*ofMap(sin(ofGetElapsedTimeMillis()), -1.0,1.0,0.0,1.0));
    ofBeginShape();
    for(int i=0; i<pts.size(); i++){
        ofVertex(pts[i].x,pts[i].y);
    }
    ofEndShape();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'q'){
        p -= 1;
    }
    if(key == 'w'){
        p += 1;
    }
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
