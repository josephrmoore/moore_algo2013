//
//  Pro.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Pro.h"

Pro::Pro(){
    pos.x = ofGetScreenWidth()/2;
    pos.y = ofGetScreenHeight()/2;
    
    vel.x = ofRandom(-5.0, 5.0);
    vel.y = ofRandom(-5.0, 5.0);
    
    color = ofColor(180,44,44);
    radius = 100.0;
}