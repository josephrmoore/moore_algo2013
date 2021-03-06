#pragma once

#include "ofMain.h"
#include "Level.h"
#include "ofxBox2d.h"
#include "ofxUI.h"
#include "ofxXmlSettings.h"

#define B2D 0.5

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
    Level level;
    ofxBox2d box;
    vector<Brick> boxes;
    
    void makeShape(float x=ofGetWidth()/2, float y=ofGetHeight()/2, float w=100, float h=100);
    ofEasyCam cam;
    ofVec2f center;
    
    bool checkBricks();
    ofSoundPlayer noise, all, trill;
    float center_perc;
};
