//
//  Copter.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Copter.h"

Copter::Copter(){
    speed = 3;
    pos.set(ofGetWidth()/2, 60);
    vel.set(speed,1);
    baits = 3;
    skin.loadImage("copter.png");
}

void Copter::update(){
    pos.x = cos(ofGetElapsedTimeMillis()/(600.0/speed))*(400.0) + 500;
    pos.y = sin(ofGetElapsedTimeMillis()/(600.0/speed))*30.0 + 30.0;
}
void Copter::draw(){
//    ofRect(pos.x, pos.y, 40, 20);
    skin.draw(pos, 80, 56);
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString(ofToString(baits), pos.x+15, pos.y+15);
    ofPopStyle();
}

void Copter::drop(){
    bait.lifetime = 10000;
    if(baits>0){
        if(bait.eaten){
            baits--;
        }
        bait.drop(pos);
    }
}