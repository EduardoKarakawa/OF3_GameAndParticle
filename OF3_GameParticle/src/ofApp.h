#pragma once

#include "ofMain.h"
#include "Game/GameStats.h"
#include "Game/GameTime.h"
#include "Game/Player.h"
#include "Game/Bullet.h"
#include "Game/EnemyControl.h"
#include "Game/Menu.h"
#include "Editor/ParticleEditor.h" 

class ofApp : public ofBaseApp{
private:
	Player *gamePlayer;
	GameStats *gameStats;
	GameTime *gameTime;
	vector<Bullet*> bulletP;
	EnemyControl *enemys;
	int startTime; //Para comecer a contar o tempo do zero
	ParticleEditor partEditor;
	Menu menu;	// Class que gerencia o menu

	public:
		//Gui* gui;

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
