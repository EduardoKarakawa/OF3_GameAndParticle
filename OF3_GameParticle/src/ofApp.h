#pragma once

#include "ofMain.h"
#include "Game/GameStats.h"
#include "Game/Menu.h"
#include "Game/Game.h"
#include "Editor/ParticleEditor.h" 

class ofApp : public ofBaseApp{
	private:
		GameStats _gameStatus;
		ParticleEditor _particleEditor;
		Menu _menu;					// Class que gerencia o menu
		float _deltaTime;
	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		
		Game _game;
};
