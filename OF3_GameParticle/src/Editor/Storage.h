#pragma once

#include <vector>
#include <string>
#include <ofXml.h>

#define STORAGE Storage::instance()

using namespace std;
class ParticleEmission;

class Storage {
	private:
		vector<ofXml> files;
		Storage();
	public:
		static Storage& instance();
		void save(const ParticleEmission &particle, const string &name);
		void load(ParticleEmission &particle, const string &name);
};