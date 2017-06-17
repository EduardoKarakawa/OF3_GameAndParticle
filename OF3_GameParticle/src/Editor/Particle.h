#pragma once
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofImage.h"
#include "ofAppRunner.h"

class Particle
{
	private:
		bool m_isDead;
		ofVec2f m_position;
		ofVec2f m_direction;
		float m_lifeTime;
		float m_velocity;
		float m_opacity, m_startOpacity;


	public:
		Particle();
		Particle(ofVec2f origin, ofVec2f direction, float openAngle, float speed, float lifeTime, float startOpacity);
		void Update(const float & deltaTime);
		bool IsLife();
		void Draw(ofImage sprite, ofColor color, ofVec2f origin);
		bool OnScreen(const int &w, const int&h);

		~Particle();
};

