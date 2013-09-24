#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    earth = 0.97;
    jupiter = 2.48;
    moon = 0.16;
    gravity = earth;
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<balls.size(); i++){
        balls[i].update(gravity);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<balls.size(); i++){
        balls[i].draw();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'e' || key == 'E'){
        gravity = earth;
    }
    if(key == 'j' || key == 'J'){
        gravity = jupiter;
    }
    if(key == 'm' || key == 'M'){
        gravity = moon;
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
    Ball b = Ball(mouseX, mouseY);
    balls.push_back(b);
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
