#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(100);
    ofEnableAlphaBlending();
    
    ofHideCursor();
    
    ofBackground(255);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    diffx = mouseX - ofGetWidth()/2;
    diffy = mouseY - ofGetHeight()/2;
    tan = diffy/diffx;
    arctan = atan(tan);
    angle =  (180*arctan)/PI;
    
    if (diffx >= 0 && diffy <= 0) {
        angle = abs(angle);
    } else if (diffx <= 0 && diffy <= 0) {
        angle = 180 - angle;
    } else if (diffx <= 0 && diffy >= 0) {
        angle = 180 + abs(angle);
    } else if (diffx >= 0 && diffy >= 0) {
        angle = abs(angle - 90) + 270;
    }
    
       
    color = angle*255/360;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(140);
    for (float i = 0; i < 30; i++){
        ofLine(i * (ofGetWidth()/30), 0, i * (ofGetWidth()/30), ofGetHeight());
    }
    
    for (float j = 0; j < 20; j++){
        ofLine(0, j * (ofGetHeight()/20), ofGetWidth(), j * (ofGetHeight()/20));
    }
    
    ofSetColor(100);
    ofLine(0, mouseY, ofGetWidth(), mouseY);
    ofLine(mouseX, 0, mouseX, ofGetHeight());
    
    ofSetColor(ofColor::fromHsb(color, 255, 255, 180));
    ofLine(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY);
    
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        diff = abs(ofDist(ofGetWidth()/2, ofGetHeight()/2, mouseX, mouseY));
    
        ofFill();
        ofCircle(0, 0, diff/4);
    
        ofNoFill();
        ofCircle(0, 0, diff);
    ofPopMatrix();
    
    /*
    ofSetColor(20);
    ofDrawBitmapString(ofToString(angle), mouseX, mouseY);
    ofDrawBitmapString(ofToString(color), mouseX, mouseY - 20);
    */
     
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
