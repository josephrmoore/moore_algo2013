//
//  Card.cpp
//  SolitaireEnding
//
//  Created by Joseph Moore on 10/5/13.
//
//

#include "Card.h"

Card::Card(string s, string f){
    suit = s;
    face = f;
    pos = ofVec2f(ofRandom(ofGetWidth()),ofRandom(-200,ofGetHeight()-600));
//    pos = ofVec2f(0,0);
    mass = 0.1;
    scale = 0.4;
    falling = false;
    bounce = ofRandom(5,20);
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(155,205));
    height = 200;
    width = 120;
    float fl = ofRandom(100);
    if(fl>50){
        square = true;
    } else {
        square = false;
    }
}

void Card::update(){
    vel += acc;
    pos += vel;
    acc.set(0);
    vel *= 0.95;
    if(pos.y>=ofGetHeight()-height){
        vel *= -1;
        if(vel.y<0){
            addForce(vel/bounce);
        }
        if(pos.y>ofGetHeight()-height){
            pos.y = ofGetHeight()-height;
        }
    }
}

void Card::draw(){
    ofSetColor(color);
    if(square){
        ofRect(pos.x,pos.y,width,height);
    } else {
        ofEllipse(pos.x,pos.y,width,height);
    }
}

void Card::addForce(ofVec2f f){
    acc += (f/mass);
}
