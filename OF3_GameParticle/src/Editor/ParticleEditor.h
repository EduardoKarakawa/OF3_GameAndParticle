#pragma once
#include <vector>
#include <fstream>
#include "Gui.h"
#include "ParticleEmission.h"
#include "ofFileUtils.h"


class ParticleEditor{
	private:
		Gui m_guiEditor;
		ParticleEmission m_particlesList;
		//std::vector<ParticleEmission> m_particlesList;
		

	public:
		ParticleEditor();
		void LoadParticles();
		void Setup();
		void Update(float &deltaTime);
		void Draw();
		void SetMousePosition(int &x, int &y);
};
