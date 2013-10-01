#pragma once

#include "ofMain.h"
#include "ofxUI.h"
#include "Particle.h"

class testApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    ofImage saved_img;
    void onGuiEvent(ofxUIEventArgs &e);
    ofxUICanvas *gui;
    float s(float mult, float period, bool norm);
    float c(float mult, float period, bool norm);
    float xeno(float target, float speed, float current);
    ofPoint xeno(ofPoint p, float catchX, float catchY, float cX, float cY);
    void addParticle();
    vector<Particle>    particles;
    float radius, opacity, hue, sat, bright, curr_img;
    ofColor color;
    bool bleed;
};
