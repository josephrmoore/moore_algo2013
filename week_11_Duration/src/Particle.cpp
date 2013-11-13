//
//  Particle.cpp
//  Duration
//
//  Created by Joseph Moore on 11/12/13.
//
//

#include "Particle.h"

Particle::Particle(){
    pos.set(ofRandomWidth(),ofRandomHeight(),ofRandomWidth());
//    vel.set(ofRandom(-10,10),ofRandom(-10,10),ofRandom(-10,10));
    vel.set(0);
    color = ofColor(ofRandom(150,255), ofRandom(50,200));
    radius = ofVec2f(ofRandom(2,6));
}

//--------------------------------------------------------------
void Particle::update(){
    vel += acc;
    vel *= 0.97;
    pos += vel;
    acc.set(0);
    if(pos.x<0 || pos.x>ofGetWidth()-2*radius.x){
        vel.x *= -1.0;
    }
    if(pos.y<0 || pos.y>ofGetHeight()-2*radius.y){
        vel.y *= -1.0;
    }
}

//--------------------------------------------------------------
void Particle::draw(){
    ofPushStyle();
    ofSetColor(color);
    ofEllipse(pos.x, pos.y, radius.x, radius.y);
    ofPopStyle();
}

void Particle::applyForce(ofVec3f force){
    acc += force;
}

