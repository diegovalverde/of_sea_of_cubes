#pragma once

#include "ofMain.h"

class Cube {
    public:
        ofColor mColor;       /// Color
        int mSize = 5;        /// Size of the cube
        bool mAlive = false;
    
    public:
    Cube() : mColor( 0, ofRandom(100,255), ofRandom(100,255), 128 ),
    mSize(5){}
    
    
};

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
    
    public:
        ofEasyCam mCamera;
        const int mCellSize = 10;
        const int mGridSize = 100;
        ofApp() : mGrid(mGridSize, vector<Cube>(mGridSize)) {}
    
        void randomizeGrid();
    
        vector<vector<Cube>> mGrid;
    
        int getNumberOfNeighbors( int r, int c );
		
};
