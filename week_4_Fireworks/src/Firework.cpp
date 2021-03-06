//
//  Firework.cpp
//  Fireworks
//
//  Created by Joseph Moore on 9/20/13.
//
//

#include "Firework.h"

void Firework::setup(ofSoundPlayer s1, ofSoundPlayer s2){
    speed = -20.0;
    pos = ofVec2f(ofGetWidth()/2, ofGetHeight());
    vel = ofVec2f(ofRandom(-10.0,10.0), speed);
    detonate_y = ofGetHeight()/2-200 + ofRandom(-35.0,35.0);
    detonated = false;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
    timer = ofGetElapsedTimeMillis();
    curve = ofRandom(-vel.x, vel.x);
    over = false;
    reax = s1;
    explosion = s2;
}

void Firework::update(){
    pos.x += 5.0*(powf(cos(curve), 3.0));
    pos.y += vel.y;
    vel *= 0.97;
    if(pos.y <= detonate_y && detonated == false){
        detonated = true;
        explode(pos);
    }
    trails.push_back(pos);
    if(detonated){
        trails.clear();
        for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
            it->update();
            if( it->bIsDead ){
                it = pList.erase(it);
                ofLog( OF_LOG_NOTICE, "size is " + ofToString(pList.size()) );
            }else {
                it++;
            }
        }
        if(pList.size()==0){
            over = true;
        }
    }
}

void Firework::draw(float x, float y){

    if(detonated){
        for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
                it->draw();
        }
    } else {
        for( vector<ofPoint>::iterator it = trails.begin(); it!=trails.end(); it++){
            ofSetColor(75*ofMap(sin((ofGetElapsedTimeMillis()-timer)/220.0), -1.0,1.0,0,1));
            ofCircle(it->x, it->y, 5);
            
        }
        ofSetColor(255);
        ofFill();
        ofCircle(pos, 3);
    }
}

void Firework::explode(ofVec2f p){
    number = ofMap(sin(ofGetElapsedTimeMillis()), -1.0,1.0,0,1.0)*80+20;
    for( int i=0; i<number; i++ ){
        Particle pa;
        pa.setup(p);
        pa.color = color;
        pList.push_back( pa );
    }
    reax.play();
    explosion.play();
}