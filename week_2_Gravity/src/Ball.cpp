//
//  ball.cpp
//  Gravity
//
//  Created by Joseph Moore on 9/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "Ball.h"

Ball::Ball(float x, float y){
    pos.x = x;
    pos.y = y;
    
    vel.x = ofRandom(-5.0, 5.0);
    vel.y = ofRandom(-5.0, 5.0);
}

void Ball::update(float g) {
    pos += vel;
    vel.y += g;
    if(pos.y >= (ofGetScreenHeight()-150)){
        vel.y *= -1.0;
    }
    vel *= 0.97;
}

void Ball::draw() {
    ofCircle( pos, 10 );
}

void Ball::toggleCollide(){
    collide = !collide;
}