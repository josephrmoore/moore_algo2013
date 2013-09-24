//
//  rectangle.h
//  rectangleTest
//
//  Created by Joseph Moore on 8/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once
#include "ofMain.h"

class Rectangle{
    public:
    Rectangle();
    
    void update();
    void draw();
    void interpolateByPercent(float percent);
    void xenoToPoint(float catchX, float catchY, float speedX, float speedY);
    ofPoint pos;
    float percent;
    ofPoint posA;
    ofPoint posB;
    ofPoint radius;
    ofColor color;
};