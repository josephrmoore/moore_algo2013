//
//  Particle.cpp
//  Attraction
//
//  Created by Joseph Moore on 10/6/13.
//
//

#include "Particle.h"

Particle::Particle(){
    damping = 0.05;
    pos.x = ofRandom(ofGetWidth());
    pos.y = ofRandom(ofGetHeight());
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(255));
    color.setSaturation(50);
    radius = 3;
}

void Particle::addForce(ofVec2f force){
    acc += force;
}

void Particle::addRepulsionForce(float px, float py, float r, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos-posOfForce;
    if(diff.length()<r){
        float pct = 1-(diff.length()/r);
        diff.normalize();
        acc.x += diff.x * pct * strength;
        acc.y += diff.y * pct * strength;
    }
}

void Particle::addAttractionForce(float px, float py, float r, float strength){
    ofVec2f posOfForce;
    posOfForce.set(px, py);
    ofVec2f diff = pos-posOfForce;
    cout<<radius<<endl;
    if(diff.length()<r){
        float pct = 1-(diff.length()/r);
        diff.normalize();
        acc.x -= diff.x * pct * strength;
        acc.y -= diff.y * pct * strength;
    }
}

void Particle::update(){
    vel += acc;
    pos += vel;
    vel *= damping;
    acc.set(0);

}

void Particle::draw(){
    ofCircle(pos, radius);
}