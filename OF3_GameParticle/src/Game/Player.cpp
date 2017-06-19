#include "Player.h"
#include "Shoot.h"
#include "GameManager.h"

Player::Player(const ofVec2f& centerPos) : position(centerPos) {}

void Player::init() {
	//position.set(ofGetWidth() / 2, ofGetHeight() - 200);
	life = 10;
}

void Player::update(float secs, const ofVec2f& camera) {
	float speed = 300.0f;
	if (ofGetKeyPressed('d') || ofGetKeyPressed('D')) {
		position.x += speed * secs;
	}
	else if (ofGetKeyPressed('a') || ofGetKeyPressed('A')) {
		position.x -= speed * secs;
	}
	if (ofGetKeyPressed('w') || ofGetKeyPressed('W')) {
		position.y -= speed * secs;
	}
	else if (ofGetKeyPressed('s') || ofGetKeyPressed('S')) {
		position.y += speed * secs;
	}
	
}

void Player::draw(const ofVec2f &camera) {
	ofSetColor(ofColor::red);
	ofDrawCircle(position - camera, 10);
	ofSetColor(ofColor::white);
}

bool Player::isAlive() {
	if (life <= 0) {
		return false;
	}
	return true;
}

void Player::collidedWith(GameObject* other) {

}

void Player::setLimits(const ofVec2f & background) {
	if (position.x > background.x) {
		position.x = background.x;
	}
	else if (position.x < 0) {
		position.x = 0;
	}
	if (position.y > background.y) {
		position.y = background.y;
	}
	else if (position.y < 0) {
		position.y = 0;
		}
}

ofRectangle Player::bounds() {
	return ofRectangle(position, 10, 10);
}

const ofVec2f Player::getPosition() const {
	return position;
}

const ofVec2f Player::getHandPosition() const {
	return ofVec2f(position.x + 5, position.y + 5);
}
