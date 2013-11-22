//
//  Boid.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"

class Boid : public ofxBox2dCircle {
public:
    Boid( ofVec3f position, ofVec3f velocity );
    
    void applyForce( ofVec3f force );
    void pullToCenter( ofVec3f center );
    
    void update();
    void draw();
    
    float   damping;
    ofVec3f pos, vel, acc;
};