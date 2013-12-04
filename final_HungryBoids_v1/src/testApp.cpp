#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    box.init();
	box.setGravity(0, 5);
	box.setFPS(30.0);
    box.createGround();
    box.enableGrabbing();
    box.registerGrabbing();
    level.setup(box.getWorld());
    center.set(ofGetWidth()/2,ofGetHeight()/2);
    level.flocker.x = center.x;
    level.flocker.y = center.y;
    level.copter.bait.setup2();
    level.copter.bait.setPhysics(9.0, 0.01, 0.001);
    level.copter.bait.setup(box.getWorld(), 0, 0, 10);
}

//--------------------------------------------------------------
void testApp::update(){
    box.update();
    level.update();
    level.copter.bait.update();
    level.flocker.x = level.copter.bait.pos.x;
    level.flocker.y = level.copter.bait.pos.y;
    b2World* b = box.getWorld();
//    b->Step(0.0001, 0.0001, 0.0001);
}

//--------------------------------------------------------------
void testApp::draw(){
//    cam.begin();
    level.draw();
    for(int i=0; i<boxes.size(); i++){
        boxes[i].draw();
    }
//    cam.end();
    if(!level.copter.bait.eaten){
        level.copter.bait.draw();
    }
}

void testApp::makeShape(float x, float y, float w, float h){
    Brick r;
    r.setPhysics(3.0, 0.03, 1.0);
    r.setup(box.getWorld(), x, y, w, h);
    boxes.push_back(r);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(level.level == 0){
        if(key == ' '){
            level.load(1);
            for(int i=0; i<boxes.size(); i++){
                boxes[i].destroy();
            }
            boxes.clear();
            makeShape(200.0, ofGetHeight()-100);
            makeShape(400.0, ofGetHeight()-100);
            makeShape(600.0, ofGetHeight()-100);
            makeShape(800.0, ofGetHeight()-100);
            makeShape(200.0, ofGetHeight()-220);
            makeShape(400.0, ofGetHeight()-240);
            makeShape(800.0, ofGetHeight()-220);
            makeShape(600.0, ofGetHeight()-240);
        }
    }
    
    if(key == '1'){
        level.load(1);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(200.0, ofGetHeight()-100);
        makeShape(400.0, ofGetHeight()-100);
        makeShape(600.0, ofGetHeight()-100);
        makeShape(800.0, ofGetHeight()-100);
        makeShape(200.0, ofGetHeight()-220);
        makeShape(400.0, ofGetHeight()-240);
        makeShape(800.0, ofGetHeight()-220);
        makeShape(600.0, ofGetHeight()-240);
    } else if (key == '2'){
        level.load(2);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(100.0, ofGetHeight()-100);
        makeShape(200.0, ofGetHeight()-100);
        makeShape(300.0, ofGetHeight()-100);
        makeShape(400.0, ofGetHeight()-100);
        makeShape(500.0, ofGetHeight()-100);
        makeShape(600.0, ofGetHeight()-100);
        makeShape(700.0, ofGetHeight()-100);
        makeShape(800.0, ofGetHeight()-100);
        makeShape(200.0, ofGetHeight()-220);
        makeShape(400.0, ofGetHeight()-240);
        makeShape(800.0, ofGetHeight()-220);
        makeShape(600.0, ofGetHeight()-240);
        makeShape(100.0, ofGetHeight()-220);
        makeShape(300.0, ofGetHeight()-240);
        makeShape(500.0, ofGetHeight()-220);
        makeShape(700.0, ofGetHeight()-240);
    } else if (key == '3'){
        level.load(3);
        for(int i=0; i<boxes.size(); i++){
            boxes[i].destroy();
        }
        boxes.clear();
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
        makeShape(ofRandom(100,ofGetWidth()-100), ofRandom(ofGetHeight()-200,ofGetHeight()-20));
    } else {
        level.copter.drop();
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
