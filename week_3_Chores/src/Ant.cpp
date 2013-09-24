//
//  Ant.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Ant.h"

Ant::Ant(){
    pos.x = -800.0;
    pos.y = 200.0;
    
    vel.x = 0.0;
    vel.y = 0.0;
    
//    color = ofColor(253, 241, 174);
//    color = ofColor(242, 225, 33);
    radius.x = 30.0;
    radius.y = 30.0;
    
    rotation = 0.0;
    gravity = 0.98;
    
    // pos
    moving = false;
    shaking = false;
    darting = false;
    rolling = false;
    jumping = false;
    swarming = false;
    looping = false;
    approaching = false;
    
    // radius
    breathing = false;
    shrinking = false;
    flattening = false;
    
    shake_dir = false;
    
    swarm_anchor = pos;
    shrink_timer = 0;
    
    type = "ant";
}

void Ant::update(){
    pos.x += vel.x;
    pos.y += vel.y;
    color = ofColor(ofMap(sin(ofGetElapsedTimeMillis()/200), -1.0, 1.0, 100.0, 255.0), ofMap(sin(ofGetElapsedTimeMillis()/100.0), -1.0, 1.0, 100.0, 240.0), ofMap(sin(ofGetElapsedTimeMillis()/300), -1.0, 1.0, 100.0, 175.0));
    //    color = ofColor(242, 225, 33);
}