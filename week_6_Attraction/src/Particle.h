//
//  Particle.h
//  Attraction
//
//  Created by Joseph Moore on 10/6/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
    
public:
    Particle();
    void setup();
    void update();
    void draw();
    ofVec2f pos, vel, acc;
    void addForce(ofVec2f force);
    void addRepulsionForce(float px, float py, float radius, float strength);
    void addAttractionForce(float px, float py, float radius, float strength);

    float damping, radius;
    ofColor color;
};
