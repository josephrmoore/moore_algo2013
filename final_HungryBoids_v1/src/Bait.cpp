//
//  Bait.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Bait.h"

Bait::Bait(){
    lifetime = -1;
    eaten = true;
    img.loadImage("baitball.png");
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
}

void Bait::update(){
    pos = getPosition();
    
    if(ofGetElapsedTimeMillis()-timer>lifetime){
        eaten = true;
    } else {
        eaten = false;
    }
    
    if(lifetime==-1){
        eaten = false;
    }
    
    if(eaten){
        pos = ofVec2f(-ofGetWidth(), -ofGetHeight());
    } else {
        if(lifetime>-1){
            setRadius(radius/2-((ofGetElapsedTimeMillis()-timer)/lifetime*radius/2));
        }
    }
}

void Bait::draw(){
	if(!isBody()) return;
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
//    ofCircle(0, 0, getRadius());
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    img.draw(ofVec2f(-90,-90), getRadius()*2,getRadius()*2);
    ofEnableAlphaBlending();
    ofSetColor(0);
    //	ofLine(0, 0, radius, 0);
    if(isSleeping()) {
        ofSetColor(255, 100);
        ofCircle(0, 0, getRadius());
    }
    ofPopStyle();
    
	ofPopMatrix();
}