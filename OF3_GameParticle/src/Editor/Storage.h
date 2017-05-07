#pragma once

#include <vector>
#include <string>
#include <ofXml.h>
#include "ParticleEmission.h"
#include "../KenjiGUI/MyButton.h" 
#include "Gui.h"

//define pra n�o ter que ficar digitando Storage::instance() toda vez que quiser chamar um m�todo da classe Storage
#define STORAGE Storage::instance()

using namespace std;

class Storage {
	private:
		//construtor privado porque objeto que instancia a si mesmo n�o tem construtor publico.
		Storage();
	public:
		static Storage& instance();
		void reset(Gui &guiParticle, ParticleEmission & particleList);
		void save(const ParticleEmission &particle, std::string fatherTag);
		void load(Gui &guiParticle);
		void load(ParticleEmission &Particle, ofXml &file);
		std::string GetFather(std::vector<MyButton> &buttons);

};