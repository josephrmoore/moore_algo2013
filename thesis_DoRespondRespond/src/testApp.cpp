#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    t.setLimit(2000);
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    p1.active = true;
    loop_counter = 1;
    for(int i=0; i<TOTAL_LOOPS; i++){
        vector<TimePoint>   pointList;
        loops.push_back(pointList);
        vector<TimePoint>   hitList;
        hits.push_back(hitList);
    }
    playbackStartTime = ofGetElapsedTimef();
    
    // ofxMidi stuff
    
    // print the available output ports to the console
	midiOut.listPorts(); // via instance
	//ofxMidiOut::listPorts(); // via static too
	
	// connect
	midiOut.openPort(0);	// by number
	//midiOut.openPort("IAC Driver Pure Data In");	// by name
	//midiOut.openVirtualPort("ofxMidiOut");		// open a virtual port
	
	channel = 1;
	currentPgm = 0;
	note = 0;
	velocity = 0;
	pan = 0;
	bend = 0;
	touch = 0;
	polytouch = 0;
}

//--------------------------------------------------------------
void testApp::exit() {
	
	// clean up
	midiOut.closePort();
}


//--------------------------------------------------------------
void testApp::update(){
    t.update();
    // startTime is reset every time we press the mouse, so we're recornding the time since we've pressed the mouse
    
    if(t.activate == true){
        t.reset();
        startTime = ofGetElapsedTimef();
        playbackStartTime = ofGetElapsedTimef();
        // action to perform on timer rollover
        if(p1.active == false){
            p1.active = true;
            p2.active = false;
        } else {
            p1.active = false;
            p2.active = true;
        }
        if(loop_counter>=TOTAL_LOOPS){
            loop_counter = 1;
            for(int i=0; i<hits.size(); i++){
                for(int j=0; j<hits[i].size(); j++){
                    hits[i][j].played = false;
                }
            }
        } else {
            loop_counter+=1;
        }
//        if(loops[loop_counter-1].size()>0){
//            loops[loop_counter-1].clear();
//        }
        cout<<playbackStartTime<<endl;
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    if(p1.active){
        ofBackground(100);
    }
    if(p2.active){
        ofBackground(255);
    }
    // -------------------------- draw the line
	ofSetColor(0,0,0);
	ofNoFill();
    t.metronome();
    for( vector<vector <TimePoint> >::iterator it=loops.begin(); it!=loops.end(); it++ ){
        ofBeginShape();
        for( vector<TimePoint>::iterator it2=it->begin(); it2!=it->end(); it2++ ){
            ofVertex( it2->x, it2->y );
        }
        ofEndShape();
        
    }
    
    string keys = "";
    for(int i=0; i<TOTAL_LOOPS; i++){
        if(i==loop_counter-1){
            ofPoint pos = getPos(ofGetElapsedTimef() - playbackStartTime, loops[i]);
            // x pos controls the pan (ctl = 10)
            pan = ofMap(pos.x, 0, ofGetWidth(), 0, 127);
            midiOut.sendControlChange(channel, 10, pan);
            
            // y pos controls the pitch bend
            bend = ofMap(pos.y, 0, ofGetHeight(), 0, MIDI_MAX_BEND);
            midiOut.sendPitchBend(channel, bend);
            ofFill();
            ofSetColor(255,0,0);
            ofCircle(pos.x, pos.y, 10);
            for( int j=0; j<getKeys(ofGetElapsedTimef() - playbackStartTime, hits[i]); j++){
                keys += ofToString(hits[i][j].key);
                keys += " ";
                // send a note on if the key is a letter or a number
                if(isalnum((unsigned char) hits[i][j].key) && !hits[i][j].played) {
                    
                    // scale the ascii values to midi velocity range 0-127
                    // see an ascii table: http://www.asciitable.com/
                    note = ofMap(hits[i][j].key, 48, 122, 0, 127);
                    velocity = 64;
                    midiOut.sendNoteOn(channel, note,  velocity);
                    hits[i][j].played=true;
                }
            }
        }
//        getKeys(ofGetElapsedTimef() - playbackStartTime, hits[i]);
    }
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString(keys, 220, 20);
    ofPopStyle();
    
    
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString(ofToString(loop_counter), 20, 20);
    ofPopStyle();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
//    if(p1.active){
//        cout<<"p1"<<endl;
//    }
//    if(p2.active){
//        cout<<"p2"<<endl;
//    }
//    if(hits[loop_counter-1].size()>0){
//        hits[loop_counter-1].clear();
//    }
    TimePoint temp;
	temp.key = key;
	temp.t = ofGetElapsedTimef() - startTime;
	hits[loop_counter-1].push_back(temp);
    // send a note on if the key is a letter or a number
	if(isalnum((unsigned char) key)) {
        
		// scale the ascii values to midi velocity range 0-127
		// see an ascii table: http://www.asciitable.com/
		note = ofMap(key, 48, 122, 0, 127);
		velocity = 64;
		midiOut.sendNoteOn(channel, note,  velocity);
	}
	
	if(key == 'l') {
		ofxMidiOut::listPorts();
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
 	TimePoint temp;
	temp.x = mouseX;
	temp.y = mouseY;
	temp.t = ofGetElapsedTimef() - startTime;
	loops[loop_counter-1].push_back(temp);
 	// x pos controls the pan (ctl = 10)
	pan = ofMap(x, 0, ofGetWidth(), 0, 127);
	midiOut.sendControlChange(channel, 10, pan);
	
	// y pos controls the pitch bend
	bend = ofMap(y, 0, ofGetHeight(), 0, MIDI_MAX_BEND);
	midiOut.sendPitchBend(channel, bend);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    // reset all of our points
	
	bIsRecording = true;
    if(loops[loop_counter-1].size()>0){
	loops[loop_counter-1].clear();
    }
	TimePoint temp;
	temp.x = x;
	temp.y = y;
	temp.t = 0;
	loops[loop_counter-1].push_back(temp);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	bIsRecording = false;
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


//--------------------------------------------------------------
ofPoint testApp::getPositionForTime(float time){
	
	// are we recording or do we have less than 2 points? If so return a blank placeholder point.
	if (bIsRecording == true){
		return ofPoint(0,0,0);
	} else if (pointList.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// Now we figure out where we are time-wise in the drawing
	
    // The variable "time" we are passing in is relative to how long the program has been running, not relative to
    // our timeframe.  We essentially need a modulus operator (%).  Instead we'll mimic is.
    
    // This function acts like a big modulus. The last element in our list (pointList.size()-1) is how long the whole drawing took.
    // We'll keep subtracting it from time until it's smaller than "time".  Now we can work with it on the right time scale. This also
    // allows it to loop!
    
	while (time > pointList[pointList.size()-1].t){
		time -= pointList[pointList.size()-1].t;
	}
	
	
    // Create our point we'll return
	ofPoint pos;
	
	for (int i = 0; i < pointList.size()-1; i++){
        
        // find out which two points we're between
		if (time >= pointList[i].t && time < pointList[i+1].t){
			
			// Since we want a smooth playback, we'll interpolate between these two points
			float part = time - pointList[i].t;
			float whole = pointList[i+1].t - pointList[i].t;
			float pct = part / whole;
			
			// Figure out where we are between a and b
            // We've done this before with our linear interpolation where we take a percentage of both, where both
            // percentages add up to 100.  We do this by taking "pct" from one of them and "1-pct" from the other.
			pos.x = (1-pct) * pointList[i].x + (pct) * pointList[i+1].x;
			pos.y = (1-pct) * pointList[i].y + (pct) * pointList[i+1].y;
		}
	}
	
    // return our point which represents a position interpolated between two other points
	return pos;
}

//--------------------------------------------------------------
ofPoint testApp::getPos(float time, vector<TimePoint> t){
	
	// are we recording or do we have less than 2 points? If so return a blank placeholder point.
	if (bIsRecording == true){
		return ofPoint(0,0,0);
	} else if (t.size() < 2){
		return ofPoint(0,0,0);
	}
	
	// Now we figure out where we are time-wise in the drawing
	
    // The variable "time" we are passing in is relative to how long the program has been running, not relative to
    // our timeframe.  We essentially need a modulus operator (%).  Instead we'll mimic is.
    
    // This function acts like a big modulus. The last element in our list (pointList.size()-1) is how long the whole drawing took.
    // We'll keep subtracting it from time until it's smaller than "time".  Now we can work with it on the right time scale. This also
    // allows it to loop!
    
	while (time > t[t.size()-1].t){
		time -= t[t.size()-1].t;
	}
	
	
    // Create our point we'll return
	ofPoint pos;
	
	for (int i = 0; i < t.size()-1; i++){
        
        // find out which two points we're between
		if (time >= t[i].t && time < t[i+1].t){
			
			// Since we want a smooth playback, we'll interpolate between these two points
			float part = time - t[i].t;
			float whole = t[i+1].t - t[i].t;
			float pct = part / whole;
			
			// Figure out where we are between a and b
            // We've done this before with our linear interpolation where we take a percentage of both, where both
            // percentages add up to 100.  We do this by taking "pct" from one of them and "1-pct" from the other.
			pos.x = (1-pct) * t[i].x + (pct) * t[i+1].x;
			pos.y = (1-pct) * t[i].y + (pct) * t[i+1].y;
		}
	}
	
    // return our point which represents a position interpolated between two other points
	return pos;
}


//--------------------------------------------------------------
int testApp::getKeys(float time, vector<TimePoint> t){
	
	// are we recording or do we have less than 2 points? If so return a blank placeholder point.
	if (t.size() < 1){
		return 0;
	}
	
	// Now we figure out where we are time-wise in the drawing
	
    // The variable "time" we are passing in is relative to how long the program has been running, not relative to
    // our timeframe.  We essentially need a modulus operator (%).  Instead we'll mimic is.
    
    // This function acts like a big modulus. The last element in our list (pointList.size()-1) is how long the whole drawing took.
    // We'll keep subtracting it from time until it's smaller than "time".  Now we can work with it on the right time scale. This also
    // allows it to loop!
    
	while (time > t[t.size()-1].t){
		time -= t[t.size()-1].t;
	}
	
	
    // Create our point we'll return
	int index;
	index = 0;
	for (int i = 0; i < t.size()-1; i++){
        // find out which two points we're between
		if (time >= t[i].t && time < t[i+1].t){
            index = i;
			// Since we want a smooth playback, we'll interpolate between these two points
//			float part = time - t[i].t;
//			float whole = t[i+1].t - t[i].t;
//			float pct = part / whole;
			// Figure out where we are between a and b
            // We've done this before with our linear interpolation where we take a percentage of both, where both
            // percentages add up to 100.  We do this by taking "pct" from one of them and "1-pct" from the other.
//			pos.x = (1-pct) * t[i].x + (pct) * t[i+1].x;
//			pos.y = (1-pct) * t[i].y + (pct) * t[i+1].y;
		}
        cout<<index<<endl;
	}
    // return our point which represents a position interpolated between two other points
	return index;
}
