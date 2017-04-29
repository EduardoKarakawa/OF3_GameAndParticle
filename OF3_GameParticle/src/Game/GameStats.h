#pragma once

enum EstadoJogo
{
	MENU = 0,
	EDITOR,
	GAMEPLAY,
	GAMEOVER
};

class GameStats
{
private:
	int m_estadoJogo;

public:
	GameStats();

	int GetEstado();

	void changeStats(int a);

};