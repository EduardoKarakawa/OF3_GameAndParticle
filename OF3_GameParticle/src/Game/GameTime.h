#pragma once
#include <Time.h>

class GameTime
{
private:
	clock_t m_start;
	clock_t m_end;
	int m_now;

public:
	GameTime();

	void StartTime();
	void EndTime();
	void TimeGame();

	int GetTimeGame() const;

};