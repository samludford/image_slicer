#pragma once

#include "ofMain.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        float adjustment {200};
        int slice_count {6};
    
        ofImage me;
        ofImage mirror_me;
    
        ofImage one;
        ofImage one_mirrored;
    
        ofVideoGrabber grabber;
    
        ofVideoPlayer player;
    
        int mode {1};
		
};
