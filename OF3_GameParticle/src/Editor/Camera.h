#pragma once
#include "ofMain.h"

enum Cam {
	velocity = 8,
	edge = 120
};

class Camera {
	private:
		ofVec2f screen_center;
		ofVec2f position;
		float maxX, maxY;
	public:
		void init(ofImage& background);
		void update(float secs);
		ofVec2f getPosition() const;
		ofVec2f getCenterPos() const;
};