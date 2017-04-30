#pragma once
#include <vector>
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"
#include "Bullet.h"
#define MAX_TIME_SHOOTING 0.2f

class Player : public GameObject
{
private:
	bool m_keyRight, m_keyLeft, m_keyUp, m_keyDown, m_keyZ, m_keySpace;
	bool m_keyW, m_keyS, m_keyA, m_keyD;
	int m_radius, m_keyArrow;
	float m_speed;
	float m_cooldownShooting;
	vector<Bullet*> bullets;

public:
	Player(std::string tag, int width, int height, float speed);

	void AddCounter();

	void Update(float &deltaTime);
	void Draw();
	void Press(int a);
	void Release(int a);

	int GetArrowKey() const;
	bool GetShooting();

	// -- Controle dos Tiros --
	void EraseBullet(int i);

	int GetVectorBulSize() const;
	ofVec2f GetBulletPosition(int i) const;
};