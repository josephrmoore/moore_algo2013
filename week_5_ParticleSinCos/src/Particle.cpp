//
//  Particle.cpp
//  ParticleControl
//
//  Created by Joseph Moore on 9/28/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( 0.01f );
    color = ofColor(ofRandom(0,180), ofRandom(100, 255));
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

void Particle::update(ofVec2f p) {
    vel = vel + frc +p;
    pos = pos + vel;
}

void Particle::draw(float size) {
    ofSetColor(color);
    ofCircle(pos.x, pos.y, size);
}