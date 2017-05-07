#pragma once
#include <vector>
#include "GameObject.h"
#include "ofGraphics.h"
#include "ofMain.h"
#include "Bullet.h"
#include "../Editor/ParticleEmission.h"
#define MAX_TIME_SHOOTING 0.2f
#define FRICTION_PORCENT 0.3f
#define SPEED 

	class Player : public GameObject{
	private:
		int m_radius;
		float m_speed;
		float m_cooldownShooting;
		vector<Bullet> m_bullets;
		ParticleEmission m_particle;
		ofVec2f m_mousePosition;
		ofVec2f m_direction;
		bool m_moving;

	public:
		Player();
		Player(std::string tag, int width, int height, float speed);
		~Player();

		void Update(const float &deltaTime);
		void Draw();
		void SetDirectionX(int x);
		void SetDirectionY(int y);
		void Shooting();
		void SetMousePosition(const int &x, const int &y);



		// -- Controle dos Tiros --
		void EraseBullet(int i);
		int GetVectorBulSize() const;
		ofVec2f GetBulletPosition(int i) const;
};