#pragma once
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"

#define MAX_TIME_SHOOTING 0.2f

class Player : public GameObject
{
private:
	bool m_keyRight, m_keyLeft, m_keyUp, m_keyDown, m_keyZ, m_keySpace;
	bool m_keyW, m_keyS, m_keyA, m_keyD;
	int m_radius, m_keyArrow;
	float m_speed;
	float m_cooldownShooting;

public:
	Player(int width, int height, float speed);

	void AddCounter();

	void Update(float &deltaTime);
	void Draw();
	void Press(int a);
	void Release(int a);

	int GetArrowKey() const;
	// int GetBulletKey() const; virou bool GetShooting();--------------------------
	bool GetShooting();

	// GetPosition foi movido para o GameObject-------------------------------------

};