//
//  Note.h
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#pragma once

#include "ofMain.h"
#include "Timer.h"

class Note {
    
public:
    Note();
    void getPerc(Timer t);
    double time;
    int pitch;
    float duration;
    bool played;
    // need something for key
    void setParams(int _pitch);
    void setParams(float _dur);
    void setParams(int _pitch, float _dur);
    void play();
};
