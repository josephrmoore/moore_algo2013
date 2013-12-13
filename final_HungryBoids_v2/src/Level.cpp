//
//  Level.cpp
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#include "Level.h"

Level::Level(){
    complete = false;
}

void Level::load(int _level){
    number = _level;
    start = ofGetElapsedTimeMillis();
    
}

void Level::checkWin(){
    
}

Condition Level::createCondition(int _size){
    Condition c;
    c.height = _size*100;
    conditions.push_back(c);
    return c;
}

bool Level::checkConditions(vector<Brick> b){
    bool allmet = true;
    vector<int> winners;
    for(int i=0; i<conditions.size(); i++){
        bool anymet = false;
        for(int j=0; j<b.size(); j++){
            cout<<"i: "<<i<<" j: "<<j<<endl;
            cout<<b[j].getPosition().y<<endl;
            cout<<ofGetHeight()-conditions[i].height<<endl;
            if(b[j].isSleeping() && b[j].getPosition().y<ofGetHeight()-conditions[i].height+50){
                if(winners.size()>0){
                    for(int k=0; k<winners.size(); k++){
                        if(j!=winners[k]){
                            anymet = true;
                            winners.push_back(j);
                            bricks.push_back(b[j].getPosition());
                        }
                    }
                } else {
                    anymet = true;
                    winners.push_back(j);
                    bricks.push_back(b[j].getPosition());
                }
            }
        }
        if(anymet==false){
            allmet=false;
        }
    }
    return allmet;
}
