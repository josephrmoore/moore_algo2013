//
//  Particle.cpp
//  Fireworks
//
//  Created by Joseph Moore on 9/19/13.
//
//

#include "Particle.h"

void Particle::setup(ofVec2f p){
    age = 0;
    lifespan = ofRandom(50, 150);
    bIsDead = false;
    agePct = 1.0;
    vel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    pos = p;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    radius = 5.0;
}

void Particle::update(){
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    pos += ofVec2f( cos(noise), sin(noise) );

    pos += vel;
    vel *= 0.97;
    
    age++;
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
    agePct = 1.0 - ((float)age / (float)lifespan);
}

void Particle::draw(){
    if( bIsDead ){
        return;
    }
    ofFill();
    ofSetColor(color);
    ofCircle( pos, (radius * agePct)  );

}