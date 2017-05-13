#pragma once
#include "Player.h"
#include "EnemyControl.h"
#include "GameStats.h"
#include "../KenjiGUI/MyButton.h"

struct Keys {
	bool Right, Left, Up, Down;
	bool MouseLeft;
};

class GameControl{
	private:
		Player m_player;
		EnemyControl m_enemyControl;
		Keys m_keyInput;

	public:
		MyButton m_exit;

	public:
		GameControl();

		void Update(float &deltatime, GameStats &status);
		void Draw();
		void Key(const int &key);
		void KeyRelease(const int &key);

		~GameControl();
};

