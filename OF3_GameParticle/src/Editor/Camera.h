#pragma once
#include "ofMain.h"

enum Cam {
	velocity = 8,
	edge = 120
};

class Camera {
	private:
		ofVec2f position, bgSize;
		float maxX, maxY, minX, minY;
	public:
		void init(ofImage& background);
		void update(float secs);
		ofVec2f getPosition() const;
};