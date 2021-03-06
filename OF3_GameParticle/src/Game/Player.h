#pragma once
#include "GameObject.h"

class Player : public GameObject {
	private:
		ofVec2f position;
		int life;
	public:
		Player(const ofVec2f& centerPos);
		void init();
		void update(float secs, const ofVec2f& camera);
		void draw(const ofVec2f &camera);
		bool isAlive();
		void collidedWith(GameObject* other);
		void setLimits(const ofVec2f& background);
		ofRectangle bounds();
		const ofVec2f getPosition() const;
		const ofVec2f getHandPosition() const;
};