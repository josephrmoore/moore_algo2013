#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    mReceiver2.setup( 12346 );
    mReceiver3.setup( 12347 );
    mReceiver4.setup( 12348 );
    mSender2.setup( "localhost", 12345 );
    mSender3.setup( "localhost", 12349 );
    mSender4.setup( "localhost", 12340 );

    pos.set( ofGetWindowSize() /2 );
    mousePos.set( ofGetWindowSize() /2 );
    
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    
    pos += vel;
    
    if( pos.x < 0 ){ pos.x = ofGetWindowWidth()*2; }
    else if( pos.x > ofGetWindowWidth()*2 ){ pos.x = 0; }
    
    if( pos.y < 0 ){ pos.y = ofGetWindowHeight()*2; }
    else if( pos.y > ofGetWindowHeight()*2 ){ pos.y = 0; }
    
    vel *= 0.97;
    
    // send out bg color information
    ofxOscMessage m;
    m.setAddress("/bgColor");
    m.addIntArg( bgColor );
    mSender2.sendMessage(m);
    mSender3.sendMessage(m);
    mSender4.sendMessage(m);

    // send ball position
    ofxOscMessage mPos;
    mPos.setAddress("/ball/pos");
    mPos.addFloatArg( pos.x );
    mPos.addFloatArg( pos.y );
    mSender2.sendMessage(mPos);
    mSender3.sendMessage(mPos);
    mSender4.sendMessage(mPos);
}

void testApp::checkOsc() {
    
	// check for waiting messages
	while(mReceiver2.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		mReceiver2.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/mouse/pos" ){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
//            mousePos.set( xPos, yPos );
        }else if( addr == "/vel" ){
            cout << "got vel" << endl;
            
            int xVel = m.getArgAsFloat(0);
            int yVel = m.getArgAsFloat(1);
            
            vel.set( xVel, yVel );
        }else if( addr == "/bgColor" ){
            float bg = m.getArgAsFloat(0);
            bgColor = floor(bg * 255.0);
            
            ofBackground( bgColor );
        }
    }
    // check for waiting messages
	while(mReceiver3.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		mReceiver3.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/mouse/pos" ){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            //            mousePos.set( xPos, yPos );
        }else if( addr == "/vel" ){
            cout << "got vel" << endl;
            
            int xVel = m.getArgAsFloat(0);
            int yVel = m.getArgAsFloat(1);
            
            vel.set( xVel, yVel );
        }else if( addr == "/bgColor" ){
            float bg = m.getArgAsFloat(0);
            bgColor = floor(bg * 255.0);
            
            ofBackground( bgColor );
        }
    }
    // check for waiting messages
	while(mReceiver4.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		mReceiver4.getNextMessage(&m);
        
        string addr = m.getAddress();
        
        if( addr == "/mouse/pos" ){
            int xPos = m.getArgAsInt32(0);
            int yPos = m.getArgAsInt32(1);
            
            //            mousePos.set( xPos, yPos );
        }else if( addr == "/vel" ){
            cout << "got vel" << endl;
            
            int xVel = m.getArgAsFloat(0);
            int yVel = m.getArgAsFloat(1);
            
            vel.set( xVel, yVel );
        }else if( addr == "/bgColor" ){
            float bg = m.getArgAsFloat(0);
            bgColor = floor(bg * 255.0);
            
            ofBackground( bgColor );
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofPushMatrix();
//    ofTranslate( ofGetWindowWidth(), 0);
    ofCircle( pos, 20 );
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    vel.set( ofRandom(-30,30), ofRandom(-30,30));
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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
