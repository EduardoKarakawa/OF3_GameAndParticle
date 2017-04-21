#include "Enemy.h"

Enemy::Enemy(ofVec2f playerPos, int id)
{
	m_r = 0.5;
	m_g = 0.25;
	m_b = 0.6;
	
	m_id = id;
	m_speed = 2;
	m_position.set(ofGetWidth() % rand(), 0);
	m_direction = (playerPos - m_position).normalize();

}

void Enemy::Update(Player *p)
{
	m_direction = (p->GetPosition() - m_position).normalize();
	m_position += m_direction*m_speed;
}

void Enemy::Draw()
{
	if (m_position.x <= ofGetWidth() && m_position.x >= 0 && m_position.y <= ofGetHeight() && m_position.y >= 0) {
		ofSetColor(m_r, m_g, m_b);
		ofDrawCircle(m_position.x, m_position.y, m_radius);
	}
}
