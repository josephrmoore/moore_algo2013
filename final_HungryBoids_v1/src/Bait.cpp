//
//  Bait.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Bait.h"

void Bait::setup2(){
    lifetime = 10000;
    eaten = false;
}

void Bait::drop(ofVec2f _pos){
    setPosition(_pos);
    pos = _pos;
    timer = ofGetElapsedTimeMillis();
    eaten = false;
}

void Bait::update(){
    pos = getPosition();
    if(ofGetElapsedTimeMillis()-timer>lifetime){
        eaten = true;
    }
    if(eaten){
        pos = ofVec2f(-ofGetWidth(), -ofGetHeight());
    }
}
