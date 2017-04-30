#pragma once

#include <vector>
#include <string>
#include <ofXml.h>
#include "ParticleEmission.h"
#include "Gui.h"

//define pra não ter que ficar digitando Storage::instance() toda vez que quiser chamar um método da classe Storage
#define STORAGE Storage::instance()

using namespace std;

class Storage {
	private:
		//vector de ofXml para salvar todas as xml (ainda não tá usando, não precisa prestar atenção nisso)
		vector<ofXml> files;
		//construtor privado porque objeto que instancia a si mesmo não tem construtor publico.
		Storage();

	public:
		static Storage& instance();
		void save(const ParticleEmission &particle, const string &name);
		void load(Gui &guiParticle, const string &name);
};