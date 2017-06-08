#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Gui.h"
#include "ParticleEmission.h"
#include "ofFileUtils.h"
#include "ofSystemUtils.h"
#include "Camera.h"


class ParticleEditor{
	private:
		ParticleEmission m_particlesList;
		
	public:
		Gui m_guiEditor;
		Camera camera;
		ofImage image;

	public:
		ParticleEditor();
		void Setup();
		void Update(float &deltaTime);
		void Draw();
		void SetMousePosition(int &x, int &y);
		
};
