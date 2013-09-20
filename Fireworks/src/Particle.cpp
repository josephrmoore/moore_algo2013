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
    lifespan = ofRandom(20, 50);
    bIsDead = false;
    agePct = 1.0;
    vel = ofVec2f( ofRandom(1.0), ofRandom(1.0) ) * 10.0 - 5.0;
    pos = p;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    radius = 9.0;
    acc = ofVec2f(vel.x/8, vel.y/8+0.38);
}

void Particle::update(){
    age++;
    if( age > lifespan ) {
        bIsDead = true;         // we've had a good life.
    }
    agePct = 1.0 - ((float)age / (float)lifespan);
    
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimef() * 0.1) * 15.0;
    pos += ofVec2f( cos(noise), sin(noise) );
    vel += acc;
    pos += vel;
    vel *= 0.97;
    
}

void Particle::draw(){
    if( bIsDead ){
        return;
    }
    ofFill();
    color.setBrightness(255);
    ofSetColor(color);
    ofCircle( pos, (radius * agePct)  );
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();
    ofVertex(pos.x+3.6,pos.y+1.2);
//    ofVertex(pos.x-3.8,pos.y+1.2);
//    ofVertex(pos.x+2.2,pos.y-3.2);
//    ofVertex(pos.x-0.2,pos.y+3.8);
//    ofVertex(pos.x-2.4,pos.y-3.2);
    ofVertex(-3.8,+1.2);
    ofVertex(+2.2,-3.2);
    ofVertex(-0.2,+3.8);
    ofVertex(-2.4,-3.2);
    ofEndShape();

}