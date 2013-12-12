//
//  Timer.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 12/11/13.
//
//
#include "Timer.h"

Timer::Timer(){
    start = ofGetElapsedTimeMillis();
    current = start;
    limit = 2000; // default 2 second, or 120bpm
    bpm = 120;
    activate = false;
}
void Timer::setLimit(float _limit){
    limit = _limit;
    bpm = (1/limit)*240000;
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

void Timer::metronome(){
    float pct = (current-start)/limit;
    int beat = 1;
    if(pct<=0.25){
        beat = 1;
    } else if (pct<=0.50&&pct>0.25){
        beat = 2;
    } else if (pct<=0.75&&pct>0.50){
        beat = 3;
    } else if (pct<=1.00&&pct>0.75){
        beat = 4;
    }
    for(int i=0; i<4; i++){
        int mult = 1;
        if(beat == i+1){
            mult = 2;
        }
        ofCircle(ofGetWidth()/2-60+(i*40), 40, 10*mult);
        ofPushStyle();
        ofSetColor(0);
        ofDrawBitmapString(ofToString(bpm)+" bpm", ofGetWidth()/2-20, 80);
        ofPopStyle();
    }
}