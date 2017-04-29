#pragma once
#include <vector>
#include "ofGraphics.h"
#include "ofVec2f.h"
#include "ofAppRunner.h"
#include "../KenjiGUI/MyButton.h"

class Menu {
	private:
		int m_option;
		//ofImage logo;
		std::vector<MyButton> m_buttonList;

	public:
		void Setup();
		void Draw();
		int Update();
};