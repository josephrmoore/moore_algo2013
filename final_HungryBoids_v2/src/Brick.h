//
//  Brick.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//
#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Brick : public ofxBox2dRect {
public:
    Brick();
    void draw();
};