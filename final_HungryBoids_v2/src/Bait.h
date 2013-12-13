//
//  Bait.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//


#include "ofMain.h"
#include "ofxBox2d.h"

class Bait : public ofxBox2dCircle {
public:
    Bait();
    float timer, lifetime, radius;
    bool eaten;
    ofVec2f pos;
    void drop(ofVec2f pos);
    void update();
    void draw();
    ofImage img;
    bool dropped;
};