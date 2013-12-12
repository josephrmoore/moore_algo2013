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
    bk.loadImage("bk.jpg");
    title_bk.loadImage("boids_titlescreen_bk.png");
    title_hungry.loadImage("boids_titlescreen_hungry.png");
    title_boids.loadImage("boids_titlescreen_boids.png");
    title_start.loadImage("boids_titlescreen_start.png");
    flocker.addParticle( _box, 100 );
    timelimit = 30000;
    level = 0;
    won = false;
    title_back.limit = 2000;
    title_word1.limit = 200;
    title_word2.limit = 50;
    word1 = ofColor(255);
    word2 = ofColor(255);
    back = ofColor(255);
}

void Level::load(int _level){
    won = false;
    level = _level;
    start = ofGetElapsedTimeMillis();
    copter.pos.set(ofGetWidth()/2, 60);
    level_bars.limit = 1000;
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
    ofBackground(back);
    title_back.update();
    if(title_back.activate == true){
        back = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
        back.setBrightness(255);
        title_back.reset();
    }
    if(ofGetElapsedTimeMillis()-start<=timelimit){
        if(level_bars.activate == true){
            level_bars.reset();
        }
        copter.update();
        for(int i=0; i<bricks.size(); i++){
            bricks[i].update();
        }
        flocker.applyForces(80, 0.4, 0.75);
        flocker.update();
        level_bars.update();
    } else if(level>0){
        checkWin(_bricks);
    }
    if(level==0){
        title_word1.update();
        if(title_word1.activate == true){
            word1 = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            word1.setBrightness(255);
            title_word1.reset();
        }
        title_word2.update();
        if(title_word2.activate == true){
            word2 = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
            word2.setBrightness(255);
            title_word2.reset();
        }
    }
    copter.bait.update();
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
    title_bk.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    title_start.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    ofPushStyle();
    ofSetColor(word1);
    title_hungry.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    ofPushStyle();
    ofSetColor(word2);
    title_boids.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
    ofPopStyle();
    copter.bait.draw();
    flocker.draw();
}


void Level::draw(){
    if(level>0 && !won){
//        bk.draw(ofVec2f(0,0),ofGetWidth(),ofGetHeight());
        ofSetColor(255);
        int rows = ofGetHeight()/64;
        int step = 255/rows;
        for(int i=0; i<rows; i++){
            ofPushStyle();
            ofSetColor(i*step, 100);
            ofRect(0,i*64,ofGetWidth(),64);
            ofPopStyle();
        }
        
        // height line
        ofPushStyle();
        ofSetColor(255);
        string info = "";
        info += ofToString(height);
        info += " feet";
        ofDrawBitmapString(info, 20, ofGetHeight()-height+4);
        ofLine(0,ofGetHeight()-height, 15,ofGetHeight()-height);
        ofPopStyle();
        // timer countdown
        ofPushStyle();
        ofSetColor(255);
        ofDrawBitmapString(ofToString((timelimit-(ofGetElapsedTimeMillis()-start))/1000), 900, 20);
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
        if(copter.bait.dropped == false){
            copter.bait.eaten = true;
            copter.bait.drop(ofVec2f(200.0,0));
            copter.bait.dropped = true;
        }
    } else if (level == -1){
        lose();
    }
    
}

void Level::reset(){
    
}
