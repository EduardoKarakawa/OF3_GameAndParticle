#pragma once
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"
#include "../Editor/ParticleEmission.h"

class Enemy : public GameObject
{
private:
	float m_r, m_g, m_b;
	int m_speed, m_radius;
	bool m_live;
	ofVec2f m_direction;
	ParticleEmission m_particle;
public:
	Enemy(ofVec2f playerPos);

	void Update(ofVec2f playerPos, float &deltaTime);
	void Draw();
	bool enemyLife(ofVec2f bul);

};