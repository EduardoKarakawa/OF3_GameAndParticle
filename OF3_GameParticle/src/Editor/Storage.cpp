#include "Storage.h"

Storage::Storage() {
	//construtor vazio
}

//método que instancia a própria classe e retorna ela mesma
//isso faz com que essa classe possa ser usada em todo o projeto
//sem ter que ser criado um objeto do tipo Storage
Storage& Storage::instance() {
	static Storage storage;
	return storage;
}

//método salvar recebe como parâmetro por referência uma partícula criada
//string referente ao nome do documento de texto (xml)
void Storage::save(const ParticleEmission &particle, const string &name) {
	//cria um documento de texto(xml)
	ofXml xml;
	//cria uma tag principal chamada EMITTER
	xml.addChild("EMITTER");
	//entra na tag EMITTER
	xml.setTo("EMITTER");
	//cria "subtags" dentro da tag EMITTER com todos os parâmetros necessários
	xml.addValue("Sprite", particle.GetSprite());
	xml.addValue("Size", particle.GetSizeParticle());
	xml.addValue("Position", particle.GetOrigin());
	xml.addValue("Direction", particle.GetDirection());
	xml.addValue("Lifetime", particle.GetLifeTime());
	xml.addValue("Velocity", particle.GetSpeed());
	xml.addValue("TimeSpawn", particle.GetSpawnTime());
	xml.addValue("Color", particle.GetColor());

	//salva no documento de texto
	xml.save(name);
}

//método carregar recebe como parâmetro uma particula 
//aqui ParticleEmission não é const porque os parâmetros dela são alterados
//string referente ao nome do documento de texto(xml)
void Storage::load(ParticleEmission &particle, const string &name) {
	cout << "3 Entrou no Storage" << endl;
	//cria documento de texto(xml)
	ofXml xml;
	//carrega xml com o nome enviado por parâmetro
	xml.load(name);
	//se ele encontrar a tag <EMITTER>
	if (xml.getName() == "EMITTER") {
		cout << "4 entrou no if do EMITTER" << endl;
		//se dentro de <EMITTER> existir a tag <Sprite>
		if (xml.exists("Sprite")) {
			cout << "5 entrou no if do Sprite" << endl;
			//seta caminho da sprite pra um valor do tipo string 
			// que está dentro da tag <Sprite> do documento de texto(xml)
			particle.SetSprite(xml.getValue<string>("Sprite"));
			cout << particle.GetSprite() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Size>
		if (xml.exists("Size")) {
			//seta tamanho da particula pra um valor do tipo float 
			// que está dentro da tag <Size> do documento de texto(xml)
			particle.SetSizeParticle(xml.getValue<float>("Size"));
			cout << particle.GetSizeParticle() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Position>
		if (xml.exists("Position")) {
			//seta posição da particula pra um valor do tipo ofVex2f 
			// que está dentro da tag <Position> do documento de texto(xml)
			particle.SetOrigin(xml.getValue<ofVec2f>("Position"));
			cout << particle.GetOrigin() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Direction>
		if (xml.exists("Direction")) {
			//seta direção da particula pra um valor do tipo ofVex2f 
			// que está dentro da tag <Direction> do documento de texto(xml)
			particle.SetDirection(xml.getValue<ofVec2f>("Direction"));
			cout << particle.GetDirection() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Lifetime>
		if (xml.exists("Lifetime")) {
			//seta tempo de vida da particula pra um valor do tipo float 
			// que está dentro da tag <Lifetime> do documento de texto(xml)
			particle.SetLifeTime(xml.getValue<float>("Lifetime"));
			cout << particle.GetLifeTime() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Velocity>
		if (xml.exists("Velocity")) {
			//seta speed da particula pra um valor do tipo float 
			// que está dentro da tag <Velocity> do documento de texto(xml)
			particle.SetSpeed(xml.getValue<float>("Velocity"));
			cout << particle.GetSpeed() << endl;
		}
		//se dentro de <EMITTER> existir a tag <TimeSpawn>
		if (xml.exists("TimeSpawn")) {
			//seta spawn da particula pra um valor do tipo float 
			// que está dentro da tag <TimeSpawn> do documento de texto(xml)
			particle.SetSpawnTime(xml.getValue<float>("TimeSpawn"));
			cout << particle.GetSpawnTime() << endl;
		}
		//se dentro de <EMITTER> existir a tag <Color>
		if (xml.exists("Color")) {
			//seta cor da particula pra um valor do tipo ofColor 
			// que está dentro da tag <Color> do documento de texto(xml)
			particle.SetColor(xml.getValue<ofColor>("Color"));
			cout << particle.GetColor() << endl;
		}
	}
}
