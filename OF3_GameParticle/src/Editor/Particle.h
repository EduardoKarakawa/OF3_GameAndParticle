#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofImage.h"
#include "ofAppRunner.h"

class Particle
{
	private:
		ofColor m_color;
		bool m_isDead;
		ofVec2f m_position;
		ofVec2f m_direction;
		float m_maxLifeTime;
		float m_lifeTime;
		float m_velocity;
		float m_startOpacity;
		float addR;
		float addG;
		float addB;
		float addA;


	public:
		Particle();
		Particle(const ofVec2f& origin, const ofVec2f& direction, float openAngle, float speed, float maxLifeTime, const ofColor& initialColor, const ofColor& finalColor);
		void Update(const float & deltaTime);
		bool IsLife();
		void Draw(const ofImage& sprite);
		bool OnScreen(const int &w, const int&h);

		void SetValueToAddColor(const ofColor& initialCol, const ofColor& finalCol);

		const float& getCurrentLifeTime() const;

		~Particle();
};

