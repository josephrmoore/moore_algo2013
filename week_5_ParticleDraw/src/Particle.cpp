//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( 0.01f );
    color = ofColor(ofRandom(255), ofRandom(255));
}

void Particle::setParams( float px, float py, float vx, float vy ){
    pos.set( px, py );
    vel.set( vx, vy );
}

void Particle::addForce( ofVec2f force ){
    frc += force;
}

void Particle::addDampingForce() {
    frc = frc - vel * damping;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::update() {
    vel = vel + frc;
    pos = pos + vel;
    if(pos.x<0||pos.x>ofGetWidth()){
        vel.x *=-1;
    }
    if(pos.y<0||pos.y>ofGetHeight()){
        vel.y *=-1;
    }
}

void Particle::draw(float radius, ofColor c) {
    ofSetColor(color);
    ofCircle(pos,radius);
}