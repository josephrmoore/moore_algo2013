#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetBackgroundAuto(false);
    c = ofColor(0,0,255);
    type = 1;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(c);
    ofFill();
    if(type==1){
        ofCircle(ofPoint(mouseX, mouseY), ofRandom(20,40));
    } else if (type==2){
        ofRect(mouseX, mouseY, ofRandom(20,40), ofRandom(20,40));
    } else {
        ofLine(mouseX, mouseY, ofGetScreenWidth()/2, ofGetScreenHeight()/2);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == ' '){
        c = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
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
    if(type==3){
        type=0;
    } else {
        type++;
    }
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
