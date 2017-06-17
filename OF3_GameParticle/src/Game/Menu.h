#pragma once
#include <vector>
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "../KenjiGUI/MyButton.h"
#include "../Editor/ParticleEmission.h"

class Menu {
	private:
		int m_option;
		ofTrueTypeFont particle, editor;
		vector<ParticleEmission> particles;
		std::vector<MyButton> m_buttonList;

	public:
		void Setup();
		void Draw();
		int Update();
};