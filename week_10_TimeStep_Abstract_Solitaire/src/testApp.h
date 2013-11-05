#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "Card.h"

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
    ofxSVG svg;
    void newDeck();
    vector<Card> cards;
    int current_card;
    bool timer;
    float interval, current_time;
    double  lastTime;
    float   timeScale;
};
