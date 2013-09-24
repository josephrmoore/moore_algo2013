//
//  Dot.h
//  SinSquared
//
//  Created by Joseph Moore on 9/15/13.
//
//

#pragma once

#include "ofMain.h"

class Dot {
    
public:
    Dot();
    void update();
    void draw();
    float s(float mult, float period, bool norm);
    ofPoint pos, vel, acc, radius;
    ofColor color;
    float rotation, opacity;
};
