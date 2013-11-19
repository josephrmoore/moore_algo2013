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

void Level::load(int level){
    if(level == 1){
        // precise placement of each brick instead of loop?
        for(int i=0; i<10; i++){
            Brick b;
            bricks.push_back(b);
        }
        copter.base_speed = 3;
        copter.baits = 3;
        
    } else if (level == 2){
        
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
    flocker.applyForces(80, 0.4, 0.75);
    flocker.update();
}

void Level::draw(){
    copter.draw();
    for(int i=0; i<bricks.size(); i++){
        bricks[i].draw();
    }
    flocker.draw();
}
