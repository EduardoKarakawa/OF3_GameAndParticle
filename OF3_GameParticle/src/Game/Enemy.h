#pragma once
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"
#include "Player.h"

class Enemy : public GameObject
{
private:
	int m_id;
	float m_r, m_g, m_b;
	int m_speed, m_radius;
	ofVec2f m_direction;

public:
	Enemy(ofVec2f playerPos, int id);

	void Update(Player *p);
	void Draw();

};