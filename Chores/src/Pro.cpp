//
//  Pro.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Pro.h"

Pro::Pro(){
    pos.x = -radius.x-30;
    pos.y = ofGetHeight()-50;
    
    color = ofColor(180,44,44);
    radius.x = 100.0;
    radius.y = 100.0;
    
    vel.x = 0.0;
    vel.y = 0.0;
    
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
    
    type = "pro";
}


void Pro::draw(ofPoint r, ofPoint p){
    // Protagonist
    
    ofPushMatrix();
    {
        cout<<p.x/2<<r.x<<endl;
        ofTranslate(pos.x/2, pos.y/2);
        ofRotate(rotation,0,0,1);
        ofTranslate(-pos.x/2, -pos.y/2);
        ofSetColor(color);
        ofEllipse(p, r.x, r.y);
    };
    ofPopMatrix();
}