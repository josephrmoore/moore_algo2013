#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bk.loadImage("bk.jpg");
    redS.loadImage("p1.png");
    blondeS.loadImage("p2.png");
    brownS.loadImage("p3.png");
    blackS.loadImage("p4.png");
    red.allocate(25, 25);
    blonde.allocate(25, 25);
    brown.allocate(25, 25);
    black.allocate(25, 25);
    red.begin();
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    ofSetColor(255, 255, 255, 255);
    redS.draw(0,0);
    red.end();
    blonde.begin();
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    ofSetColor(255, 255, 255, 255);
    blondeS.draw(0,0);
    blonde.end();
    brown.begin();
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    ofSetColor(255, 255, 255, 255);
    brownS.draw(0,0);
    brown.end();
    black.begin();
    // to prevent uncleared video memory!
    ofSetColor(255, 255, 255, 0);
    ofClear(255, 255, 255, 0);
    ofSetColor(255, 255, 255, 255);
    blackS.draw(0,0);
    black.end();
    for(int i=0; i<1; i++){
        int person = (int)ofRandom(1,5);
        if(person == 1){
            f = red;
        } else if (person == 2){
            f = blonde;
        } else if (person == 3){
            f = brown;
        } else {
            // person == 4
            f = black;
        }
        Particle p(f);
        p.setParams(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-2,2), ofRandom(-2,2));
        people.push_back(p);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for(int i=0; i<people.size(); i++){
        people[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    bk.draw(0, 0);
    for(int i=0; i<people.size(); i++){
        people[i].draw();
    }

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    int person = (int)ofRandom(1,5);
    ofFbo f;
    if(person == 1){
        f = red;
    } else if (person == 2){
        f = blonde;
    } else if (person == 3){
        f = brown;
    } else {
        // person == 4
        f = black;
    }
    Particle p(f);
    p.setParams(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-2,2), ofRandom(-2,2));
    people.push_back(p);
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
