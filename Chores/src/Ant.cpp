//
//  Ant.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Ant.h"

Ant::Ant(){
    pos.x = ofGetScreenWidth()/2;
    pos.y = ofGetScreenHeight()/2;
    
    vel.x = 0.0;
    vel.y = 0.0;
    
    color = ofColor(242, 225, 33);
    radius = 10.0;
}