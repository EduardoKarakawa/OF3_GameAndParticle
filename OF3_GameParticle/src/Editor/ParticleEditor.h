#pragma once
#include <vector>
#include <fstream>
#include <string>
#include "Gui.h"
#include "ParticleEmission.h"
#include "ofFileUtils.h"
#include "ofSystemUtils.h"



class ParticleEditor{
	private:
		ParticleEmission m_particlesList;
		
	public:
		Gui m_guiEditor;


	public:
		ParticleEditor();
		void LoadParticles();
		void Setup();
		void Update(float &deltaTime);
		void Draw();
		void SetMousePosition(int &x, int &y);
		
};
