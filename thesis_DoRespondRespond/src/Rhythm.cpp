//
//  Rhythm.cpp
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#include "Rhythm.h"

Rhythm::Rhythm(){
    t.setLimit(2000); // start at 120 BPM
    tempo = (3*t.limit)/2000;
}

void Rhythm::setTempo(float _tempo){
    tempo = _tempo;
    t.setLimit(tempo*2000/3);
}

void Rhythm::record(){
    double hit = ofGetElapsedTimeMillis();
    float note = hit-t.start;
    values.push_back(note);
}
void Rhythm::play(){
    
}
void Rhythm::update(){
    t.update();
    if(t.activate == true){
        // action to perform on timer rollover
        
        t.reset();
    }
}
void Rhythm::quantize(int _note){
    
}