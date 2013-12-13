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
    c.height = _size;
    conditions.push_back(c);
    return c;
}

bool Level::checkConditions(vector<Brick> b){
    bool allmet = true;
    vector<int> winners;
    for(int i=0; i<conditions.size(); i++){
        bool anymet = false;
        for(int j=0; j<b.size(); j++){
            if(b[j].isSleeping() && b[j].getPosition().y<ofGetHeight()-(conditions[i].height*100)+50){
                if(winners.size()>0){
                    for(int k=0; k<winners.size(); k++){
                        if(j!=winners[k]){
                            bool stack = false;
                            for (b2ContactEdge* edge = b[j].body->GetContactList(); edge; edge = edge->next){
                                b2Fixture* a1 = edge->contact->GetFixtureA();
                                b2Fixture* a2 = edge->contact->GetFixtureB();
                                if(a1->GetBody()->GetPosition() == b[winners[k]].body->GetPosition() || a2->GetBody()->GetPosition() == b[winners[k]].body->GetPosition()){
                                    stack = true;
                                }
                            }
                            if(!stack){
                                anymet = true;
                                winners.push_back(j);
                                bricks.push_back(b[j].getPosition());
                            }
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
