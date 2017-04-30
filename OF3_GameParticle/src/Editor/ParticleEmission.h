#pragma once
#include "ofGraphics.h"
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "Particle.h"
#include <vector>

class ParticleEmission
{
	private:
		ofVec2f * m_fatherPosition;
		std::vector<Particle> m_particles;
		std::string m_spriteLocal;
		std::string m_father;
		ofImage m_sprite;
		ofVec2f m_positionOrigin;
		ofVec2f m_direction;
		ofColor m_color;
		float m_openAngle;
		float m_maxLifeTime;
		float m_velocity;
		float m_timeSpawnParticle;
		float m_spawnTimeCont;
		bool m_enableParticles;



	public:
		ParticleEmission();
		ParticleEmission(std::string tag, ofVec2f * fatherPosition);
		ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size);
		~ParticleEmission();

		void Update(float deltaTime);
		void CreateParticle();
		void Draw();


		void SetOrigin(ofVec2f origin);
		void SetDirection(ofVec2f direction);
		void SetOpenAngle(float openAngle);
		void SetSpeed(float speed);
		void SetSizeParticle(float radius);
		void SetLifeTime(float lifeTime);
		void SetSprite(string sprite);
		void SetSpawnTime(float timeSpawn);
		void SetColor(ofColor color);
		ParticleEmission * SearchConfig(std::string tag, ofVec2f * fatherPosition);
		void SaveParticleConfig(std::string name);

};

