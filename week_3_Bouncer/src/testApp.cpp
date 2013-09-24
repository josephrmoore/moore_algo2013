#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    head.loadImage("bodyguard_head.png");
    arms.loadImage("bodyguard_shoulder.png");
    legs.loadImage("bodyguard_legs.png");
    pos.x = 0;
    pos.y = 0;
    start.x = pos.x;
    start.y = pos.y;
}

//--------------------------------------------------------------
void testApp::update(){
    pos.y += (cos(ofGetElapsedTimef()*3))/3.5;
}

//--------------------------------------------------------------
void testApp::draw(){
    legs.draw(start.x,start.y);
    arms.draw(pos.x,pos.y);
    head.draw(start.x,start.y);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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