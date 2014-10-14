#include "ofApp.h"

ofIndexType id = 0;

ofMesh box;

//--------------------------------------------------------------
void ofApp::setup()
{
    shader.load("vertexShader.vert", "fragmentShader.frag");
    camera.setPosition(100, 100, 100);
    camera.lookAt(ofVec3f(0, 0, 0));

    branch.init(ofPoint(0, 0, 0));
}

//---------------------------------------------------------------
void ofApp::update()
{
    branch.update();
}

//--------------------------------------------------------------
void ofApp::draw()
{

    ofBackground(ofColor(0));

    shader.begin();
    camera.begin();

    //グリッドの猫写
    //ofDrawGrid();

    ofSetColor(ofColor::white);
    branch.drawWireframe();

    camera.end();
    shader.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
