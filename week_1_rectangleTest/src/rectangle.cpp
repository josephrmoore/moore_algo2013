//
//  rectangle.cpp
//  rectangleTest
//
//  Created by Joseph Moore on 8/27/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#include "rectangle.h"

Rectangle::Rectangle(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    posA.x = 100;
    posA.y = 100;
    posB.x = 400;
    posB.y = 400;
    pos.x = posA.x;
    pos.y = posA.y;
    radius.x = 100;
    radius.y = 100;
    color.r = 255;
    color.g = 255;
    color.b = 255;
}

//void Rectangle::update(){
//    pos.x = pos.x + ofRandom(-1,1);
//    pos.y = pos.x + ofRandom(-1,1);
//}

void Rectangle::draw(){
    ofEnableAlphaBlending();
    ofSetColor(color);
    ofRect(pos.x,pos.y,radius.x,radius.y);
}
//
//void Rectangle::interpolateByPercent(float percent){
//    Rectangle::percent = percent;
//    pos.x = ((1-percent) * posA.x) + (percent*posB.x);
//    pos.y = ((1-percent) * posA.y) + (percent*posB.y);
//}


void Rectangle::interpolateByPercent(float percent){
    float p = powf(percent,2);
    pos.x = ((1-p) * posA.x) + (p*posB.x);
    pos.y = ((1-p) * posA.y) + (p*posB.y);
}

void Rectangle::xenoToPoint(float catchX, float catchY, float catchUpSpeedX, float catchUpSpeedY){
    float cX = catchUpSpeedX;
    float cY = catchUpSpeedY;
    pos.x = (cX*catchX) + ((1-cX)*pos.x);
    pos.y = (cY*catchY) + ((1-cY)*pos.y);
}
