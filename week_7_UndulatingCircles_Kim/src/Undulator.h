//
//  Undulator.h
//  UndulatingCircles_Kim
//
//  Created by Joseph Moore on 10/15/13.
//
//

#pragma once

#include "ofMain.h"

class Undulator {
public:
    Undulator();
    float freq, amp, line, w, h;
    ofColor color;
    void draw();
    void setFreq(float freq);
    void setAmp(float amp);
    void setLineWidth(float line);
    void setColor(ofColor color);
};