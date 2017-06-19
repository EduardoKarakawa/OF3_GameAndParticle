#pragma once
#include "ofMain.h"
#include "Player.h"
#include "Camera.h"

class Game {
	private:
		ofImage background;
		ofSoundPlayer sound;
		Camera camera;
		Player* player;
	public:
		void init();
		void update(float secs);
		void draw();
};