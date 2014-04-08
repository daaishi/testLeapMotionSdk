#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    ofEnableAlphaBlending();
    ofEnableLighting();
    
    light1.setPosition(500, 300, 800);
    light2.setPosition(-500, -200, 800);
    
    cam.setOrientation(ofVec3f(0.0, 0.0, 0.0));
    cam.setDistance(1000);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    string touchStatus;
    stringstream info;
    
    cam.begin();
    
    ofDrawGrid(500, 5, true);
    
    light1.enable();
    light2.enable();
    
    ofSetColor(255, 215, 0);
    Frame frame = controller.frame();
    for (int i=0; i < frame.hands().count(); i++) {
        Hand hand = frame.hands()[i];
        for (int j = 0; j < hand.fingers().count(); j ++) {
            if (j == 0) {
                Finger finger = frame.fingers()[j];
                ofSpherePrimitive sphere;
                sphere.setPosition(finger.tipPosition().x, finger.tipPosition().y, finger.tipPosition().z);
                sphere.draw();
                info << "Finger position x : " << finger.tipPosition().x << " y : " << finger.tipPosition().y <<  " z : " << finger.tipPosition().z << endl;
            }
        }
    }
    cam.end();
    
    
    PointableList pointables = controller.frame().pointables();
    InteractionBox iBox = controller.frame().interactionBox();
    for (int p = 0; p < pointables.count(); p++) {
        Pointable pointable = pointables[p];
        Vector normalizedPosition = iBox.normalizePoint(pointable.stabilizedTipPosition());
        float x = normalizedPosition.x * ofGetWidth();
        float y = ofGetHeight() - normalizedPosition.y * ofGetHeight();
        
        if (pointable.touchDistance() > 0 && pointable.touchZone() != Leap::Pointable::ZONE_NONE) {
            ofSetColor(0, 255, 0);
            touchStatus = "Hover";
        } else if (pointable.touchDistance() <= 0) {
            ofSetColor(255, 0, 0);
            touchStatus = "Touch";
        } else {
            ofSetColor(0, 0, 255);
            touchStatus = "None";
        }
        ofCircle(x, y, 30);
        info << "Point Number : " << p << endl;
        info << "Touch distance : " << ofToString(pointable.touchDistance()) << endl;
        info << "Circle x : " << x << " y : " << y << endl;
    }
    
    ofDrawBitmapString("Touch Status : " + touchStatus, 20, 20);
    ofDrawBitmapString(info.str(), 20, 40);
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

void ofApp::exit() {
    
}