#pragma once

#include "ofMain.h"
#include "Leap.h"

using namespace Leap;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    void exit();
    
    Controller controller;
    
    ofEasyCam cam;
    ofLight light1, light2;
    
    ofMaterial material1;
};
