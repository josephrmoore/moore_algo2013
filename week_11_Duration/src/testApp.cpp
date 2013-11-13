#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    bk = ofColor(0);
    ofBackground(bk);
    receiver.setup( 12345 );
    for(int i=0; i<160; i++){
        Particle p;
        balls.push_back(p);
    }
    glEnable(GL_DEPTH);
}

//--------------------------------------------------------------
void testApp::update(){
    checkOsc();
    ofBackground(bk);
}

//--------------------------------------------------------------
void testApp::draw(){
    for(int i=0; i<balls.size(); i++){
        balls[i].draw();
    }
}

void testApp::checkOsc() {
    
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        cout<<m.getAddress()<<endl;
        if(m.getAddress() == "/hightension.wav"){
            float r, g, b;
            float x, y, z;
            string addr = m.getAddress();
            for(int i=0; i<m.getNumArgs(); i++){
                if(i<m.getNumArgs()/3){
                    r += m.getArgAsFloat(i);
                    x = m.getArgAsFloat(i);
                    y = 0;
                    z = 0;
                    balls[i].pos+=(ofVec3f(x*5,y*10,z*10));
                    balls[i].update();
                } else if (i>m.getNumArgs()/3*2){
                    g += m.getArgAsFloat(i);
                    x = 0;
                    y = m.getArgAsFloat(i);
                    z = 0;
                    balls[i].pos+=(ofVec3f(x*10,y*20,z*10));
                    balls[i].update();
                } else {
                    b += m.getArgAsFloat(i);
                    x = 0;
                    y = 0;
                    z = m.getArgAsFloat(i);
                    balls[i].pos+=(ofVec3f(x*10,y*10,z*50));
                    balls[i].update();
                }
            }
            
            r = ofClamp(ofMap(r, 0, m.getNumArgs()/3/1.2, 0, 255),0,255);
            g = ofClamp(ofMap(g, 0, m.getNumArgs()/3/4, 0, 255),0,255);
            b = ofClamp(ofMap(b, 0, m.getNumArgs()/3/5, 0, 255),0,255);
            bk = ofColor(r,g,b);
        } else if(m.getAddress() == "/colors"){
            // change colors of particles
            for(int i=0; i<balls.size(); i++){
                balls[i].color = ofColor(m.getArgAsInt32(0),m.getArgAsInt32(1),m.getArgAsInt32(2));
            }
        } else if (m.getAddress() == "/duration/info"){
            // read this to see what it is
        } else if (m.getAddress() == "/radius"){
            for(int i=0; i<balls.size(); i++){
                balls[i].radius.y = m.getArgAsFloat(0)*300+10;
            }
        } else if (m.getAddress() == "/z"){
            for(int i=0; i<balls.size(); i++){
                balls[i].radius.x = m.getArgAsFloat(0)*200+10;
            }
        }


//
////        cout<<r<<" "<<g<<" "<<b<<endl;
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
