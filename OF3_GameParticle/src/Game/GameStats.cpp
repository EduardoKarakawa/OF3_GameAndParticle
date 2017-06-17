#include "GameStats.h"


int GameStats::GetStatus() { return m_status; }
int GameStats::GetPreviusStatus() { return m_previusStatus; }

GameStats::GameStats() { 
	m_status = Status::MENU; 
	m_previusStatus = Status::MENU;
	m_soundtrack.load("SFX/Soundtrack.mp3");
	m_soundtrack.setVolume(m_soundtrack.getVolume() * 0.35f);
}

void GameStats::ChangeStats(int a) { 
	if (a >= MENU && a <= GAMEOVER) {
		m_previusStatus = m_status;
		m_status = a;
	}
	if(a == 1)
	{
		m_soundtrack.setLoop(true);
		m_soundtrack.play();
	}
	else
	{
		m_soundtrack.setLoop(false);
		m_soundtrack.stop();
	}
}
