//
//  Rhythm.h
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#pragma once

#include "ofMain.h"
#include "Timer.h"
#include "Note.h"

class Rhythm {
    
public:
    Rhythm();
    void quantize(int note);
    void record();
    void play();
    void update();
    void setTempo(float _tempo);
    vector<Note> notes;
    Timer t;
    float tempo;
};
