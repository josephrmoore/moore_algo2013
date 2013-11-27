//
//  Bait.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Bait : public ofxBox2dCircle {
public:
    float timer, lifetime;
    bool eaten;
    ofVec2f pos;
    void drop(ofVec2f pos);
    void setup2();
    void update();
};