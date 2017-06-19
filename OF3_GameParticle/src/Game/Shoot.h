#pragma once
#include "GameObject.h"

class Shoot : public GameObject {
	private:
		ofVec2f position;
		ofVec2f direction;
		ofVec2f destination;
	public:
		Shoot(const ofVec2f& position, const ofVec2f& camera);
		void init();
		void update(float secs, const ofVec2f& camera);
		void draw(const ofVec2f &camera);
		bool isAlive();
		void collidedWith(GameObject* other);
		ofRectangle bounds();
};