//
//  Timer.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//


#pragma once

#include "ofMain.h"

class Timer {
    
public:
    Timer();
    double start, current;
    float limit;
    void reset();
    void setLimit(float _limit);
    void update();
    bool activate;
};
