#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(255);
    radius = 10.0;
    number = 1000.0;
    size = 5.0;
    gui = new ofxUICanvas(200,500);
    gui->addLabel("Particle Controller");
    gui->addSpacer();
    gui->addButton("Explode!", false, 40, 40);
    gui->addSlider("Speed", 0, 20, 10);
    gui->addSlider("Number", 0, 2000, 1000);
    gui->addSlider("Size", 0, 20, 5);
    gui->addSlider("Hue", 0, 255, 5);
    gui->addSlider("Saturation", 0, 255, 10);
    gui->addSlider("Brightness", 0, 255, 20);
    gui->addToggle("Gravity", false, 40, 20);

    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent); // what we're listening for,
    // who's listening for it,
    // and the function to run when it happens
    gui->loadSettings("test_settings.xml");
    ofBackground(255);
    settings = 0;
}

//--------------------------------------------------------------
void testApp::exit(){
    gui->saveSettings("test_settings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if(e.getName() == "Speed"){
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        radius = radiusSlider->getScaledValue();
        cout<<radius<<endl;
    } if(e.getName() == "Number"){
        ofxUISlider *numberSlider = (ofxUISlider*)e.widget;
        number = numberSlider->getScaledValue();
        cout<<radius<<endl;
    } if(e.getName() == "Size"){
        ofxUISlider *sizeSlider = (ofxUISlider*)e.widget;
        size = sizeSlider->getScaledValue();
        cout<<radius<<endl;
    }if(e.getName() == "Hue"){
        ofxUISlider *hueSlider = (ofxUISlider*)e.widget;
        hue = hueSlider->getScaledValue();
        cout<<radius<<endl;
    }if(e.getName() == "Saturation"){
        ofxUISlider *satSlider = (ofxUISlider*)e.widget;
        sat = satSlider->getScaledValue();
        cout<<radius<<endl;
    }if(e.getName() == "Brightness"){
        ofxUISlider *brightSlider = (ofxUISlider*)e.widget;
        bright = brightSlider->getScaledValue();
        cout<<radius<<endl;
    } if(e.getName() == "Gravity"){
        ofxUIToggle *colorToggle = (ofxUIToggle*)e.widget;
        if(colorToggle->getValue() == 1){
            gravity = true;
        } else {
            gravity = false;
        }
        cout<<radius<<endl;
    } if(e.getName() == "Explode!"){
        ofxUIButton *colorToggle = (ofxUIButton*)e.widget;
        if(colorToggle->getValue() == 1){
            particleList.clear();
            for (int i = 0; i < number; i++){
                addParticle(radius);
            }
            for (int i = 0; i < particleList.size(); i++){
                
                float circVal = ofRandom(TWO_PI);
                
                float vx = cos( circVal ) * ofRandom(0,radius);
                float vy = sin( circVal ) * ofRandom(0,radius);
                
                particleList[i].setParams(ofGetWidth()/2,ofGetHeight()/2,vx, vy);
                
            }
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
	// we reset the forces
	// add in any forces on the particle
	// perfom damping and
	// then update
	
	for (int i=0; i < particleList.size(); i++){
		particleList[i].resetForces();
        if(gravity){
            float factor = 0.05;
            particleList[i].addForce( ofVec2f(ofRandom(-factor, factor),ofRandom(-factor, factor)));  // gravity
            particleList[i].addForce( ofVec2f(0,0.04));  // gravity
        }
		particleList[i].addDampingForce();
		particleList[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    for (int i=0; i < particleList.size(); i++){
        ofColor c = particleList[i].color;
        c.setHue(hue);
        c.setSaturation(sat);
        c.setBrightness(bright);
        particleList[i].color = c;
        particleList[i].draw(size);
    }
}

void testApp::addParticle(float radius) {
    Particle myParticle;
    
    float vx = ofRandom(-radius,radius);
    float vy = ofRandom(-radius,radius);
    float factor = 1;
    float driftx = ofRandom(-factor,factor);
    float drifty = ofRandom(-factor,factor);

    myParticle.setParams(0+driftx,0+drifty,vx, vy);
    
    // more interesting with diversity :)
    // uncomment this:
    //		myParticle.damping = ofRandom(0.01, 0.05);
    particleList.push_back(myParticle);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

    if(key == '1'){
        gui->loadSettings("settings1.xml");
    }
    if(key == '2'){
        gui->loadSettings("settings2.xml");
    }
    if(key == '3'){
        gui->loadSettings("settings3.xml");
    }
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
