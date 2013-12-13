//
//  Level.h
//  HungryBoids_v2
//
//  Created by Joseph Moore on 12/13/13.
//
//

#pragma once

#include "ofMain.h"
#include "Brick.h"
#include "Condition.h"

class Level {
public:
    Level();
    int number;
    double start;
    void load(int _level);
    vector<ofVec2f> bricks;
    int bricks_num;
    int conditions_num;
    bool complete;
    Condition createCondition(int _size);
    bool checkConditions(vector<Brick> b);
    float timer;
    vector<Condition> conditions;
    void addBricks(int num);
};
