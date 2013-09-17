//
//  Dot.cpp
//  SinSquared
//
//  Created by Joseph Moore on 9/15/13.
//
//

#include "Dot.h"

Dot::Dot(){
    pos.x = 0.0;
    pos.y = 0.0;
    
    vel.x = 0.0;
    vel.y = 0.0;
    
    acc.x = 0.0;
    acc.y = 0.0;

    radius.x = 50.0;
    radius.y = 50.0;
    
    rotation = 0.0;
    
    opacity = 255.0;
    
    color = ofColor(255.0,255.0,255.0,opacity);
    
}

void Dot::update(){
    
}

void Dot::draw(){
    ofPushMatrix();{
        ofTranslate(pos);
        ofRotate(rotation);
        ofTranslate(-pos);
        ofSetColor(color);
        ofFill();
        ofEllipse(pos, radius.x, radius.y);
    };ofPopMatrix();
}