//
//  Brick.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Brick : public ofxBox2dRect {
public:
    Brick();
    void draw();
    ofImage img;
};