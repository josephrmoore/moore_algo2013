//
//  Loop.cpp
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#include "Loop.h"

Loop::Loop(){
    t.setLimit(2000); // start at 120 BPM
    tempo = (3*t.limit)/2000;
}

void Loop::setTempo(float _tempo){
    tempo = _tempo;
    t.setLimit(tempo*2000/3);
}

void Loop::record(){
    Note n;
    notes.push_back(n);
}

void Loop::play(){
    for( vector<Note>::iterator it=notes.begin(); it!=notes.end(); it++ ){
        if(t.current-t.start >= it->time-t.start && it->played==false){
            it->play();
            it->played = true;
        }
    }
}
void Loop::update(){
    t.update();
    if(t.activate == true){
        // action to perform on timer rollover
        
        t.reset();
    }
}
void Loop::quantize(int _note){
    
}