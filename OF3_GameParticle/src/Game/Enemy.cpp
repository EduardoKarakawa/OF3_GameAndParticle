#include "Enemy.h"

Enemy::Enemy(ofVec2f playerPos)
{
	m_r = 0.5;
	m_g = 0.25;
	m_b = 0.6;

	m_speed = 80 % rand() + 10;

	m_radius = 27;

	int pos;
	pos = rand() % ofGetWidth();
	m_position.set(pos, 0);

	m_direction = playerPos - m_position;

	int i = rand() % 4; 
	m_particle.SearchParticleConfig("Enemy" + ofToString(i));

	//Carrega a sprite
	LoadNewImage("GameSprites", "Enemy.png");

	//Carrega o som
	bullet.load("SFX/Bullet_Enemy.mp3");
}



void Enemy::Update(ofVec2f playerPos, const float &deltaTime)
{
	// Atualiza a posição do inimigo conforme a posição do player, para persegui-lo
	m_direction = playerPos - m_position;

	// Calcula uma velocidade pegando o produto do speed e deltaTime para que o enemy ande igual em qualquer pc
	m_position += m_direction.normalized() * m_speed * deltaTime;

	m_particle.Update(deltaTime, &m_position);
}



void Enemy::Draw()
{
	m_particle.Draw();
	ofSetColor(255, 255, 255, 255);
	if (m_position.x <= ofGetWidth() - 10 && m_position.x >= -10 && m_position.y <= ofGetHeight() - 10 && m_position.y >= -10) {
		DrawImage();
	}
}

//Verifica se o enemy sobrevive ao ataque do player
bool Enemy::Collided(ofVec2f bul, Score &gameScore)
{
	if (bul.distance(m_position) <= 37)
	{
		return true;
	}
	gameScore.addNormalEnemy();
	return false;
}

