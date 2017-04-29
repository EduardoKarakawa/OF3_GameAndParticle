#include "Enemy.h"

Enemy::Enemy(ofVec2f playerPos)
{
	m_live = true;

	m_r = 0.5;
	m_g = 0.25;
	m_b = 0.6;

	m_life = 2;
	m_speed = 80%rand()+10;
	m_radius = 27;
	int pos;
	do {
		pos = ofGetWidth() % rand();
	} while (pos == ofGetWidth());
	m_position.set(pos, 0);
	m_direction = (playerPos - m_position).normalize();

}

void Enemy::Update(ofVec2f playerPos, float &deltaTime)
{
	// Calcula uma velocidade pegando o produto do speed e deltaTime para que o enemy ande igual em qualquer pc
	float tmpVelocity = m_speed * deltaTime;

	// Atualiza a posição do inimigo conforme a posição do player, para persegui-lo
	m_direction = (playerPos - m_position).normalize();
	m_position += m_direction*tmpVelocity;
}

void Enemy::Draw()
{
	if (m_position.x <= ofGetWidth() && m_position.x >= 0 && m_position.y <= ofGetHeight() && m_position.y >= 0) {
		ofSetColor(m_r, m_g, m_b);
		ofDrawCircle(m_position.x, m_position.y, m_radius);
	}
}

//Verifica se o enemy sobrevive ao ataque do player
bool Enemy::enemyLife(ofVec2f bul)
{
	//if ((bul.x - 10) <= (m_position.x + 27) && (bul.x + 10) >= (m_position.x - 27) && (bul.y - 10) <= (m_position.y + 27) && (bul.y + 10) >= (m_position.y - 27))
	if (bul.distance(m_position) <= 37)
	{
		m_life--;
		if (m_life <= 0)
		{
			return false;
		}
	}
	return true;
}