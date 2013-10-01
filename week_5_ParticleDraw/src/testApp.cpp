#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    gui = new ofxUICanvas(200, 400);
    gui->addLabel("My Controls");
    gui->addSpacer();
    gui->addSlider("radius", 0, 20, 5);
    gui->addSlider("opacity", 0, 255, 255);
    gui->addWidgetDown(new ofxUIRotarySlider(16*4, 0, 255, 255, "hue"));
    gui->addWidgetDown(new ofxUIRotarySlider(16*5, 0, 255, 255, "sat"));
    gui->addWidgetDown(new ofxUIRotarySlider(16*6, 0, 255, 255, "bright"));
    ofAddListener(gui->newGUIEvent, this, &testApp::onGuiEvent);
    gui->loadSettings("test_settings.xml");
    ofBackground(255,0);
    glEnable(GL_DEPTH_TEST);
    radius = 5.0;
    opacity = 255.0;
    color = ofColor(255,0,0, opacity);
    curr_img = 0;
    bleed = false;
}

//--------------------------------------------------------------
void testApp::exit(){
    gui->saveSettings("test_settings.xml");
    delete gui;
}

//--------------------------------------------------------------
void testApp::onGuiEvent(ofxUIEventArgs &e){
    if(e.getName() == "radius"){
        ofxUISlider *radiusSlider = (ofxUISlider*)e.widget;
        radius = radiusSlider->getScaledValue();
    } else if(e.getName() == "opacity"){
        ofxUISlider *opacitySlider = (ofxUISlider*)e.widget;
        opacity = opacitySlider->getScaledValue();
        color = ofColor(color, opacity);
    } else if(e.getName() == "hue"){
        ofxUIRotarySlider *hueSlider = (ofxUIRotarySlider*)e.widget;
        hue = hueSlider->getScaledValue();
        cout<<hue<<endl;
        color.setHue(hue);
    } else if(e.getName() == "sat"){
        ofxUIRotarySlider *satSlider = (ofxUIRotarySlider*)e.widget;
        sat = satSlider->getScaledValue();
        color.setSaturation(sat);
        cout<<sat<<endl;
    } else if(e.getName() == "bright"){
        ofxUIRotarySlider *brightSlider = (ofxUIRotarySlider*)e.widget;
        bright = brightSlider->getScaledValue();
        color.setBrightness(bright);
        cout<<bright<<endl;
    }
}

//--------------------------------------------------------------
void testApp::update(){
	for (int i=0; i < particles.size(); i++){
		particles[i].resetForces();
//		particles[i].addDampingForce();
        float thisnum = ofRandom(particles.size());
        if(particles[i].pos.x != particles[thisnum].pos.x || particles[i].pos.y != particles[thisnum].pos.y ){
        particles[i].addForce(
                              xeno(
                                   particles[i].frc,
                                   particles[thisnum].frc.x,
                                   particles[thisnum].frc.y,
                                   0.1, 0.1));
        } else {
            particles[i].vel.x = s(5.0,200.0,false);
            particles[i].vel.y = c(5.0,200.0,false);
        }
		particles[i].update();
        particles[i].color = color;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(0,100);
    saved_img.draw(200,0,-1,ofGetWidth()-200, ofGetHeight());
    for (int i=0; i < particles.size(); i++){
        particles[i].draw(radius, color);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'a'){
        ofSetBackgroundAuto(false);
    }
    if(key == 'z'){
        Particle myParticle;
        myParticle.setParams(mouseX, mouseY, s(10.0, 200.0, false),c(10.0, 200.0, false));
        particles.push_back(myParticle);
    }
    if(key == 'q'){
        bleed = true;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    if(key == 'a'){
        saved_img.grabScreen(200,0,ofGetWidth()-200, ofGetHeight());
        saved_img.saveImage("grab"+ofToString(curr_img)+".png");
        curr_img++;
        ofSetBackgroundAuto(true);
    }
    if(key == 'q'){
        bleed = false;
    }
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    if(bleed){
        Particle myParticle;
        myParticle.setParams(x, y, s(10.0, 200.0, false),c(10.0, 200.0, false));
        particles.push_back(myParticle);
    }
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

float testApp::xeno(float target, float speed, float current){
    return (speed*target) + ((1-speed)*current);
}

ofPoint testApp::xeno(ofPoint p, float catchX, float catchY, float cX, float cY){
    p.x = (cX*catchX) + ((1-cX)*p.x);
    p.y = (cY*catchY) + ((1-cY)*p.y);
    return p;
}
