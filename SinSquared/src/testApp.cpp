#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofEnableAlphaBlending();
    ofBackground(0);
     glEnable(GL_DEPTH_TEST);
    sound.loadSound("sevenstars.mp3");
    sound.play();
    for(int i=0; i<2; i++){
        d = Dot();
        dots.push_back(d);
    }
    bk = true;
    ofSetBackgroundAuto(bk);
}

//--------------------------------------------------------------
void testApp::update(){
    
    if(ofGetElapsedTimef()>6){
            
        if((int)ofGetElapsedTimef() % 3 == 0 && ofGetElapsedTimef() > 15){
            if(ofRandom(10)<=5.0){
                if(bk == false){
                    i.grabScreen(0,0,ofGetWidth(), ofGetHeight());
                }
                bk = true;
            } else {
                bk = false;
            }
            ofSetBackgroundAuto(bk);
        }
        
        if(ofGetElapsedTimef() > 59){
            if(dots.size()>=1){
                dots.erase(dots.begin());
            }
        } else if(ofGetElapsedTimef() < 56){
            if(ofGetElapsedTimef()*2 > dots.size()){
                d = Dot();
                dots.push_back(d);
            }
        }
    }
    for(int i=0; i<dots.size(); i++){
//        dots[i].pos.x = i*c(c(50.0, i*4.0, true), i*4.0, false);
//        dots[i].pos.y = i*s(s(30.0, i*3.0, true), i*3.0, false);
//        dots[i].vel.x = i*c(c(50.0, i*4.0, true), i*4.0, false);
//        dots[i].vel.y = i*s(s(30.0, i*3.0, true), i*3.0, false);
        dots[i].radius.x = s(s(50.0, i*4.0, true), i*4.0, false);
        dots[i].radius.y = s(s(50.0, i*4.0, true), i*4.0, false);
        dots[i].opacity = s(255.0, i*4.0, true);
        dots[i].pos.x = c(c(c(500.0, i*40.0, true), i*4.0, true), i*4.0, false);
        dots[i].pos.y = s(300.0, i*3.0, false);
        dots[i].color = ofColor(c(255.0, i*s(10.0,200.0,true), false)-ofMap(mouseX, 0.0,1024.0,0.0,255.0), s(255.0, i*s(10.0,200.0,true), false)-ofMap(mouseY, 0.0,1024.0,0.0,255.0), c(510.0, i*s(4.0, i, true), false)/2, dots[i].opacity);
//        dots[i].vel.x = i*c(c(50.0, i*4.0, true), i*4.0, false);
//        dots[i].vel.y = i*s(s(30.0, i*3.0, true), i*3.0, false);
//        dots[i].radius.x = c(c(50.0, i*4.0, true), i*4.0, false);
//        dots[i].radius.y = s(s(50.0, i*4.0, true), i*4.0, false);
        dots[i].pos += dots[i].vel;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();{
        i.draw(0,0,-1,ofGetWidth(), ofGetHeight());
        ofTranslate(512,384);
        ofRotate(ofGetElapsedTimeMillis()/7.0);
        ofTranslate(-512,-384);
    ofTranslate(512,384);
    if((ofGetElapsedTimef()>10 && ofGetElapsedTimef()<30) || ofGetElapsedTimef()>50){
        ofRotate(s(ofGetElapsedTimef()*50, 200.0, true));
    }

    for(int i=0; i<dots.size(); i++){
        dots[i].draw();
    }

    }; ofPopMatrix();
//    ofNoFill();
//    ofBeginShape();
//    for(int i=0; i<dots.size(); i++){
//        ofVertex(dots[i].pos.x,dots[i].pos.y);
//    }
//    ofEndShape();
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

float testApp::s(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * sin(ofGetElapsedTimeMillis()/period);
    }
    return f;
}

float testApp::c(float mult, float period, bool norm){
    float f;
    if(norm){
        f = mult * ofMap(sin(ofGetElapsedTimeMillis()/period), -1.0, 1.0, 0.0, 1.0);
    } else {
        f = mult * cos(ofGetElapsedTimeMillis()/period);
    }
    return f;
}