#pragma once

#include "ofxGui.h"
#include "ofxLabel.h"
#include "ParticleEmission.h"
#include "of3dUtils.h"


class Gui {
	private:
		ofxFloatSlider size, lifeTime, angle, radius, timeSpawn; //slider float
		ofxVec2Slider worldPos, direction; //slider vector
		ofxIntSlider velocity; //slider int
		ofxColorSlider color; //slider color
		ofxToggle worldPosToMouse, directionPosToMouse; //check button 
		ofxToggle drawParameters;
		ofxPanel gui;
		float buttonHide;
		ofVec2f mousePositon, antPosition;

	public:
		void Init();
		void Update(ParticleEmission &emissor);
		void Draw();
		void Hide();
		void SetMousePosition(int x, int y);
		void ChangeDirectionAndPosition();
		void DrawDirectionAndCone(ofVec2f posit, ofVec2f direct);
};