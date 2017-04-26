#pragma once

#include "ofMain.h"
#include "Game/GameStats.h"
#include "Game/Player.h"
#include "Game/Bullet.h"
#include "Game/Enemy.h"
#include "Game/Menu.h"
#include "Editor/ParticleEditor.h" 



class ofApp : public ofBaseApp{
	private:
		Player *gamePlayer;
		GameStats *gameS;
		ParticleEditor partEditor;
		Menu menu;

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

};
