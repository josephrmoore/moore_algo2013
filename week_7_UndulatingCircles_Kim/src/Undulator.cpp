//
//  Undulator.cpp
//  UndulatingCircles_Kim
//
//  Created by Joseph Moore on 10/15/13.
//
//

#include "Undulator.h"

Undulator::Undulator(){
    freq = 2.5;
    amp = 500;
    line = 2.0;
    color = ofColor(255);
}

void Undulator::draw(){
    for (int i = 0; i < 20; i++){
        float sinOfTime = sin( ofGetElapsedTimef()/freq );
        float sinMapped = ofMap( sinOfTime, -1, 1, 1, amp );
        ofSetColor(color);
        ofSetLineWidth(i+line);
        ofNoFill();
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, sinMapped+(i*20));
    }
}

void Undulator::setFreq(float f){
    freq = f;
}

void Undulator::setAmp(float a){
    amp = a;
}

void Undulator::setLineWidth(float l){
    line = l;
}

void Undulator::setColor(ofColor c){
    color = c;
}