#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetVerticalSync(true);
    ofBackground(0,0,0);
    ofSetCircleResolution(150);
    ofEnableSmoothing();
    ofSetFrameRate(60);
    u1.setFreq(2.5);
    u1.setAmp(480);
    u1.setLineWidth(3.0);
    u1.setColor(ofColor(50, 255, 200));
    u2.setFreq(1.5);
    u2.setAmp(480);
    u2.setLineWidth(2.0);
    u2.setColor(ofColor(255, 55, 120));
    u3.setFreq(2.5);
    u3.setAmp(800);
    u3.setLineWidth(2.0);
    u3.setColor(ofColor(50, 55, 255));
    u4.setFreq(7.5);
    u4.setAmp(500);
    u4.setLineWidth(2.0);
    u4.setColor(ofColor(150, 55, 255));
    u5.setFreq(5.5);
    u5.setAmp(500);
    u5.setLineWidth(1.1);
    u5.setColor(ofColor(35, 35, 50));
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    u1.draw();
    u2.draw();
    u3.draw();
    u4.draw();
    u5.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    u1.amp = x;
    u2.amp = y;
    u3.amp = x;
    u4.amp = y;
    u5.amp = x;
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
