//
//  Bait.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Bait.h"

void Bait::setup2(){
    lifetime = 1;
    eaten = true;
}

void Bait::drop(ofVec2f _pos){
    if(eaten){
        setPosition(_pos);
        pos = _pos;
        timer = ofGetElapsedTimeMillis();
        eaten = false;
    }
}

void Bait::update(){
    pos = getPosition();
    
    if(ofGetElapsedTimeMillis()-timer>lifetime){
        eaten = true;
    } else {
        eaten = false;
    }
    
    if(eaten){
        pos = ofVec2f(-ofGetWidth(), -ofGetHeight());
    } else {
        setRadius(10-((ofGetElapsedTimeMillis()-timer)/lifetime*10.0));
    }
}
