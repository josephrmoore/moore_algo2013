//
//  Level.cpp
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#include "Level.h"

Level::Level(){

}

void Level::setup(b2World* _box){
//    box = _box;
//    for(int i=0; i<10; i++){
//        Brick b(box);
//        bricks.push_back(b);
//    }
    flocker.addParticle( _box, 100 );
    timelimit = 30000;
    level = 0;
}

void Level::load(int _level){
    level = _level;
    start = ofGetElapsedTimeMillis();
    copter.pos.set(ofGetWidth()/2, 60);

    if(level == 1){
        // precise placement of each brick instead of loop?

        copter.speed = 1;
        copter.baits = 3;
        square20 = 4;
        square40 = 2;
        rect200x20 = 2;
        rect20x200 = 4;
        height = 200;
    } else if (level == 2){
        copter.speed = 3;
        copter.baits = 5;
        square20 = 2;
        square40 = 4;
        rect200x20 = 1;
        rect20x200 = 2;
        height = 250;
    } else if (level == 3){
        copter.speed = 5;
        copter.baits = 7;
        height = 300;
    } else if (level == 0){
        height = 0;
    } else {
        cout<<"some other level!"<<endl;
    }
}

void Level::update(){

    if(ofGetElapsedTimeMillis()-start<=timelimit){
        copter.update();
        for(int i=0; i<bricks.size(); i++){
            bricks[i].update();
        }
        flocker.applyForces(80, 0.4, 0.75);
        flocker.update();
    } else {
        load(0);
    }
}

void Level::draw(){
    if(height>0){
        ofPushStyle();
        ofSetColor(0);
        string info = "";
        info += ofToString(height);
        info += " feet";
        ofDrawBitmapString(info, 20, ofGetHeight()-height+4);
        ofLine(0,ofGetHeight()-height, 15,ofGetHeight()-height);
        ofPopStyle();
        ofPushStyle();
        ofSetColor(0);
        ofDrawBitmapString(ofToString((timelimit-(ofGetElapsedTimeMillis()-start))/1000), 400, 200);
        ofPopStyle();
        copter.draw();
        for(int i=0; i<bricks.size(); i++){
            bricks[i].draw();
        }
        ofPushMatrix();{
            //        ofTranslate( ofGetWindowSize() / 2.0 );
            flocker.draw();
        }ofPopMatrix();
        //    flocker.draw();
    } else {
        ofPushStyle();
        ofSetColor(0);
        ofDrawBitmapString("Hungry Boids", 400, 200);
        ofDrawBitmapString("PRESS SPACE TO CONTINUE", 400, 250);
        ofPopStyle();
    }
}
