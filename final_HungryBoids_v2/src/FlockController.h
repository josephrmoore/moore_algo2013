//
//  FlockController.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "Boid.h"

class FlockController {
public:
    FlockController();
    
    void applyForces( float zoneRadius, float separateThresh=0.4, float alignThresh=0.7 );
    
    void addParticle(b2World* _box, int numParticles=1 );
    void update();
    void draw();
    
    vector<Boid>    boidList;
    float x, y;
    ofPoint flockPos();
    ofPoint center;
    void reset();
};
