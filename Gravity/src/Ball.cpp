//
//  ball.cpp
//  Gravity
//
//  Created by Joseph Moore on 9/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Ball.h"

Ball::Ball(){
    pos.x = ofGetWindowWidth() / 2.0;
    pos.y = ofGetWindowHeight() / 2.0;
    
    vel.x = ofRandom(-5.0, 5.0);
    vel.y = ofRandom(-5.0, 5.0);
}

void Ball::update() {
    pos += vel;
    vel.x *= 0.97;
}

void Ball::draw() {
    ofCircle( pos, 10 );
}

void Ball::toggleCollide(){
    collide = !collide;
}