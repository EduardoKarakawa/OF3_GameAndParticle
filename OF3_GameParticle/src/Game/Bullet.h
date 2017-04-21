#pragma once
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"

#define BULLET_SPEED 600.0f

class Bullet : public GameObject
{
private:
	int m_id;
	int m_radius;
	float m_r, m_g, m_b;
	float m_speed;
	ofVec2f  m_direction;

public:
	Bullet(ofVec2f position, int direcao);

	void Update(float &deltaTime);
	void Draw();

};