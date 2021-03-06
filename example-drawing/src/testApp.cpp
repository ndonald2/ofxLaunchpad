#include "testApp.h"

void testApp::setup(){
	// 10 fps is important, otherwise we can overload the device and it will stop
	// updating. it can handle 400 messages per second, and a full grid update
	// is 8x8/2 + 1 = 33 messages. 400 / 33 = 12 fps absolute max.
	ofSetFrameRate(10);
	ofSetVerticalSync(true);	
	launchpad.setup();
}

void testApp::launchpadDraw() {
	ofClear(0, 255);
	float r = ofMap(sin(ofGetElapsedTimef() * 4), -1, 1, 0, 4);
	ofFill();
	ofSetColor(ofColor::green);
	ofCircle(4, 4, r);
	ofNoFill();
	ofSetColor(ofColor::red);
	ofCircle(4, 4, r);
}

void testApp::update(){
	launchpad.begin();
	launchpadDraw();
	launchpad.end();
}

void testApp::draw(){
	launchpad.draw(0, 0);
}
