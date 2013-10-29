//
//  Particle.cpp
//  SingleParticle
//
//  Created by Charlie Whitney on 9/23/13.
//
//

#include "Particle.h"

Particle::Particle() {
    setParams(0,0,0,0);
    damping = ofVec2f( 0.01f );
    color = ofColor(ofRandom(255), ofRandom(255));
    maxSpeed = 10.0;
    maxForce = 0.4;
    slowdown = 200.0;
}

void Particle::setParams( float px, float py, float vx, float vy ){
    pos.set( px, py );
    vel.set( vx, vy );
}

void Particle::addForce( ofVec2f force ){
    frc += force;
//    frc = ofClamp(frc, 0 maxForce);
}

void Particle::addDampingForce() {
    frc = frc - vel * damping;
}

void Particle::resetForces() {
    frc.set(0,0);
}

void Particle::seek(ofVec2f dest, vector<Particle> ps) {
    ofVec2f desired = dest - pos;
    if(desired.length() < slowdown){
        float mag = ofMap(desired.length(), 0, slowdown, 0, maxSpeed);
        desired.normalize();
//        for(int i=0; i<ps.size(); i++){
//            ofVec2f collision = ps[i].pos - pos;
//            if(collision.length() < slowdown){
//                ofVec2f flee = pos - collision;
//                mag = ofMap(flee.length(), 0, slowdown, 0, maxSpeed);
////                desired *= -mag;
////                desired.x *= ofRandom(-mag);
////                desired.y *= ofRandom(-mag);                
//            }
//        }
        desired *= mag;
    } else {
        desired.normalize();
        desired *= maxSpeed;
    }
    ofVec2f steer = desired - vel;
    steer.limit(maxForce);
    addForce(steer);
}

void Particle::avoid(vector<Particle> ps) {
    for(int i=0; i<ps.size(); i++){
        ofVec2f collision = ps[i].pos - pos;
        if(collision.length() < slowdown){
            
        }
    }
}

void Particle::addRepulsionForce(const ofVec2f &dest) {
    ofVec2f diff = pos - dest;
    float strength = 1- (diff.length()/200.0);
    addForce(diff.normalize()*strength);
}

void Particle::update() {
    vel = vel + frc;
    pos = pos + vel;
    if(pos.x<0||pos.x>ofGetWidth()){
        vel.x *=-1;
    }
    if(pos.y<0||pos.y>ofGetHeight()){
        vel.y *=-1;
    }
    frc.set(0);
}

void Particle::draw() {
//    ofSetColor(255);
//    ofCircle(pos,3);

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(pos);
    float rot = atan2(vel.y,vel.x);
    ofRotate(ofRadToDeg(rot)+90);
    ofSetColor(255);
    ofRect(0,0,20,40);
    ofPopMatrix();
}