#pragma once
#include "Bullet.h"
#include "Player.h"

class BulletControl
{
private:
	vector<Bullet*> bullet;

public:
	BulletControl();

	void Update(Player *gamePlayer, float deltaTime);
	void Draw();

	void EraseBullet(int i);

	int GetVectorSize() const;
	ofVec2f GetBulletPosition(int i) const;
};