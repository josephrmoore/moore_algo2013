//
//  Copter.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "Bait.h"

class Copter : public ofxBox2dRect {
public:
    Copter();
    void update();
    void draw();
    void drop();
    void think();
    float speed, stability, damage;
    int  baits;
    ofVec2f pos, vel, acc;
    Bait bait;
    ofImage skin;
};