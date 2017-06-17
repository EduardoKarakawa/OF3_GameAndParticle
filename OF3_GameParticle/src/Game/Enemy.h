#pragma once
#include "GameObject.h"
#include "GameScore.h"
#include "ofGraphics.h"
#include "ofSoundPlayer.h"
#include "ofMain.h"
#include "../Editor/ParticleEmission.h"

class Enemy : public GameObject
{
private:
	float m_r, m_g, m_b;
	int m_speed, m_radius;
	ofVec2f m_direction;
	ParticleEmission m_particle;
	ofSoundPlayer bullet;


public:
	Enemy(ofVec2f playerPos);
	
	void Update(ofVec2f playerPos, const float &deltaTime);
	void Draw();
	bool Collided(ofVec2f bul, Score &gameScore);
};