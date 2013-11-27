#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    t.setLimit(1100);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    p1.active = true;
}

//--------------------------------------------------------------
void testApp::update(){
    t.update();
    if(t.activate == true){
        // action to perform on timer rollover
        if(p1.active == false){
            p1.active = true;
            p2.active = false;
        } else {
            p1.active = false;
            p2.active = true;
        }
        t.reset();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if(p1.active){
        ofBackground(0);
    }
    if(p2.active){
        ofBackground(255);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(p1.active){
        cout<<"p1"<<endl;
    }
    if(p2.active){
        cout<<"p2"<<endl;
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
