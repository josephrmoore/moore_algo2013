//
//  Firework.h
//  Fireworks
//
//  Created by Joseph Moore on 9/20/13.
//
//

#pragma once

#include "ofMain.h"
#include "Particle.h"

class Firework {
public:
    Firework(){};
    void setup(ofSoundPlayer s1, ofSoundPlayer s2);
    void update();
    void draw(float x, float y);
    
    ofVec2f pos;
    ofVec2f vel;
    float detonate_y, size, speed, timer, curve;
    int number;
    ofColor color;
    bool shrieks, has_trails, detonated, over;
    vector <ofPoint> trails;
    vector <Particle> pList;
    void explode(ofVec2f p);
    ofSoundPlayer reax, explosion;
};
