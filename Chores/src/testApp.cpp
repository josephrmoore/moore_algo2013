#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    sound.loadSound("chores.mp3");
    // protagonist
    Pro protagonist = Pro();
    dots.push_back(protagonist);
    // antagonist
    Ant antagonist = Ant();
    dots.push_back(antagonist);
    // rain of dots
    for(int i=0; i<100; i++){
        Dot dot = Dot();
        dots.push_back(dot);
    }
    ofBackground(125);
}

//--------------------------------------------------------------
void testApp::update(){
    if(ofGetElapsedTimef() > 5 && sound_started == false){
        sound.play();
        sound_started = true;
    }
    for(int i=0; i<dots.size(); i++){
        dots[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        ofRotateX(sin(ofGetElapsedTimef()));
    for(int i=0; i<dots.size(); i++){
        if(i == 0){
            //        dots[i].shake(10);
            dots[i].breathe(600, 1.3);
        } else if (i == 1){
            dots[i].breathe(0, 1.2, true);
        }
        dots[i].draw();
    }
    };ofPopMatrix();
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
