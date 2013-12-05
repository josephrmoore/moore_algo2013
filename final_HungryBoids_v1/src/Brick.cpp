//
//  Brick.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Brick.h"

Brick::Brick(){
    img.loadImage("brick.jpg");
}

void Brick::draw(){
	if(!isBody()) return;
	ofPushMatrix();
	ofTranslate(getPosition().x, getPosition().y, 0);
	ofRotate(getRotation(), 0, 0, 1);
    //    ofCircle(0, 0, getRadius());
    ofPushStyle();
    ofSetRectMode(OF_RECTMODE_CENTER);
    img.draw(ofVec2f(0,0), getWidth()*2,getHeight()*2);
    ofEnableAlphaBlending();
    ofSetColor(0);
    //	ofLine(0, 0, radius, 0);
    if(isSleeping()) {
//        ofSetColor(255, 100);
//        ofRect(0, 0, getWidth(), getHeight());
    }
    ofPopStyle();
    
	ofPopMatrix();
}