#pragma once
#include "ofMain.h"

enum Cam {
	velocity = 8,
	edge = 120
};

class Camera {
	private: 
		ofVec2f position, center;
		ofVec2f bgSize;
		float maxX, maxY, minX, minY;

	public:
		void init(const ofVec2f& background);
		void init(ofImage& background);
		void update(float secs);
		void update(const ofVec2f& player);
		const ofVec2f getPosition() const;
};