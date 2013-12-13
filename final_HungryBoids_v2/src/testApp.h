#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "FlockController.h"
#include "Timer.h"
#include "Copter.h"

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
    
    ofxBox2d box;
    
    int state_screen; // 0=title,1=lose,2=win,3=level,4=ending
    int state_win; // resets to false at each level load
    int levels_total; // needs to know when to go to the ending
    int levels_current; // 0 = not a level, 1->n = level 1->level n
    
    FlockController title_flocker; // flock for title screen
    FlockController flocker; // flock for game
    
    ofSoundPlayer noise, all, trill;
    ofImage title_start, title_hungry, title_boids, title_bk;
    
    void title();
    void win();
    void lose();
    void ending();
    void level(int level);
    
    Timer title_word1, title_word2, title_back, level_bars;
    ofColor word1, word2, back;

    Bait title_bait;
    Copter copter;
    
    float center_perc;

    vector<vector<ofVec2f> > towers;
};
