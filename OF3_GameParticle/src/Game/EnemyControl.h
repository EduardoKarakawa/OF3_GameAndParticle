#pragma once
#include "Enemy.h"

class EnemyControl
{
private:
	vector<Enemy*> enemy;
	int lastTime; //último momento que o inimigo foi criado

public:
	EnemyControl();

	void Update(int time, float deltaTime, ofVec2f playerPos, vector<Bullet*> bullet);
	void Draw();

};