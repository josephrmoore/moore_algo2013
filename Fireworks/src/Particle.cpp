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
    radius = 10.0;
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
    float noise = ofNoise(pos.x * 0.005, pos.y*0.005, ofGetElapsedTimeMillis()/300.0) * 15.0;
    color = ofColor(color.r, color.g, color.b, ofMap(sin(ofGetElapsedTimeMillis()/ofRandom(50.0,100.0))*255.0, -1.0, 1.0, 0, 1)*255);
    ofSetColor(color);
    ofCircle( pos, (radius * agePct)  );
    ofSetPolyMode(OF_POLY_WINDING_NONZERO);
    ofBeginShape();{
        float x = pos.x;
        float y = pos.y;
        ofVertex(ofRandom(-3,3)+x+9.0*1.5*agePct,ofRandom(-3,3)+y+3.0*1.5*agePct);
        ofVertex(ofRandom(-3,3)+x-9.5*1.5*agePct,ofRandom(-3,3)+y+3.0*1.5*agePct);
        ofVertex(ofRandom(-3,3)+x+5.5*1.5*agePct,ofRandom(-3,3)+y-8.0*1.5*agePct);
        ofVertex(ofRandom(-3,3)+x-5.0*1.5*agePct,ofRandom(-3,3)+y+9.5*1.5*agePct);
        ofVertex(ofRandom(-3,3)+x-6.0*1.5*agePct,ofRandom(-3,3)+y-8.0*1.5*agePct);
    };ofEndShape();
}