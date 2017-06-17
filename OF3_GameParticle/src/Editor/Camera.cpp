#include "Camera.h"

void Camera::init(ofImage& background) {
	maxX = background.getWidth() / 2 - ofGetWidth() / 2;
	maxY = background.getHeight() / 2 - ofGetHeight() / 2;
	minX = -background.getWidth() / 2 + ofGetWidth() / 2;
	minY = -background.getHeight() / 2 + ofGetHeight() / 2;
	position.set(0, 0);
	bgSize.set(background.getWidth(), background.getHeight());
}

void Camera::update(float secs) {
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());

	if (bgSize.x >= ofGetWidth()) {
		if (mouse.x < edge) {
			position.x -= velocity;
			if (position.x < minX)
				position.x = minX;
		}
		//dando mais ou menos certo
		else if (mouse.x >= ofGetWidth() - edge) {
			position.x += velocity;
			if (position.x > maxX)
				position.x = maxX;
		}
	}


	if (bgSize.y >= ofGetHeight()) {
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
}

ofVec2f Camera::getPosition() const {
	return position;
}