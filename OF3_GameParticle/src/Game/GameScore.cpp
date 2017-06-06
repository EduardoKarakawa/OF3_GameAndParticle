#include "GameScore.h"

Score::Score()
{
	m_score = 0;
	for (int i = 0; i < 5; i++) {
		m_highScore[i] = -1;
	}
}

void Score::addNormalEnemy()
{
	m_score += 10;
}

void Score::scoreUpdate()
{
	scoreFile = fopen("score.txt", "w");
	bool newScore = false;

	for (int i = 0; i < 5; i++)
	{
		if (m_highScore[i] <= m_score && newScore == false)
		{
					m_highScore[i] = m_score;
					newScore = true;
					break;
		}
	}

	if(newScore)
	{
		for(int i = 0; i < 5 ; i++ )
		{
			if(m_highScore[i] > -1)
				fprintf(scoreFile, "%d:\t %d\t\n", (i+1), m_highScore[i]);
			else
				fprintf(scoreFile, "%d:\t -----\t\n", (i+1));
		}
	}

	fclose(scoreFile);
}
