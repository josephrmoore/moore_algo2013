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
    won = false;
}

void Level::load(int _level){
    won = false;
    level = _level;
    start = ofGetElapsedTimeMillis();
    copter.pos.set(ofGetWidth()/2, 60);

    if(level == 1){
        // precise placement of each brick instead of loop?

        copter.speed = 1;
        copter.baits = 3;
        height = 200;
    } else if (level == 2){
        copter.speed = 3;
        copter.baits = 5;
        height = 250;
    } else if (level == 3){
        copter.speed = 5;
        copter.baits = 7;
        height = 300;
    } else if (level == 0){
        copter.speed = 0;
        copter.baits = 0;
        height = 0;
    } else {
        cout<<"some other level!"<<endl;
    }
}

void Level::update(bool _bricks){

    if(ofGetElapsedTimeMillis()-start<=timelimit){
        copter.update();
        for(int i=0; i<bricks.size(); i++){
            bricks[i].update();
        }
        flocker.applyForces(80, 0.4, 0.75);
        flocker.update();
    } else {
        checkWin(_bricks);
    }
}

void Level::checkWin(bool bricks){
    // add actual conditions HERE
    if(bricks){
        win();
    } else {
        lose();
    }
}

void Level::win(){
    won = true;
    // screen stuff
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString("You Win!", 400, 200);
    ofDrawBitmapString("PRESS SPACE FOR THE NEXT LEVEL", 400, 250);
    ofPopStyle();
}

void Level::lose(){
    level = -1;
    // screen stuff
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString("You lose. Sorry.", 400, 200);
    ofDrawBitmapString("PRESS SPACE TO TRY AGAIN", 400, 250);
    ofDrawBitmapString("PRESS Q TO QUIT", 400, 300);
    ofPopStyle();
}

void Level::title(){
    level = 0;
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString("Hungry Boids", 400, 200);
    ofDrawBitmapString("PRESS SPACE TO CONTINUE", 400, 250);
    ofPopStyle();
}


void Level::draw(){
    if(level>0 && !won){
        // height line
        ofPushStyle();
        ofSetColor(0);
        string info = "";
        info += ofToString(height);
        info += " feet";
        ofDrawBitmapString(info, 20, ofGetHeight()-height+4);
        ofLine(0,ofGetHeight()-height, 15,ofGetHeight()-height);
        ofPopStyle();
        // timer countdown
        ofPushStyle();
        ofSetColor(0);
        ofDrawBitmapString(ofToString((timelimit-(ofGetElapsedTimeMillis()-start))/1000), 400, 200);
        ofPopStyle();
        // copter
        copter.draw();
        // bricks
        for(int i=0; i<bricks.size(); i++){
            bricks[i].draw();
        }
        // boids
        ofPushMatrix();{
            flocker.draw();
        }ofPopMatrix();
    }
    
    if(level>0&&won){
        win();
    }
    
    if(level == 0) {
        // intro screen
        title();
    } else if (level == -1){
        lose();
    }
    
}
