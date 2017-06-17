#pragma once
#include <iostream>
#include "ofSoundPlayer.h"

enum Status
{
	MENU,
	GAME,
	EDITOR,
	GAMEOVER
};

class GameStats
{
private:
	int m_status;
	int m_previusStatus;
	ofSoundPlayer m_soundtrack;

public:
	GameStats();

	int GetStatus();
	int GetPreviusStatus();
	void ChangeStats(int a);
};