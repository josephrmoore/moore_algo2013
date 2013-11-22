//
//  Boid.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Boid.h"

Boid::Boid( ofVec2f position, ofVec2f velocity) {
    pos = position;
    vel = velocity;
    damping = 0.98;
    setDamping(damping);
}

void Boid::applyForce( ofVec2f force ){
    acc += force;
}

void Boid::pullToCenter( ofVec2f center ){
    
    // if the particles stray too far, we want to pull them back on screen
    
    ofVec2f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 100.0;
    
    if( dir.length() > maxDistance ) {
        dir.normalize();
        vel -= dir * ( ( dist - maxDistance ) * 0.0001f );
    }
}

void Boid::update(){

//    vel += getVelocity();
//    vel += getPosition();
    vel += acc;
    
    // don't move too fast
    vel.limit(10.0);
    
    // but also don't move too slow!
    if( vel.lengthSquared() < 1.0 ){
        vel = vel.normalized() * 1.0;
    }
    
    pos += vel;
    
    acc.set(0);
    setVelocity(vel);
    setPosition(pos);
}

//void Boid::draw(){
//    ofPushStyle();
//        ofSetColor(255);
//        ofCircle(pos, 4);
//    ofPopStyle();
//}