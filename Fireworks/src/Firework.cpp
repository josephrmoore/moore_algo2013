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
    vel = ofVec2f(ofRandom(-5.0,5.0), speed);
    detonate_y = ofGetHeight()/2;
    detonated = false;
    number = 50;
}

void Firework::update(){
    pos += vel;
    vel *= 0.97;
    if(pos.y <= detonate_y){
        detonated = true;
        explode();
    }
    trails.push_back(pos);
    if(detonated){
        for( vector<Particle>::iterator it=pList.begin(); it!=pList.end(); ){
            it->update();
            cout<<"updating"<<endl;
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
        cout<<":detonated"<<endl;
        for( vector<Particle>::iterator it = pList.begin(); it!=pList.end(); it++){
            it->draw();
        }
    } else {
        cout<<"not det"<<endl;
        for(int i=0; i<trails.size(); i++){
            ofSetColor(255*ofMap(sin(ofGetElapsedTimeMillis()/200.0), -1.0,1.0,0,1));
            ofCircle(trails[i], 5);
        }
        ofSetColor(255);
        ofFill();
        ofCircle(pos, 3);
    }
}

void Firework::explode(){
    cout<<"explode!"<<endl;
        for( int i=0; i<number; i++ ){
            Particle p;
            p.setup();
            pList.push_back( p );
        }
}