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
    typedef ofxBox2dCircle super;
    Boid( ofVec2f position, ofVec2f velocity );
    
    void applyForce( ofVec2f force );
    void pullToCenter( ofVec2f center );
    
    void update();
//    void draw();
    
    float   damping;
    ofVec2f pos, vel, acc;
};