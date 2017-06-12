#include "Camera.h"

void Camera::init(ofImage& background) {
	maxX = background.getWidth() / 2 - ofGetWidth();
	maxY = background.getHeight() / 2 - ofGetHeight();
	minX = -background.getWidth() / 2;
	minY = -background.getHeight() / 2;
	position.set(0,0);
}

void Camera::update(float secs) {
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	if (mouse.x < edge) {
		position.x -=  velocity;
		if (position.x < minX)
			position.x = minX;
	}
	//dando mais ou menos certo
	else if (mouse.x >= ofGetWidth() - edge) {
		position.x += velocity;
		if (position.x > maxX)
			position.x = maxX;
	}

	if (mouse.y < edge) {
		position.y -= velocity;
		if (position.y < minY)
			position.y = minY;
	}
	//dando mais ou menos certo
	else if (mouse.y > ofGetHeight() - edge) {
		position.y += velocity;
		if (position.y > maxY)
			position.y = maxY;
	}
}

ofVec2f Camera::getPosition() const {
	return position;
}