//
//  TimePoint.h
//  DoRespondRespond
//
//  Created by Joseph Moore on 12/7/13.
//
//

#pragma once

#include "ofMain.h"

class TimePoint {
public:
    TimePoint(){
//        cout << "Constructed!" << endl;
    };
    ~TimePoint(){
//        cout << "Denstructed!" << endl;
    }
    ;
    
    float x, y;
    float t;
    int key;
};
