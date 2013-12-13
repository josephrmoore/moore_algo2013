//
//  Bait.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "Bait.h"

Bait::Bait(){
    lifetime = -1;
    eaten = true;
    radius = 100.0;
    dropped = false;
}

void Bait::drop(ofVec2f _pos){
    if(eaten){
        setPosition(_pos);
        pos = _pos;
        timer = ofGetElapsedTimeMillis();
        eaten = false;
    }
//    dropped = true;
}

void Bait::update(){
    pos = getPosition();
    
    if(ofGetElapsedTimeMillis()-timer>lifetime && lifetime!=-1){
        eaten = true;
    } else {
        eaten = false;
    }
    
    if(eaten){
        // reset to offscreen
        pos = ofVec2f(ofGetWidth()/2, -ofGetHeight()/2);
    } else {
        // shrink radius while onscreen if timed
        if(lifetime>-1){
            setRadius(radius/2-((ofGetElapsedTimeMillis()-timer)/lifetime*radius/2));
        } else {
//            setRadius(radius/2);
        }
    }
}

void Bait::draw(){
	if(!isBody()) return;
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
    ofPushStyle();
    ofColor c = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    ofSetColor(c);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofCircle(0, 0, getRadius());
    ofEnableAlphaBlending();
    ofPopStyle();
	ofPopMatrix();
}