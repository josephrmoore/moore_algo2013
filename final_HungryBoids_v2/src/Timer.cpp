//
//  Timer.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//
#include "Timer.h"

Timer::Timer(){
    start = ofGetElapsedTimeMillis();
    current = start;
    limit = 2000; // default 2 second, or 120bpm
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