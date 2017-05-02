#pragma once
#include "ofGraphics.h"
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "Particle.h"
#include "ofXml.h"
#include <vector>

enum Positions {
	Position,
	PositionOrigin,
	PositionFather,
	PositionPrevious
};


class ParticleEmission
{
	private:
		bool m_isLoad;
		std::string m_spriteLocal;
		std::string m_fatherTag;
		ofImage m_sprite;
		std::vector<ofVec2f*> m_position;
		ofVec2f m_direction;
		ofColor m_color;
		float m_openAngle;
		float m_maxLifeTime;
		float m_velocity;
		float m_timeSpawnParticle;
		float m_spawnTimeCont;
		float m_radius;
		bool m_enableParticles;
		float m_timeCountSweep;
		
	public:
		std::vector<Particle> m_particles; 
		std::vector<int> m_particlesDead;


	private:
		ParticleEmission(std::string tag, ofVec2f * fatherPosition);

	public:
		ParticleEmission();
		ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, string sprite, float size);
		~ParticleEmission();

		void Update(float deltaTime);
		void CreateParticle();
		void Draw();

		std::string enable();
		void SetOrigin(ofVec2f origin);
		void SetDirection(ofVec2f direction);
		void SetOpenAngle(float openAngle);
		void SetSpeed(float speed);
		void SetSizeParticle(float radius);
		void SetLifeTime(float lifeTime);
		void SetSprite(string sprite);
		void SetSpawnTime(float timeSpawn);
		void SetColor(ofColor color);
		void SetParticleProcess(bool process);
		void SetFatherTag(std::string fatherTag);

		void SearchParticleConfig(std::string tag, ofVec2f *fatherPosition);

		const ofVec2f GetOrigin() const;
		const ofVec2f GetDirection() const;
		const float GetOpenAngle() const;
		const float GetSpeed() const;
		const float GetLifeTime() const;
		const string GetSprite() const;
		const float GetSpawnTime() const;
		const ofColor GetColor() const;
		const float GetSizeParticle() const;
		const std::string GetFatherTag() const;


		void ListSweeping(bool speegin);
};

