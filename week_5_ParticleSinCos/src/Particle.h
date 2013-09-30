//
//  Particle.h
//  ParticleControl
//
//  Created by Joseph Moore on 9/28/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void update(ofVec2f pos);
    void draw(float size);
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f force );
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    ofColor color;
    ofVec2f damping;  // could also be a ofVec2f
};