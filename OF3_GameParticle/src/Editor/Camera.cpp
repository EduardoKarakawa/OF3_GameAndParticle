#include "Camera.h"

void Camera::init(ofImage& background) {
	screen_center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

	maxX = background.getWidth() - ofGetWidth();
	maxY = background.getHeight() - ofGetHeight();
	position.set(screen_center);
}

void Camera::update(float secs) {

	float temp = 0;
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	if (mouse.x < edge) {
		position.x += velocity;
	}
	//dando mais ou menos certo
	else if (mouse.x > ofGetWidth() - edge) {
		position.x -= velocity;
	}

	if (mouse.y < edge) {
		position.y += velocity;
	}
	//dando mais ou menos certo
	else if (mouse.y > ofGetHeight() - edge) {
		position.y -= velocity;
	}
}

ofVec2f Camera::getPosition() const {
	return position;
}

ofVec2f Camera::getCenterPos() const {
	return screen_center;
}