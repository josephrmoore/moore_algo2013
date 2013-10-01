#pragma once

#include "ofMain.h"
#include "Particle.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void addParticle();
    
    vector<Particle>    particleList;
    
    ofPoint             lastMousePos;
    float s(float mult, float period, bool norm);
    float c(float mult, float period, bool norm);
    float xeno(float target, float speed, float current);
    ofPoint xeno(ofPoint p, float catchX, float catchY, float cX, float cY);
};
