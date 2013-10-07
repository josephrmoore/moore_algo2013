#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    newDeck();
    ofSetVerticalSync(true);
    ofSetBackgroundAuto(false);
    current_card = cards.size()-1;
    current_time = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(ofGetElapsedTimeMillis()-current_time>300){
        cards[current_card].falling = true;
        current_card--;
        current_time = ofGetElapsedTimeMillis();
        cards[current_card].addForce(ofVec2f(ofRandom(-1,1),0));
    }
    for(int i=0; i<cards.size(); i++){
        if(cards[i].falling){
            cards[i].addForce(ofVec2f(0,0.1));
        }
        cards[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<cards.size(); i++){
        cards[i].draw();
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

void testApp::newDeck(){
    for(int i=0; i<4; i++){
        string suit;
        ofVec2f p;
        if(i==0){
            suit = "H";
            p = ofVec2f(100,0);
        } else if (i==1){
            suit = "S";
            p = ofVec2f(300,0);
        } else if (i==2){
            suit = "D";
            p = ofVec2f(500,0);
        } else {
            suit = "C";
            p = ofVec2f(700,0);
        }

        Card ace = Card(suit, "A");
        ace.pos = p;
        cards.push_back(ace);
        for(int j=2; j<11; j++){
            Card c = Card(suit, ofToString(j));
            c.pos = p;
            cards.push_back(c);
        }
        Card jack = Card(suit, "J");
        jack.pos = p;
        cards.push_back(jack);
        Card queen = Card(suit, "Q");
        queen.pos = p;
        cards.push_back(queen);
        Card king = Card(suit, "K");
        king.pos = p;
        cards.push_back(king);
    }
}