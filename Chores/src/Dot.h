//
//  dot.h
//  Chores
//
//  Created by Joseph Moore on 9/13/13.
//
//

#pragma once

#include "ofMain.h"

class Dot{
    public:
        Dot();
        void update();
        void draw();
        ofPoint pos, vel, swarm_anchor;
        ofColor color;
        float radius, gravity, shake_amt, breathing_r;
        bool moving, breathing, shaking, shake_dir;
    
        void breathe(float interval, float max_size, bool flash = false);
        void shake(float distance);
        void flash();
    
        // people dots
        void line(ofPoint start, ofPoint end);
        void fall(float gravity);
        void bounce(float floorY);
        void settle(float floorY, float gravity, int hits);

        // protagonist dots
        void dart(float startX, float endX);
        void roll(ofPoint vel);
        void jump(float startY, float endY);
        void flatten(float percent);
    
        // antagonist dots
        void swarm(ofPoint pos);
        void loop(ofPoint pos);
        void approach(ofPoint start, ofPoint end);
        void shrink(float duration);

};