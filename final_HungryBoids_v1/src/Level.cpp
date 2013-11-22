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
}

void Level::load(int level){
    if(level == 1){
        // precise placement of each brick instead of loop?

        copter.base_speed = 3;
        copter.baits = 3;
        square20 = 4;
        square40 = 2;
        rect200x20 = 2;
        rect20x200 = 4;
    } else if (level == 2){
        copter.base_speed = 4;
        copter.baits = 4;
        square20 = 2;
        square40 = 4;
        rect200x20 = 1;
        rect20x200 = 2;
    } else if (level == 3){
        
    } else {
        cout<<"some other level!"<<endl;
    }
}

void Level::update(){
    copter.update();
    for(int i=0; i<bricks.size(); i++){
        bricks[i].update();
    }
    flocker.update();
    flocker.applyForces(80, 0.4, 0.75);
}

void Level::draw(){
    copter.draw();
    for(int i=0; i<bricks.size(); i++){
        bricks[i].draw();
    }
    ofPushMatrix();{
        ofTranslate( ofGetWindowSize() / 2.0 );
        flocker.draw();
    }ofPopMatrix();
//    flocker.draw();
}
