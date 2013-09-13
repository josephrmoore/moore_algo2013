//
//  dot.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Dot.h"

Dot::Dot(){
    pos.x = ofGetScreenWidth()/2;
    pos.y = ofGetScreenHeight()/2;
    
    vel.x = ofRandom(-5.0, 5.0);
    vel.y = ofRandom(-5.0, 5.0);
    
    gravity = 0.98;
    radius = 20.0;
    color = ofColor(255);
    
    moving = false;
    breathing = false;
    shaking = false;
    shake_dir = false;
    
    breathing_r = radius;
    
    swarm_anchor = pos;
}

void Dot::update() {
    pos.x += vel.x;
    pos.y += vel.y;
}

void Dot::draw() {
    ofSetColor(color);
    ofCircle(pos, breathing_r);
}


void Dot::breathe(float interval, float max_size, bool flash) {
    if(interval <= 0){
        interval = 1.0;
    }
    if(flash){
        breathing_r = radius * sin(ofGetElapsedTimeMillis());
    } else {
        breathing_r = radius * ofMap(sin(ofGetElapsedTimeMillis()/interval), -1.0, 1.0, 1.0, max_size);
    }
}

void Dot::shake(float distance) {
    if(!shake_dir){
        shake_amt = ofRandom(-distance,distance);
        pos.x += shake_amt;
        shake_dir = !shake_dir;
    } else {
        pos.x -= shake_amt;
        shake_dir = !shake_dir;
    }
}

void Dot::swarm(ofPoint p){
    float xorig = p.x;
	float yorig = p.y;
	float angle = ofGetElapsedTimef()*3.5;
	float radius = 200;
	pos.x = xorig + 200.0*(sin(ofGetElapsedTimeMillis()/200.0)) * cos(angle * 3.4);    // 3.4
	pos.y = yorig + 200.0*(cos(ofGetElapsedTimeMillis()/200.0)) * sin(angle * 4.7);   // 4.7
	
}

//void Dot::gravity(float g) {
//    pos += vel;
//    vel.y += g;
//    if(pos.y >= (ofGetScreenHeight()-150)){
//        vel.y *= -1.0;
//    }
//    vel *= 0.97;
//}

