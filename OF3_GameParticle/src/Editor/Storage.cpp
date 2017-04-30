#include "Storage.h"
#include "ParticleEmission.h"

Storage::Storage() {

}

Storage& Storage::instance() {
	static Storage storage;
	return storage;
}

void Storage::save(const ParticleEmission &particle, const string &name) {
	ofXml xml;
	xml.addChild("Emitter");
	xml.setTo("Emitter");

	xml.addValue("Sprite", particle.GetSprite());
	xml.addValue("Size", particle.GetSizeParticle());
	xml.addValue("Position", particle.GetOrigin());
	xml.addValue("Direction", particle.GetDirection());
	xml.addValue("Lifetime", particle.GetLifeTime());
	xml.addValue("Velocity", particle.GetSpeed());
	xml.addValue("TimeSpawn", particle.GetSpawnTime());
	xml.addValue("Color", particle.GetColor());


	xml.save(name);
}
void Storage::load(ParticleEmission &particle, const string &name) {
	ofXml xml;
	xml.load(name);
	if (xml.exists("Emitter")) {
		if (xml.exists("Sprite")) {
			particle.SetSprite(xml.getValue<string>("Sprite"));
		}
		if (xml.exists("Size")) {
			particle.SetSizeParticle(xml.getValue<float>("Sprite"));
		}
		if (xml.exists("Position")) {
			particle.SetOrigin(xml.getValue<ofVec2f>("Sprite"));
		}
		if (xml.exists("Direction")) {
			particle.SetDirection(xml.getValue<ofVec2f>("Sprite"));
		}
		if (xml.exists("Lifetime")) {
			particle.SetLifeTime(xml.getValue<float>("Sprite"));
		}
		if (xml.exists("Velocity")) {
			particle.SetSpeed(xml.getValue<float>("Sprite"));
		}
		if (xml.exists("TimeSpawn")) {
			particle.SetSpawnTime(xml.getValue<float>("Sprite"));
		}
		if (xml.exists("Color")) {
			particle.SetColor(xml.getValue<ofColor>("Sprite"));
		}
	}
}
