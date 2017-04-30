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
	xml.addChild("EMITTER");
	xml.setTo("EMITTER");

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
	cout << "3 Entrou no Storage" << endl;
	ofXml xml;
	xml.load(name);
	if (xml.getName() == "EMITTER") {
		cout << "4 entrou no if do EMITTER" << endl;
		if (xml.exists("Sprite")) {
			//cout << "5 entrou no if do Sprite" << endl;
			particle.SetSprite(xml.getValue<string>("Sprite"));
			cout << particle.GetSprite() << endl;
		}
		if (xml.exists("Size")) {
			particle.SetSizeParticle(xml.getValue<float>("Size"));
			cout << particle.GetSizeParticle() << endl;
		}
		if (xml.exists("Position")) {
			particle.SetOrigin(xml.getValue<ofVec2f>("Position"));
			cout << particle.GetOrigin() << endl;
		}
		if (xml.exists("Direction")) {
			particle.SetDirection(xml.getValue<ofVec2f>("Direction"));
			cout << particle.GetDirection() << endl;
		}
		if (xml.exists("Lifetime")) {
			particle.SetLifeTime(xml.getValue<float>("Lifetime"));
			cout << particle.GetLifeTime() << endl;
		}
		if (xml.exists("Velocity")) {
			particle.SetSpeed(xml.getValue<float>("Velocity"));
			cout << particle.GetSpeed() << endl;
		}
		if (xml.exists("TimeSpawn")) {
			particle.SetSpawnTime(xml.getValue<float>("TimeSpawn"));
			cout << particle.GetSpawnTime() << endl;
		}
		if (xml.exists("Color")) {
			particle.SetColor(xml.getValue<ofColor>("Color"));
			cout << particle.GetColor() << endl;
		}
	}
}
