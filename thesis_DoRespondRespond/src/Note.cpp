//
//  Note.cpp
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#include "Note.h"

Note::Note(){
    time = ofGetElapsedTimeMillis();
    played = false;
    pitch = 1;
    duration = 0.25;
}

void Note::getPerc(Timer _t){
    
}

void Note::setParams(int _pitch){
    pitch = _pitch;
}

void Note::setParams(float _dur){
    duration = _dur;
}

void Note::setParams(int _pitch, float _dur){
    pitch = _pitch;
    duration = _dur;
}

void Note::play(){
    cout<<pitch<<" "<<time<<endl;
}