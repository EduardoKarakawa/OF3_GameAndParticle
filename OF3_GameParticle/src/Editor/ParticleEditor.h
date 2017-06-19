#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Gui.h"
#include "ParticleEmission.h"
#include "ofFileUtils.h"
#include "ofSystemUtils.h"
#include "../Game/Camera.h"


class ParticleEditor{
	private:
		ParticleEmission m_particlesList;
		
	public:
		Gui m_guiEditor;
		Camera camera;
		ofImage image;
		string background;
		bool clicked;

	public:
		ParticleEditor();
		void Setup();
		void Update(float &deltaTime);
		void Draw();
		void SetMousePosition(int &x, int &y);
		void SetBackground(string& bg);
		
};
