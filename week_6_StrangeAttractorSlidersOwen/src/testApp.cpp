#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync( true );
    ofBackground( 0 );
    ofSetRectMode( OF_RECTMODE_CENTER );
    ofEnableAlphaBlending();
    a0 = -0.966918,			// coefficients for "The King's Dream"
	b0 = 2.879879,
	c0 = 0.765145,
	d0 = 0.744728;
    a=a0;
    b=b0;
    c=c0;
    d=d0;
    px = 0.1;
    py = 0.1;
    gui = new ofxUICanvas(200,300);
    gui->addLabel("Strange Attractor");
    gui->addSpacer();
    gui->addSlider("a", -1, 3, a0);
    gui->addSlider("b", -1, 3, b0);
    gui->addSlider("c", -1, 3, c0);
    gui->addSlider("d", -1, 3, d0);
    
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent); // what we're listening for,
    // who's listening for it,
    // and the function to run when it happens
    gui->loadSettings("test_settings.xml");
    
    for (int i = 0; i < 50000; i++) {
        ofPoint tmp;
        tmp.x = (sin(py*b) + c*sin(px*b));
		tmp.y = (sin(px*a) + d*sin(py*a));
        
        px = tmp.x;
        py = tmp.y;
        
        tmp.x *= 200;
        tmp.y *= 200;
        
        a += ofRandom(-0.01, 0.01);
        b += ofRandom(-0.01, 0.01);
        c += ofRandom(-0.01, 0.01);
        d += ofRandom(-0.01, 0.01);
        
        
        points.push_back( tmp );
        Particle p;
        p.pos.x = tmp.x;
        p.pos.y = tmp.y;
        particles.push_back(p);
    }
    
}

//--------------------------------------------------------------
void testApp::exit(){
    gui->saveSettings("test_settings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if(e.getName() == "a"){
        ofxUISlider *aSlider = (ofxUISlider*)e.widget;
        a0 = aSlider->getScaledValue();
    }
    if(e.getName() == "b"){
        ofxUISlider *bSlider = (ofxUISlider*)e.widget;
        b0 = bSlider->getScaledValue();
    }
    if(e.getName() == "c"){
        ofxUISlider *cSlider = (ofxUISlider*)e.widget;
        c0 = cSlider->getScaledValue();
    }
    if(e.getName() == "d"){
        ofxUISlider *dSlider = (ofxUISlider*)e.widget;
        d0 = dSlider->getScaledValue();
    }
    
    px = 0.1;
    py = 0.1;
    
    a = a0;
    b = b0;
    c = c0;
    d = d0;
    
    for (int i = 0; i < points.size(); i++) {
        points[i].x = (sin(py*b) + c*sin(px*b));
        points[i].y = (sin(px*a) + d*sin(py*a));
        
        px = points[i].x;
        py = points[i].y;
        
        points[i].x *= 200;
        points[i].y *= 200;
        
        a += ofRandom(-0.01, 0.01);
        b += ofRandom(-0.01, 0.01);
        c += ofRandom(-0.01, 0.01);
        d += ofRandom(-0.01, 0.01);
        particles[i].pos.x = points[i].x;
        particles[i].pos.y = points[i].y;
    }
}

//--------------------------------------------------------------
void testApp::update(){
//    for(int i=0; i<particles.size();i++){
//        cout<<points[i].x<<endl;
//        particles[i].addAttractionForce(points[i].x, points[i].y, 1000, 5);
//        particles[i].update();
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofNoFill();
    ofSetColor(255, 5);
    
    
    ofPushMatrix();{
        ofBeginShape();
        ofTranslate(ofGetWindowSize() / 2);
        
        for (vector<ofPoint>::iterator it = points.begin(); it != points.end(); it++) {
//            ofVertex(it->x, it->y);
        }
        ofEndShape();
        for(int i=0; i<particles.size();i++){
            particles[i].draw();
        }
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
