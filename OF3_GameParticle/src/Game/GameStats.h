#pragma once
#include <iostream>

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

public:
	GameStats();

	int GetStatus();
	int GetPreviusStatus();
	void ChangeStats(int a);
};