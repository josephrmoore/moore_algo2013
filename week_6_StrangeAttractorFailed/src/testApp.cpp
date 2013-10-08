#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    a = 0.2;
    b = 0.2;
    c = 0.7;
    x = 0.001;
    y = 0.001;
    z = 0.001;
    
    ofBackground(255);
    ofSetBackgroundAuto(true);
}

//--------------------------------------------------------------
void testApp::update(){
    if(x<ofGetWidth() && y<ofGetHeight()){
        xd = -y - z;
        yd = x + a*y;
        zd = b + z*(x-c);
        
        x = xd;
        y = yd;
        z = zd;
        
        cout<<xd<<" "<<yd<<" "<<zd<<endl;
        pts.push_back(ofVec3f(x,y,z));
    }
    
}

//--------------------------------------------------------------
void testApp::draw(){
    mycam.begin();
    ofNoFill();
    ofSetColor(0);
    ofBeginShape();
    for(int i=0; i<pts.size(); i++){
        ofVertex(pts[i].x,pts[i].y,pts[i].z);
    }
    ofEndShape();
    ofFill();
    ofCircle(exp(x)+(ofGetWidth()/2),exp(y)+(ofGetHeight()/2),0.3);
    mycam.end();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    for(int i=-ofGetWidth(); i<ofGetWidth(); i+=0.01){
//        x = i;
//        
//    }
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
