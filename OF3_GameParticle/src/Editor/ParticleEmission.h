#pragma once
#include "ofGraphics.h"
#include "ofImage.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "Particle.h"
#include "ofXml.h"
#include <vector>

class ParticleEmission
{
	private:
		ofVec2f *m_fatherPosition;
		ofVec2f m_position;
		std::string m_spriteLocal;
		std::string m_fatherTag;
		ofImage m_sprite;
		ofVec2f m_direction;
		ofColor m_initialColor;
		ofColor m_finalColor;
		int m_totalByTime; 
		float m_openAngle;
		float m_maxLifeTime;
		float m_velocity;
		float m_timeSpawnParticle;
		float m_spawnTimeCont;
		float m_radius;
		bool m_enableParticles;
		float m_timeCountSweep;
		bool m_chageSize;
		bool m_randomDirection;
		
	public:
		std::vector<Particle> m_particles; 
		std::vector<int> m_particlesDead;


	public:
		ParticleEmission();
		ParticleEmission(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size);
		ParticleEmission(ofVec2f position, ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size, ofColor& color);
		ParticleEmission(ofVec2f position, ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float timeSpawn, std::string sprite, float size, ofColor& initialColor, ofColor& finalColor);
		~ParticleEmission();

		void Update(const float &deltaTime);
		void Update(const float &deltaTime, ofVec2f *fatherPosition);
		void CreateParticle();
		void CreateParticle(const ofVec2f &fatherPosition);
		void Draw();

		void SetOrigin(ofVec2f origin);
		void SetDirection(ofVec2f direction);
		void SetOpenAngle(float openAngle);
		void SetSpeed(float speed);
		void SetSizeParticle(float radius);
		void SetLifeTime(float lifeTime);
		void SetSprite(std::string sprite);
		void SetSpawnTime(float timeSpawn);
		void SetParticleProcess(bool process);
		void SetFatherTag(std::string fatherTag);
		void SetEnable(bool value);
		void SetTotalOfSpawnParticle(int total);
		void SetRandomDirection(bool value);
		void SetInitialColor(const ofColor& initialColor);
		void SetFinalColor(const ofColor& finalColor);


		void SearchParticleConfig(std::string tag);

		const bool& IsEnable() const;
		const bool& IsRamdomSpawn() const;
		const ofVec2f& GetOrigin() const;
		const ofVec2f& GetDirection() const;
		const float& GetOpenAngle() const;
		const float& GetSpeed() const;
		const float& GetLifeTime() const;
		const std::string& GetSprite() const;
		const float& GetSpawnTime() const;
		const float& GetSizeParticle() const;
		const std::string& GetFatherTag() const;
		const int& GetTotalOfSpawnParticle() const;
		const bool& CollidedWith(const ofVec2f &other, float size) const;
		const ofColor& GetInialColor() const;
		const ofColor& GetFinalColor() const;


		
		void ListSweeping(bool speegin);
};

