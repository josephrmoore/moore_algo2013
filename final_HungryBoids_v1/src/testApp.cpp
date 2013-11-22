#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box.init();
	box.setGravity(0, 10);
	box.setFPS(30.0);
    box.createGround();
    box.enableGrabbing();
    level.setup(box.getWorld());
    center.set(ofGetWidth()/2,ofGetHeight()/2);
    level.flocker.x = center.x;
    level.flocker.y = center.y;
}

//--------------------------------------------------------------
void testApp::update(){
    box.update();
    level.update();
}

//--------------------------------------------------------------
void testApp::draw(){
//    cam.begin();
    level.draw();
    for(int i=0; i<boxes.size(); i++){
        boxes[i].draw();
    }
//    cam.end();
    ofPushStyle();
    ofSetColor(255,0,0);
    ofCircle(center,sin(ofGetElapsedTimef())*2+7);
    ofPopStyle();
}

void testApp::makeShape(int type, float x, float y){
    float w, h;
    if(type == 0){
        // square20
        w = 20.0;
        h = 20.0;
    } else if (type == 1){
        // square40
        w = 40.0;
        h = 40.0;
    } else if (type == 2){
        // rect20x200
        w = 20.0;
        h = 100.0;
    } else if (type == 3){
        // rect200x20
        w = 200.0;
        h = 20.0;
    } else {
        return;
    }
    Brick r;
    r.setPhysics(3.0, 0.53, 0.1);
    r.setup(box.getWorld(), x, y, w, h);
    boxes.push_back(r);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == '1'){
        level.load(1);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(2, 200.0, ofGetHeight()-100);
        makeShape(2, 400.0, ofGetHeight()-100);
        makeShape(2, 600.0, ofGetHeight()-100);
        makeShape(2, 800.0, ofGetHeight()-100);
        makeShape(0, 200.0, ofGetHeight()-220);
        makeShape(1, 400.0, ofGetHeight()-240);
        makeShape(0, 800.0, ofGetHeight()-220);
        makeShape(1, 600.0, ofGetHeight()-240);
    } else if (key == '2'){
        level.load(2);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(2, 100.0, ofGetHeight()-100);
        makeShape(2, 200.0, ofGetHeight()-100);
        makeShape(2, 300.0, ofGetHeight()-100);
        makeShape(2, 400.0, ofGetHeight()-100);
        makeShape(2, 500.0, ofGetHeight()-100);
        makeShape(2, 600.0, ofGetHeight()-100);
        makeShape(2, 700.0, ofGetHeight()-100);
        makeShape(2, 800.0, ofGetHeight()-100);
        makeShape(0, 200.0, ofGetHeight()-220);
        makeShape(1, 400.0, ofGetHeight()-240);
        makeShape(0, 800.0, ofGetHeight()-220);
        makeShape(1, 600.0, ofGetHeight()-240);
        makeShape(0, 100.0, ofGetHeight()-220);
        makeShape(0, 300.0, ofGetHeight()-240);
        makeShape(1, 500.0, ofGetHeight()-220);
        makeShape(1, 700.0, ofGetHeight()-240);
    } else if (key == '3'){
        level.load(3);
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
    center.set(x,y);
    level.flocker.x = center.x;
    level.flocker.y = center.y;
    
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
