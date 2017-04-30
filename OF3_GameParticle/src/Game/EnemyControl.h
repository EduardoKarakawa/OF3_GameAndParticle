#pragma once
#include "Enemy.h"
#include "Player.h"
#include "GameStats.h"

class EnemyControl
{
private:
	vector<Enemy*> enemy;
	int lastTime; //último momento que o inimigo foi criado

public:
	EnemyControl();

	void Update(int time, float deltaTime, Player *player, GameStats *gameS);
	void Draw();

	int GetVectorSize() const;
	ofVec2f GetEnemyPos(int i) const;
};