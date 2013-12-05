//
//  Level.h
//  HungryBoids_v1
//
//  Created by Joseph Moore on 11/19/13.
//
//

#pragma once

#include "ofMain.h"
#include "Brick.h"
#include "FlockController.h"
#include "Copter.h"
#include "Player.h"

class Level {
public:
    Level();
    Player player;
    Copter copter;
    FlockController flocker;
    vector<Bait> bait_drops;
    vector<Brick> bricks;
    void load(int level);
    int level; // -2=lose, -1=win, 0=title, 1->n=level
    void setup(b2World* world);
    void update(bool bricks);
    void draw();
    int square20, square40, rect200x20, rect20x200;
    float height;
    double start;
    float timelimit;

    void title();
    void win();
    void lose();
    void checkWin(bool _bricks);
    bool won;
    void reset();
    ofImage bk;
};