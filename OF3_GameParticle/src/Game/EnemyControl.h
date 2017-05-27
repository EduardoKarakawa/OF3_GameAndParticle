#pragma once
#include "Enemy.h"
#include "Player.h"
#include "GameStats.h"

#define TIME_SPAWN 1

class EnemyControl
{
	private:
		vector<Enemy> enemy;
		float m_timeCount; //último momento que o inimigo foi criado


	public:
		EnemyControl();

		void Update(float &deltaTime, Player &player, GameStats &gameS);
		void Draw();

		int GetVectorSize() const;
		ofVec2f GetEnemyPos(int i) const;
};