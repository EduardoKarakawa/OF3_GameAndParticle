#include "Camera.h"

void Camera::init(ofImage& background) {
	screen_center = ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2);

	maxX = background.getWidth() - ofGetWidth();
	maxY = background.getHeight() - ofGetHeight();
}

void Camera::update(float secs) {
	position.set(screen_center);

	float temp = 0;
	ofVec2f mouse = ofVec2f(ofGetMouseX(), ofGetMouseY());
	if (mouse.x < edge) {
		temp = position.x - (edge - mouse.x) * velocity * secs;
		temp < 0 ? position.x = temp : 0;
	}
	//dando mais ou menos certo
	else if (mouse.x > ofGetWidth() - edge) {
		temp = position.x - (ofGetWidth() - edge - mouse.x) * velocity * secs;
		float temp2 = (maxX + position.x);
		temp2 > 0 ? position.x = temp : 0;
	}

	if (mouse.y < edge) {
		temp = position.y + (edge - mouse.y) * velocity * secs;
		temp < 0 ? position.y = temp : 0;
	}
	//dando mais ou menos certo
	else if (mouse.y > ofGetHeight() - edge) {
		temp = position.y + (ofGetHeight() - edge - mouse.y) * velocity * secs;
		float temp2 = (maxY + position.y);
		temp2 > 0 ? position.y = temp : 0;
	}

}

ofVec2f Camera::getPosition() const {
	return position;
}

ofVec2f Camera::getCenterPos() const {
	return screen_center;
}