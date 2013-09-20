#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

    for(vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); it++){
        it->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(vector<Firework>::iterator it=fireworks.begin(); it!=fireworks.end(); it++){
        it->draw(mouseX, mouseY);
    }
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
    Firework f;
    f.setup();
    fireworks.push_back(f);
    cout<<mouseX<<" "<<mouseY<<endl;

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
