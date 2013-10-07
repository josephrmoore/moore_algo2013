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
    string file = f+s+".svg";
    cout<<file<<endl;
    svg.load(file);
    falling = false;
    bounce = ofRandom(5,20);
}

void Card::update(){
    vel += acc;
    pos += vel;
    acc.set(0);
    vel *= 0.95;
    if(pos.y>=ofGetHeight()-400){
        vel *= -1;
        if(vel.y<0){
            addForce(vel/bounce);
        }
        if(pos.y>ofGetHeight()-400){
            pos.y = ofGetHeight()-400;
        }
    }
}

void Card::draw(){
    svg.draw(pos.x,pos.y,scale);
}

void Card::addForce(ofVec2f f){
    acc += (f/mass);
}
