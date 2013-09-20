//
//  Firework.cpp
//  Fireworks
//
//  Created by Joseph Moore on 9/20/13.
//
//

#include "Firework.h"

void Firework::setup(){
    speed = -15.0;
    pos = ofVec2f(ofGetWidth()/2, ofGetHeight());
    vel = ofVec2f(ofRandom(-10.0,10.0), speed);
    detonate_y = ofGetHeight()/2;
    detonated = false;
    number = 50;
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Firework::update(){
    pos += vel;
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
    }
}

void Firework::draw(){

    if(detonated){
        for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
            it->draw();
        }
    } else {
        for( vector<ofPoint>::iterator it = trails.begin(); it!=trails.end(); it++){
            ofSetColor(205*ofMap(sin(ofGetElapsedTimeMillis()/200.0), -1.0,1.0,0,1));
            ofCircle(it->x, it->y, 5);
            
        }
        ofSetColor(255);
        ofFill();
        ofCircle(pos, 3);
    }
}

void Firework::explode(ofVec2f p){
        for( int i=0; i<number; i++ ){
            Particle pa;
            pa.setup(p);
            pa.color = color;
            pList.push_back( pa );
        }
}