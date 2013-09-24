#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ico.loadImage("ico.png");
    yorda.loadImage("yorda.png");
    floor.loadImage("floor.jpg");
}

//--------------------------------------------------------------
void testApp::update(){
    ico_pos = ofPoint(mouseX, mouseY);
    yorda_pos = xenoToPoint(ico_pos.x+110, ico_pos.y+80, 0.05, 0.05, yorda_pos);
}

//--------------------------------------------------------------
void testApp::draw(){
    floor.draw(0,0);
    ico.draw(ico_pos.x,ico_pos.y);
    
    ofPushMatrix();{
        ofTranslate( yorda_pos );
        float dx = mouseX - yorda_pos.x;
        float dy = mouseY - yorda_pos.y;
        float angle = atan2( dy , dx );
        ofRotate( ofRadToDeg(angle) );
        ofTranslate( -yorda_pos );
        ofPushMatrix();{
            ofTranslate(-38, -55);
            yorda.draw(yorda_pos.x,yorda_pos.y);
            ofTranslate(38, 55);
        }ofPopMatrix();

    }ofPopMatrix();
    
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

ofPoint testApp::xenoToPoint(float catchX, float catchY, float catchUpSpeedX, float catchUpSpeedY, ofPoint p){
    float cX = catchUpSpeedX;
    float cY = catchUpSpeedY;
    p.x = (cX*catchX) + ((1-cX)*p.x);
    p.y = (cY*catchY) + ((1-cY)*p.y);
    return p;
}