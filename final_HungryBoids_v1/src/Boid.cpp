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
    setPosition(pos);
    setVelocity(vel);
    damping = 0.98;
    setDamping(damping);
    boid.loadImage("boid.png");
}

void Boid::applyForce( ofVec2f force ){
    acc += force;
    addForce(force, 1.0);
}

void Boid::pullToCenter( ofVec2f center ){
    
    // if the particles stray too far, we want to pull them back on screen
    
    ofVec2f dir = pos - center;
    float dist = dir.length();
    float maxDistance = 10.0;
    
    if( dir.length() > maxDistance ) {
        dir.normalize();
        vel -= dir * ( ( dist - maxDistance ) * 0.0001f );
    }
}

void Boid::update(){
    
    pos = getPosition();
////    vel += getVelocity();
////    vel += getPosition();
    vel += acc;
//
    // don't move too fast
    vel.limit(8.0);

    // but also don't move too slow!
    if( vel.lengthSquared() < 1.0 ){
        vel = vel.normalized() * 1.0;
    }
    setVelocity(vel.x, vel.y);
    pos += vel;
    setPosition(pos.x, pos.y);
//
    acc.set(0);
//    setPosition(pos);
}

void Boid::draw(){
	if(!isBody()) return;
	
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
//	ofCircle(0, 0, getRadius());
    ofPushStyle();
    ofEnableAlphaBlending();
    ofSetColor(cos(ofNoise(ofGetElapsedTimeMillis()))*255,sin(ofNoise(ofGetElapsedTimeMillis()))*255,ofNoise(ofGetElapsedTimeMillis())*255);
    ofRect(ofVec2f(0,0), 10, 10);
    ofPopStyle();
    
	ofPopMatrix();
}