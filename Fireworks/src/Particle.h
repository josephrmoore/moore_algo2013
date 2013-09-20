//
//  Particle.h
//  Fireworks
//
//  Created by Joseph Moore on 9/19/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle(){};
    void setup();
    void update();
    void draw();
    
    ofVec2f pos;
    ofVec2f vel;
    int age, lifespan;
    bool bIsDead;
    ofColor color;
    float radius, agePct;
    bool shriek, trails;
};
