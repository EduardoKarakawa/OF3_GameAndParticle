#pragma once
#include <vector>
#include "GameObject.h"
#include "ofSoundPlayer.h"
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
		ParticleEmission m_particle;
		ofVec2f m_mousePosition;
		ofVec2f m_direction;
		bool m_moving;
		int m_life;
		ofImage m_imageLife;
		ofSoundPlayer m_bulletSound;
		ofSoundPlayer m_explosionSound;

	public:
		Player();
		Player(std::string tag, int width, int height, float speed);
		~Player();

		void Update(const float &deltaTime);
		void Draw();
		void SetDirectionX(int x);
		void SetDirectionY(int y);
		void Shooting(bool value);
		void SetMousePosition(const int &x, const int &y);

		//Para o controle da vida do Player que é feito no EnemyControl
		void LessLife(); //Diminui a vida do Player
		int GetLife() const;

		//Reproduz o som de morte
		void SoundDie();


		// -- Controle dos Tiros --
		const ParticleEmission & GetShotParticle() const;
		//void EraseBullet(int i);
		//int GetVectorBulSize() const;
		//ofVec2f GetBulletPosition(int i) const;
};