//
//  ball.h
//  Gravity
//
//  Created by Joseph Moore on 9/8/13.
//  Copyright 2013 __MyCompanyName__. All rights reserved.
//

#pragma once

#include "ofMain.h"

class Ball {
    public:
        Ball();
    
        void update();
        void draw();
        bool collide;
        void toggleCollide();
        ofPoint pos;
        ofVec2f vel, acc;
};