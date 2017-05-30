#include "GameStats.h"


int GameStats::GetStatus() { return m_status; }
int GameStats::GetPreviusStatus() { return m_previusStatus; }

GameStats::GameStats() { 
	m_status = Status::MENU; 
	m_previusStatus = Status::MENU;
}

void GameStats::ChangeStats(int a) { 
	if (a >= MENU && a <= GAMEOVER) {
		m_previusStatus = m_status;
		m_status = a;
	}
}
