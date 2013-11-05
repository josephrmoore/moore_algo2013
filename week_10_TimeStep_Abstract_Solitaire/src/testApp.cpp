#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255);
    newDeck();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    current_card = cards.size()-1;
    current_time = ofGetElapsedTimeMillis();
    lastTime = ofGetElapsedTimef();
    timeScale = 1.0;
}

//--------------------------------------------------------------
void testApp::update(){
    float dt = ofGetElapsedTimef() - lastTime;
    lastTime = ofGetElapsedTimef();
    
    if(ofGetElapsedTimeMillis()-current_time>100){
        current_time = ofGetElapsedTimeMillis();
        if(current_card>0){
            cards[current_card].falling = true;
            cards[current_card].addForce(ofVec2f(ofRandom(-1,1),0));
            current_card--;
        } else {
            newDeck();
            current_card = cards.size()-1;
        }
    }
    for(int i=0; i<cards.size(); i++){
        if(cards[i].falling){
            cards[i].addForce(ofVec2f(0,0.1));
        }
        cards[i].update(dt * timeScale);
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
    ofSaveFrame();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    timeScale = ofMap( x, 0, ofGetWindowWidth(), -3, 3 );
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
    ofColor col = ofColor(255,0,0,ofRandom(100,200));
    float colorstep = 5;
    float card_w = 12;
    float card_h = 20;
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
        ace.color = col;
        ace.width = ofRandom(card_w*0.85,card_w);
        ace.height = ofRandom(card_h*0.75,card_h);
        col.setHue(col.getHue()+colorstep);
        col.setSaturation(ofRandom(100,200));
        col.setBrightness(ofRandom(100,200));
        cards.push_back(ace);
        for(int j=2; j<11; j++){
            Card c = Card(suit, ofToString(j));
            c.pos = p;
            c.color = col;
            c.width = ofRandom(card_w*0.85,card_w);
            c.height = ofRandom(card_h*0.75,card_h);
            col.setHue(col.getHue()+colorstep);
            col.a = ofRandom(100,200);
            cards.push_back(c);
        }
        Card jack = Card(suit, "J");
        jack.pos = p;
        jack.color = col;
        jack.width = ofRandom(card_w*0.85,card_w);
        jack.height = ofRandom(card_h*0.75,card_h);
        col.setHue(col.getHue()+colorstep);
        col.setSaturation(ofRandom(100,200));
        col.setBrightness(ofRandom(100,200));
        col.a = ofRandom(100,200);
        cards.push_back(jack);
        Card queen = Card(suit, "Q");
        queen.pos = p;
        queen.color = col;
        queen.width = ofRandom(card_w*0.85,card_w);
        queen.height = ofRandom(card_h*0.75,card_h);
        col.setHue(col.getHue()+colorstep);
        col.setSaturation(ofRandom(100,200));
        col.setBrightness(ofRandom(100,200));
        col.a = ofRandom(100,200);
        cards.push_back(queen);
        Card king = Card(suit, "K");
        king.pos = p;
        king.color = col;
        king.width = ofRandom(card_w*0.85,card_w);
        king.height = ofRandom(card_h*0.75,card_h);
        col.setHue(col.getHue()+colorstep);
        col.setSaturation(ofRandom(100,200));
        col.setBrightness(ofRandom(100,200));
        col.a = ofRandom(100,200);
        cards.push_back(king);
    }
}