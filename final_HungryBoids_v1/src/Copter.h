//
//  Copter.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "Bait.h"

class Copter {
public:
    Copter();
    void update();
    void draw();
    float base_speed, current_speed, stability, damage;
    int  baits;
};