#pragma once
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"
#include "Player.h"

class Enemy : public GameObject
{
private:
	int m_life;
	float m_r, m_g, m_b;
	int m_speed, m_radius;
	bool m_live;
	ofVec2f m_direction;

public:
	Enemy(ofVec2f playerPos);

	void Update(ofVec2f playerPos, float &deltaTime);
	void Draw();
	bool enemyLife(ofVec2f bul);

};