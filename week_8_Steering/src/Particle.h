//
//  Particle.h
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#pragma once

#include "ofMain.h"

class Particle {
public:
    Particle();
    
    void update();
    void draw();
    
    void setParams( float px, float py, float vx, float vy );
    void addForce( ofVec2f force );
    void addRepulsionForce(const ofVec2f &dest);
    void addDampingForce();
    void resetForces();
    
    ofVec2f pos;
    ofVec2f vel;
    ofVec2f frc;
    
    ofVec2f damping;  // could also be a ofVec2f
    ofVideoPlayer img;
    ofColor color;
    
    void seek(ofVec2f dest, vector<Particle> ps);
    void avoid(vector<Particle> ps);
    float maxSpeed, maxForce, slowdown;
};