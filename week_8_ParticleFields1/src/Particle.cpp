//
//  Particle.cpp
//  ParticleFields1
//
//  Created by Joseph Moore on 10/21/13.
//
//

#include "Particle.h"

Particle::Particle() {
    mass = 1.0;
}

void Particle::applyForce(ofVec2f force){
    accel += (force / mass);
}

void Particle::update(){
    vel += accel;
    pos += vel;
    
    vel*= 0.97;
    
    accel.set(0);
//    if(pos.x>ofGetWidth() || pos.x <0){
//        vel.x *= -1;
//    }
//    if(pos.y>ofGetHeight() || pos.y<0){
//        vel.y *= -1;
//    }
}

void Particle::draw() {
    ofCircle( pos, 4 );
}