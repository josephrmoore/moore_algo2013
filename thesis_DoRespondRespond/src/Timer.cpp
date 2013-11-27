//
//  Timer.cpp
//  DoRespondRespond
//
//  Created by Joseph Moore on 11/27/13.
//
//

#include "Timer.h"

Timer::Timer(){
    start = ofGetElapsedTimeMillis();
    current = start;
    limit = 1000; // default 1 second
    activate = false;
}
void Timer::setLimit(float _limit){
    limit = _limit;
}
void Timer::reset(){
    start = ofGetElapsedTimeMillis();
    activate = false;
}
void Timer::update(){
    current = ofGetElapsedTimeMillis();
    if(current-start > limit){
        activate = true;
    }
}