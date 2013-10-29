#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0);
    dest = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
//    car.pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
//    car.vel = ofVec2f(10, -5);
//    ofSetBackgroundAuto(false);
    for(int i=0; i<5; i++){
        Particle p;
        p.pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        p.vel = ofVec2f(ofRandom(-10,10), ofRandom(-10,10));
        cars.push_back(p);
    }
}

//--------------------------------------------------------------
void testApp::update(){
//    car.seek(dest, cars);
//    car.update();
    for(int i=0; i< cars.size(); i++){
        cars[i].seek(dest, cars);
        cars[i].update();
        for(int j=0; j<cars.size();j++){
            if(cars[i].pos.distance(cars[j].pos)<100){
                cars[i].addRepulsionForce(cars[j].pos);
                cars[j].addRepulsionForce(cars[i].pos);
            }
        }
        if(cars[i].pos.distance(dest)<5){
            dest = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
//    car.draw();
    for(int i=0; i< cars.size(); i++){
        cars[i].draw();
    }
    ofSetColor(255,0,0);
    ofRect(dest.x, dest.y, 5, 5);
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
