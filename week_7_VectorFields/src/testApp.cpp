#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myField.setup( ofGetWindowWidth(), ofGetWindowHeight(), 20 );
    
    ofBackground(0);
    state = 0;
    xml.loadFile("settings.xml");
    state = xml.getValue("settings:state", 0.0);
    if( state == 1){
        myField.setRandom();
    }else if( state == 2 ){
        myField.setPerlin();
    }else if( state == 3 ){
        myField.setSin();
    }else if( state == 4 ){
        myField.setCorner(true,true);
    }
    else if( state == 5 ){
        myField.setCorner(true,false);
    }
    else if( state == 6 ){
        myField.setCorner(false,true);
    }
    else if( state == 7 ){
        myField.setCorner(false,false);
    }
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw(){
    myField.draw();
}

//--------------------------------------------------------------
void testApp::exit(){
    xml.setValue("settings:state", state);
    xml.saveFile("settings.xml");
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if( key == '1'){
        myField.setRandom();
        state = 1;
    }else if( key == '2' ){
        myField.setPerlin();
        state = 2;
    }else if( key == '3' ){
        myField.setSin();
        state = 3;
    }else if( key == 'q' ){
        myField.setCorner(true,true);
        state = 4;
    }
    else if( key == 'w' ){
        myField.setCorner(true,false);
        state = 5;
    }
    else if( key == 'a' ){
        myField.setCorner(false,true);
        state = 6;
    }
    else if( key == 's' ){
        myField.setCorner(false,false);
        state = 7;
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
