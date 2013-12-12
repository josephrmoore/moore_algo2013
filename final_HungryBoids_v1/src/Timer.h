//
//  Timer.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 12/11/13.
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
    void metronome();
    float bpm;
};
