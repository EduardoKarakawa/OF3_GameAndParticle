#pragma once
#include <stdio.h>
#include <stdlib.h>

class Score
{
private:
	//Arquivo que guarda o Score
	// Score
	int m_score;
	int m_highScore[5];
	FILE *scoreFile;

public:
	Score();
	void addNormalEnemy();
	void scoreUpdate();
	
};