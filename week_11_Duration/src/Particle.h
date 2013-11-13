//
//  Particle.h
//  Duration
//
//  Created by Joseph Moore on 11/12/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
    
public:
    Particle();
    void update();
    void draw();
    ofVec3f pos, vel, acc;
    ofVec2f radius;
    ofColor color;
    void applyForce(ofVec3f force);
};
