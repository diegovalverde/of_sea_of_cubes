#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::randomizeGrid(){
    for (int i = 0; i < mGridSize; ++i){
        for (int j = 0; j < mGridSize; ++j){
            
            if (ofRandom(0,1) > 0.8){
                mGrid[i][j].mAlive = true;
                mGrid[i][j].mColor[3] = 255;
            }else{
                mGrid[i][j].mAlive = false;
                mGrid[i][j].mColor[3] = 0;
            }
        }
    }
}
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetColor(255);
    
    //randomizeGrid();
    
    mGrid[0][0].mAlive = true; mGrid[0][2].mAlive = true; mGrid[0][4].mAlive = true;
    mGrid[1][0].mAlive = true; mGrid[1][2].mAlive = false; mGrid[1][4].mAlive = true;
    mGrid[2][0].mAlive = true; mGrid[2][2].mAlive = false; mGrid[2][4].mAlive = true;
    mGrid[3][0].mAlive = true; mGrid[3][2].mAlive = false; mGrid[3][4].mAlive = true;
    mGrid[4][0].mAlive = true; mGrid[4][2].mAlive = true; mGrid[4][4].mAlive = true;
    
    
   

}
//--------------------------------------------------------------
int ofApp::getNumberOfNeighbors( int row, int col ){
    
    int count = 0;
    
    if ( row < mGridSize-1 && col < mGridSize-1 && mGrid[row+1][col+1].mAlive )
        count++;
    
    if ( row < mGridSize-1 && mGrid[row+1][col].mAlive )
        count++;
    
    if ( col < mGridSize-1 && mGrid[row][col+1].mAlive )
        count++;
    
    if ( row > 0 && col > 0 && mGrid[row-1][col-1].mAlive )
        count++;
    
    if ( row > 0 && mGrid[row-1][col].mAlive )
        count++;
    
    if ( col > 0 && mGrid[row][col-1].mAlive )
        count++;
    
    return count;
}
//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() % 100 != 0)
        return;
    
    for (int i = 0; i < mGridSize; ++i){
        for (int j = 0; j < mGridSize; ++j){
            
            
            int nCount = getNumberOfNeighbors(i, j);
            auto & cube = mGrid[i][j];
            if (cube.mAlive){
                
                if (cube.mColor[3] < 255){
                    cube.mColor[3]++;
                }
                
                if (nCount <= 1 || nCount >= 4){
                    if (ofRandom(10) < 1)
                        cube.mAlive = false;
                }
                if (nCount == 3){
                    cube.mColor[0] = (cube.mColor[0] + 1) % 255;
                }
            } else {
                if (cube.mColor[3] > 0){
                    cube.mColor[3]--;
                }
                
                if (nCount == 3){
                    cube.mAlive = true;
                    cube.mColor[3] = 1;
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    mCamera.begin();
    
    float inititialX = -100; //ofGetScreenWidth()/2-mGridSize/2;
    ofVec3f pos(inititialX, -100,0);//ofGetScreenHeight()/2+mGridSize/2,0);
    mCamera.setPosition(0, 0, 500);
    
    for (int i = 0; i < mGridSize; ++i){
        pos.x = inititialX;
        for (int j = 0; j < mGridSize; ++j){
            auto & box = mGrid[i][j];
            
            if (true){//box.mAlive){
                
                ofSetColor(box.mColor);
                int sign = (ofRandom(1)) ? -1 : 1;
                pos.z += sign * sin(ofGetFrameNum()*i*0.001);
                ofDrawBox(pos, mCellSize, mCellSize, mCellSize);
            }
            pos.x += mCellSize;
        }
        pos.y += mCellSize;
    }
    
    mCamera.end();

}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    randomizeGrid();
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
