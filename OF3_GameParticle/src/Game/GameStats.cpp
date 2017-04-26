#include "GameStats.h"

GameStats::GameStats()
{
	m_estadoJogo = EstadoJogo::MENU;
}

int GameStats::GetEstado()
{
	return m_estadoJogo;
}

void GameStats::changeStats(int a)
{
	switch (a)
	{
	case 0:
		m_estadoJogo = EstadoJogo::MENU;
		break;
	case 1:
		m_estadoJogo = EstadoJogo::GAMEPLAY;
		break;
	case 2:
		m_estadoJogo = EstadoJogo::EDITOR;
		break;
	case 3:
		m_estadoJogo = EstadoJogo::GAMEOVER;
	}
}
