#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0);
    attracting = false;
    repelling = false;
    for(int i=0; i<1000; i++){
        Particle p;
        particles.push_back(p);
    }
    for(int i=0; i<particles.size(); i++){
        ps.push_back(&particles[i]);
    }
    cout<<particles.size()<<endl;
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void testApp::update(){
    if(attracting){
        cursor_color = ofColor(0,0,255);
    } else if(repelling){
        cursor_color = ofColor(255,0,0);
    } else {
        cursor_color = ofColor(200);
    }
    for(int i=0; i<particles.size(); i++){
        if(attracting){
            ps[i]->addAttractionForce(mouseX, mouseY, 1000, 5);
        }
        if(repelling){
            ps[i]->addRepulsionForce(mouseX, mouseY, 1000, 5);
        }
        ps[i]->update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0, 5);
    ofRect(0,0,ofGetWidth(),ofGetHeight());
//    ofSetColor(cursor_color);
//    ofRect(cursor_pos.x,cursor_pos.y,20,20);
    for(int i=0; i<particles.size(); i++){
        ofSetColor(ps[i]->color);
        ps[i]->draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == '1'){
        attracting = true;
    }
    if(key == '2'){
        repelling = true;
    }
    if(key == '3'){
        for(int i=0; i<ps.size(); i++){
            ps[i]->pos.x = ofRandom(ofGetWidth());
            ps[i]->pos.y = ofRandom(ofGetHeight());
        }
    }
    if(key == '4'){
        for(int i=0; i<ps.size(); i++){
            if(ps[i]->radius>1){
                ps[i]->radius *= 0.95;
            }
//            ps[i]->color.r = ps[i]->color.r+ofRandom(3);
//            ps[i]->color.g = ps[i]->color.g+ofRandom(3);
//            ps[i]->color.b = ps[i]->color.b+ofRandom(3);
        }
    }
    if(key == '5'){
        for(int i=0; i<ps.size(); i++){
            if(ps[i]->radius<30){
                ps[i]->radius *= 1.05;
                
            }
//            ps[i]->color.r = ps[i]->color.r+ofRandom(3);
//            ps[i]->color.g = ps[i]->color.g+ofRandom(3);
//            ps[i]->color.b = ps[i]->color.b+ofRandom(3);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == '1'){
        attracting = false;
    }
    if(key == '2'){
        repelling = false;
    }

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    cursor_pos.x = x-5;
    cursor_pos.y = y-5;
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
