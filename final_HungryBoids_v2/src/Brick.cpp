//
//  Brick.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "Brick.h"

Brick::Brick(){
}

void Brick::draw(){
	if(!isBody()) return;
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(0);
    ofRect(ofVec2f(0,0), getWidth()*2,getHeight()*2);
    ofEnableAlphaBlending();
    ofSetColor(0);
    ofPopStyle();
	ofPopMatrix();
}