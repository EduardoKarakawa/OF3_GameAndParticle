#include "GameTime.h"

GameTime::GameTime()
{
}

void GameTime::StartTime()
{
	m_start = clock();
}

void GameTime::EndTime()
{
	m_end = clock();
}

void GameTime::TimeGame()
{
	m_now = m_end - m_start;
}

int GameTime::GetTimeGame() const
{
	return m_now;
}
