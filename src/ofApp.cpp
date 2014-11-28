#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(100);
	ps = new ParticleSystem(ofVec3f(0,0,0));
}

//--------------------------------------------------------------
void ofApp::update(){
	ps->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
	ofBackground(200);
	ofSetColor(0);
	cam.begin();
	ps->draw();
    ofDrawAxis(60);
	cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key==356){
        // left arrow
		if(ps->model==0)  ps->force = ofVec3f(-500,0,0);
		else ps->force = ofVec3f(-1000,0,0);
    }
	else if(key==357){
        // Up arrow
		if(ps->model==0)  ps->force = ofVec3f(0,0,-500);
		else ps->force = ofVec3f(0,0,-1000);
    }
    else if( key==358){
        // right arrow
		if(ps->model==0)  ps->force = ofVec3f(500,0,0);
		else ps->force = ofVec3f(1000,0,0);
    }
	else if( key==359){
        // down arrow
        if(ps->model==0)  ps->force = ofVec3f(0,0,500);
		else ps->force = ofVec3f(0,0,1000);
    }
	else if(key==32){
        //Space
         if(ps->model==0)  ps->force = ofVec3f(0,-500,0);
		else ps->force = ofVec3f(0,-1000,0);
    }
	else if(key==50){
		ps->initClothDistance();
	}
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
