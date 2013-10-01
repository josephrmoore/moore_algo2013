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
    img.loadImage("debris"+ofToString((int)ofRandom(7))+".png");
    img_w = 30;
    img_h = 30;
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
    img.resize(sin(ofGetElapsedTimeMillis())*img_w,cos(ofGetElapsedTimeMillis())*img_h);
    vel = vel + frc;
    pos = pos + vel;
}

void Particle::draw(float size) {
    ofSetColor(color);
    img.draw(pos.x, pos.y);
}