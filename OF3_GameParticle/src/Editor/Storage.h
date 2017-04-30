#pragma once

#include <vector>
#include <string>
#include <ofXml.h>
#include "ParticleEmission.h"
#include "Gui.h"

//define pra n�o ter que ficar digitando Storage::instance() toda vez que quiser chamar um m�todo da classe Storage
#define STORAGE Storage::instance()

using namespace std;

class Storage {
	private:
		//vector de ofXml para salvar todas as xml (ainda n�o t� usando, n�o precisa prestar aten��o nisso)
		vector<ofXml> files;
		//construtor privado porque objeto que instancia a si mesmo n�o tem construtor publico.
		Storage();

	public:
		static Storage& instance();
		void save(const ParticleEmission &particle, const string &name);
		void load(Gui &guiParticle, const string &name);
};