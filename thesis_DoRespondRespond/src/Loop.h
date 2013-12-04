//
//  Loop.h
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#pragma once

#include "ofMain.h"
#include "Timer.h"
#include "Note.h"

class Loop {
    
public:
    Loop();
    float length, tempo;
    int bar_length, bar_number;
    void quantize(int note);
    void record();
    void play();
    void update();
    void setTempo(float _tempo);
    vector<Note> notes;
    Timer t;
    bool repeat;
};
