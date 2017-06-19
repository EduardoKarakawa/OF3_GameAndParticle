#include "Shoot.h"

Shoot::Shoot(const ofVec2f& position, const ofVec2f& camera) : position(position) {
	destination.set(ofGetMouseX(), ofGetMouseY());
	direction = ((destination - position) + camera).normalize();
}

void Shoot::init() {
	
}
void Shoot::update(float secs, const ofVec2f& camera) {
	float speed = 350.0f;
	//destination += camera;
	position += direction * speed * secs;
}

void Shoot::draw(const ofVec2f &camera) {
	ofSetColor(ofColor::blueViolet);
	ofDrawCircle(position - camera, 5);
	ofSetColor(ofColor::white);
}

bool Shoot::isAlive() {
	return true;
}

void Shoot::collidedWith(GameObject* other) {

}

ofRectangle Shoot::bounds() {
	return ofRectangle(position, 5, 5);
}