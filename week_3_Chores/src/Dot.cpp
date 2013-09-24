//
//  dot.cpp
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#include "Dot.h"

Dot::Dot(){
    pos.x = 0;
    pos.y = ofRandom(100);
    
//    vel.x = ofRandom(-5.0, 5.0);
//    vel.y = ofRandom(-5.0, 5.0);

    vel.x = 0.0;
    vel.y = 0.0;
    
    rotation = 0.0;
    gravity = 0.98;
    radius.x = ofRandom(30.0, 50.0);
    radius.y = radius.x;
    color = ofColor(ofRandom(50.0, 155.0));
    
    // pos
    moving = false;
    shaking = false;
    darting = false;
    rolling = false;
    jumping = false;
    swarming = false;
    looping = false;
    approaching = false;
    
    // radius
    breathing = false;
    shrinking = false;
    flattening = false;
    
    shake_dir = false;
    
    swarm_anchor = pos;
    shrink_timer = 0;
    
    type = "dot";
    
    line_y = pos.y;
}

void Dot::update() {
    pos.x += vel.x;
    pos.y += vel.y;
}

void Dot::draw(ofPoint r, ofPoint p) {
    ofSetColor(color);
    ofEllipse(p, r.x, r.y);
}


ofPoint Dot::breathe(float interval, float max_size, bool flash) {
    breathing = true;
    ofPoint p;
    if(interval <= 0){
        interval = 1.0;
    }
    if(flash){
        p.x = radius.x * sin(ofGetElapsedTimeMillis());
        p.y = radius.y * sin(ofGetElapsedTimeMillis());
    } else {
        p.x = radius.x * ofMap(sin(ofGetElapsedTimeMillis()/interval), -1.0, 1.0, 1.0, max_size);
        p.y = radius.y * ofMap(sin(ofGetElapsedTimeMillis()/interval), -1.0, 1.0, 1.0, max_size);
    }
    return p;
}

float Dot::shake(float distance) {
    shaking = true;
    float x;
    if(!shake_dir){
        shake_amt = ofRandom(-distance,distance);
        x = pos.x + shake_amt;
        shake_dir = !shake_dir;
    } else {
        x = pos.x - shake_amt;
        shake_dir = !shake_dir;
    }
    return x;
}

void Dot::line(float amt){
    pos.y += amt;
    line_y = pos.y;
}

void Dot::fall(float gravity){
    this->applyGravity(gravity, ofGetHeight(), true);
}

void Dot::bounce(float floorY){
    
}

void Dot::settle(float floorY, float gravity, int hits){
    
}

void Dot::dart(float endX, float speed){
    darting = true;
    this->xenoToPoint(endX, this->pos.y, 0.01*speed, 0.01*speed);
}

void Dot::rotate(float amt){
    if(vel.x > 0){
        rotation -= amt;
    } else {
        rotation += amt;
    }
}

void Dot::roll(float amt){
    if(this->type == "ant"){
        this->swarm_anchor.x += amt;
    } else {
        this->pos.x += amt;
    }
}

void Dot::jump(float startY, float endY, float speed, float g){
    if(this->pos.y >= (endY+5) && falling == false){
        jumping = true;
        this->xenoToPoint(this->pos.x, endY, 0.01*speed, 0.01*speed);
    } else {
        jumping = false;
        falling = true;
        this->applyGravity(g, startY, true);
    }
}

ofPoint Dot::flatten(float percent){
    flattening = true;
    ofPoint p;
    p = this->interpolateByPercent(0.5, radius, ofPoint(radius.x+radius.x*0.1, radius.y*percent*0.01));
    return p;
}

ofPoint Dot::swarm(ofPoint p){
    swarming = true;
    moving = true;
    ofPoint pt;
    float xorig = p.x;
	float yorig = p.y;
	float angle = ofGetElapsedTimef()*3.5;
	float radius = 200;
	pt.x = xorig + 200.0*(sin(ofGetElapsedTimeMillis()/200.0)) * cos(angle * 3.4);    // 3.4
	pt.y = yorig + 200.0*(cos(ofGetElapsedTimeMillis()/200.0)) * sin(angle * 4.7);   // 4.7
	return pt;
}

ofPoint Dot::loop(float period){
    looping = true;
    ofPoint p;
    p.x = swarm_anchor.x + sin(ofGetElapsedTimeMillis()/period)*100.0;
    p.y = swarm_anchor.y + (cos(ofGetElapsedTimeMillis()/period)*100.0)/2;
    return p;
}

void Dot::approach(ofPoint start, ofPoint end, float speed){
    if(approaching == false){
        swarm_anchor = start;
    }
    approaching = true;
    swarm_anchor = this->interpolateByPercent(0.01*speed, swarm_anchor, end);
    // lissajous
    // xeno to "end"
}

void Dot::shrink(float amt){
    shrinking = true;
    if(radius.x > 0 && radius.y > 0){
        radius.x -= amt;
        radius.y -= amt;
    }
}

void Dot::stop(){
    moving = false;
    shaking = false;
    darting = false;
    rolling = false;
    jumping = false;
    swarming = false;
    looping = false;
    approaching = false;
}


ofPoint Dot::interpolateByPercent(float percent, ofPoint posA, ofPoint posB){
    ofPoint pt;
    float p = powf(percent,2);
    pt.x = ((1-p) * posA.x) + (p*posB.x);
    pt.y = ((1-p) * posA.y) + (p*posB.y);
    return pt;
}

void Dot::xenoToPoint(float catchX, float catchY, float catchUpSpeedX, float catchUpSpeedY){
    float cX = catchUpSpeedX;
    float cY = catchUpSpeedY;
    pos.x = (cX*catchX) + ((1-cX)*pos.x);
    pos.y = (cY*catchY) + ((1-cY)*pos.y);
}

void Dot::applyGravity(float g, float floor, bool bounce) {
    if(pos.y <= floor){
       vel.y += g;
    }
    if(pos.y >= (floor) && bounce){
        vel.y *= -1.0;
    }
    vel *= ofRandom(0.95,0.97);
}

