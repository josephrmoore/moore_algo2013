//
//  Copter.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "Copter.h"

Copter::Copter(){
    speed = 2;
    pos.set(ofGetWidth()/2, 60);
    vel.set(speed,1);
    baits = 1;
    skin.loadImage("copter.png");
    section = 0;
    toss.loadSound("toss.wav");
    toss.setMultiPlay(true);
    fall.loadSound("fall.wav");
    fall.setMultiPlay(true);
    fall2.loadSound("fall2.wav");
    fall2.setMultiPlay(true);
}

void Copter::update(){
    pos.x = cos(ofGetElapsedTimeMillis()/(600.0/speed))*(400.0) + 500;
    pos.y = sin(ofGetElapsedTimeMillis()/(600.0/speed))*30.0 + 30.0;
    think();
    t.update();
    if(t.activate){
        // do stuff here
        if(section<drop_points.size()-1){
            section+=1;
        }
        t.reset();
    }
}
void Copter::draw(){
    ofPushStyle();
    ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
    skin.draw(pos, 80, 56);
    ofPopStyle();
}

void Copter::drop(){
    if(baits>0){
        if(bait.eaten){
            baits--;
            toss.setPosition(0);
            fall.setPosition(0);
            fall2.setPosition(0);
            toss.play();
            fall.play();
            fall2.play();
        }
        bait.drop(pos);
    }

}

void Copter::load(float timer){
    level_time = timer;
    period = level_time/baits;
    bait.lifetime = period/2;
    t.setLimit(period);
    section = 0;
    for(int i=0; i<baits; i++){
        float point = ofRandom(0,period);
        drop_points.push_back(point);
    }
}

void Copter::think(){
//    cout<<"now: "<<ofGetElapsedTimeMillis()<<endl;
//    cout<<"dest: "<<t.start+(section*period)<<endl;
//    cout<<"timer start: "<<t.start<<endl;
//    cout<<"section: "<<section<<endl;
//    cout<<"period: "<<period<<endl;
//    cout<<"droppoints size: "<<drop_points.size()<<endl;
    if(ofGetElapsedTimeMillis()>=t.start+drop_points[section-1]){
        drop();
    }
}