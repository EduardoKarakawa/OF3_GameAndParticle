#pragma once

#include <string>
#include "ofxGui.h"
#include "ofxLabel.h"
#include "ofTrueTypeFont.h"
#include "ParticleEmission.h"
#include "ofSystemUtils.h"
#include "of3dUtils.h"
#include "../KenjiGUI/MyButton.h"
#include "../KenjiGUI/IntTextBox.h"

#define BORDER_LEFT 10.0f

class Gui {
	private:
		std::string sprite;
		string background;
		ofxFloatSlider size, lifeTime, angle, radius, timeSpawn, velocity; //slider float
		ofxColorSlider initialColor, finalColor; //slider color
		ofxToggle drawParameters, randomSpawn;
		ofxPanel gui;
		ofVec2f mousePositon, antPosition;
		bool worldPosToMouse, directionPosToMouse;
		bool changeValues;
		std::vector<MyButton> m_tagButtons;
		ofxToggle localPosition;
		MyButton m_saveButton, m_resetButton, m_loadButton;
		MyButton m_playButton, m_loadImageButton, m_loadBackground;
		IntTextBox _textPositionX, _textPositionY;
		IntTextBox _textDirectionX, _textDirectionY;
		IntTextBox _textTotalSpawnByTime;
		ofTrueTypeFont font;
	
	public:
		MyButton m_exit;

	private:
		void DisableProcessParticle(ParticleEmission &emissor);
		void CopyConfig(Gui &config);
		const ofVec2f &Position() const;
		void Position(ofVec2f& position);
		const ofVec2f &Direction() const;
		void Direction(ofVec2f& position);

	public:
		void Init();
		void Update(ParticleEmission &emissor);
		void Draw();
		void SetMousePosition(int x, int y);
		void ChangeDirectionAndPosition();
		void DrawDirectionAndCone(const ofVec2f& posit, const ofVec2f& direct);
		void DrawCenterAxis();

		void SetTotalParticleSpawn(int value);
		void SetOrigin(ofVec2f origin);
		void SetDirection(ofVec2f direction);
		void SetOpenAngle(float openAngle);
		void SetSpeed(float speed);
		void SetSizeParticle(float radius);
		void SetLifeTime(float lifeTime);
		void SetSprite(std::string local);
		void SetBackground(string bg);
		void SetSpawnTime(float timeSpawn);
		void SetInitialColor(const ofColor& initialColor);
		void SetFinalColor(const ofColor& finalColor);
		void SetRandomSpawn(bool value);

		void MoveOriginParticle();
		void MoveDirectionParticle();
		bool ParameterHasChanged(const ParticleEmission &emissor);
		
};