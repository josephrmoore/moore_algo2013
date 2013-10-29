//
//  Particle.cpp
//  CircleBounce
//
//  Created by Charlie Whitney on 10/12/13.
//
//

#include "Particle.h"

Particle::Particle() {
    maxRadius = 130.0;
    radiusX = maxRadius;
    radiusY = maxRadius;
    color = ofColor(ofRandom(255));
}

void Particle::update(ofVec2f circleCenter, float circleRadius) {
    pos += vel;
    
    
    // not sure how to code this: get the point that's the maxRadius from the center in this direrection
    ofVec2f tmpPos =  circleCenter-pos;
    ofVec2f dir = tmpPos.normalized();
    
    
    
    // This is the code that bounces off of a curved surface.  It's hard to understand, but feel free to use it if you like!
    // This is adapted from: http://rectangleworld.com/blog/archives/358
    if( pos.distance(circleCenter) > circleRadius ){
        ofVec2f tmpPos = pos - circleCenter;
        pos = tmpPos.normalized() * circleRadius + circleCenter;
        ofVec2f circleNormal( tmpPos.x, tmpPos.y );
        float twiceProjFactor = 2.0 * vel.dot( circleNormal ) / (circleRadius * circleRadius);
        ofVec2f velBounced = vel - ofVec2f(twiceProjFactor, twiceProjFactor) * tmpPos;
        vel.set( velBounced );
    }

    if(circleRadius - pos.distance(circleCenter) <=  maxRadius){
        float dx = dir.x - pos.x;
        float dy = dir.y - pos.y;
        angle = atan2( dy , dx );
        float val = maxRadius - (maxRadius - (circleRadius - pos.distance(circleCenter)))+abs(vel.y*10);
        radiusY = ofClamp(val, val, maxRadius*2);
        radiusX = maxRadius + (maxRadius - (circleRadius - pos.distance(circleCenter)))/2.0-abs(vel.y*3);
    } else {
        radiusY = ofClamp(maxRadius+abs(vel.y*10), maxRadius, maxRadius*2);
        radiusX = ofClamp(maxRadius-abs(vel.y*3), maxRadius, maxRadius*2);
    }

    
}

void Particle::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofPushMatrix();
    ofRotate( angle );
    ofTranslate(-pos.x, -pos.y);
    ofSetColor(color);
    ofEllipse( pos, radiusX, radiusY );
    ofPopMatrix();
    ofPopMatrix();
}