#pragma once

enum EstadoJogo
{
	MENU = 0,
	GAMEPLAY,
	EDITOR,
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