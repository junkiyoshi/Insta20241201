#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);

	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int width = 90;
	int height = 90;
	int len = 5;

	for (int x = -100; x <= 100; x += 100) {

		for (int y = -100; y <= 100; y += 100) {

			for (int z = 0; z <= 280; z += 15) {

				auto noise_param = ofNoise(x * 0.005, y * 0.005, z * 0.005 + ofGetFrameNum() * 0.05);

				if (noise_param < 0.25) { continue; }

				ofPushMatrix();
				ofTranslate(x, y, z);

				auto alpha = ofMap(z, 0, 280, 0, 255);

				ofFill();
				ofSetColor(ofColor(0, alpha));

				ofBeginShape();

				ofVertex(glm::vec2(width * -0.5, height * -0.5));
				ofVertex(glm::vec2(width * 0.5, height * -0.5));
				ofVertex(glm::vec2(width * 0.5, height * 0.5));
				ofVertex(glm::vec2(width * -0.5, height * 0.5));

				ofNextContour(true);

				ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
				ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
				ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
				ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

				ofEndShape(true);

				ofNoFill();
				ofSetColor(ofColor(255, alpha));

				ofBeginShape();

				ofVertex(glm::vec2(width * -0.5, height * -0.5));
				ofVertex(glm::vec2(width * 0.5, height * -0.5));
				ofVertex(glm::vec2(width * 0.5, height * 0.5));
				ofVertex(glm::vec2(width * -0.5, height * 0.5));

				ofNextContour(true);

				ofVertex(glm::vec2(width * -0.5 + len, height * -0.5 + len));
				ofVertex(glm::vec2(width * 0.5 - len, height * -0.5 + len));
				ofVertex(glm::vec2(width * 0.5 - len, height * 0.5 - len));
				ofVertex(glm::vec2(width * -0.5 + len, height * 0.5 - len));

				ofEndShape(true);

				ofPopMatrix();
			}
		}
	}

	this->cam.end();

	/*
	int start = 50;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}