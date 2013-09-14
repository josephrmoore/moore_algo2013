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
        ofPoint pos, vel, radius, swarm_anchor;
        ofColor color;
        float gravity, rotation, shake_amt, breathing_r, rX, rY, shrink_timer;
        bool moving, breathing, shaking;
        bool lining, falling, bouncing, settling;
        bool darting, rolling, jumping, flattening;
        bool swarming, looping, approaching, shrinking;
        bool shake_dir;
    
        string type;
    
        ofPoint breathe(float interval, float max_size, bool flash = false);
        float shake(float distance);
    
        void update();
        void draw(ofPoint r, ofPoint p);

        ofPoint interpolateByPercent(float percent, ofPoint posA, ofPoint posB);
        void xenoToPoint(float catchX, float catchY, float catchUpSpeedX, float catchUpSpeedY);
        void applyGravity(float g, float floor, bool bounce);
    
        // people dots
        void line(float amt);
        void fall(float gravity);
        void bounce(float floorY);
        void settle(float floorY, float gravity, int hits);

        // protagonist dots
        void dart(float endX, float speed);
        void roll(float amt);
        void rotate(float amt);
        void jump(float startY, float endY, float speed, float g);
        ofPoint flatten(float percent);
    
        // antagonist dots
        ofPoint swarm(ofPoint pos);
        ofPoint loop(float period);
        void approach(ofPoint start, ofPoint end, float speed);
        void shrink(float amt);

        void stop();
};