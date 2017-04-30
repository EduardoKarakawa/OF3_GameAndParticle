#include "Storage.h"
#include "ofSystemUtils.h"

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
void Storage::save(const ParticleEmission &particle) {
	//
	ofFileDialogResult file = ofSystemSaveDialog("default.xml", "Save");
	if (file.bSuccess) {
		string path = file.getPath();
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
		xml.addValue("OpenAngle", particle.GetOpenAngle());
		xml.addValue("Lifetime", particle.GetLifeTime());
		xml.addValue("Velocity", particle.GetSpeed());
		xml.addValue("TimeSpawn", particle.GetSpawnTime());
		xml.addValue("Color", particle.GetColor());

		xml.save(path);
	}
}

//método carregar recebe como parâmetro uma particula 
//aqui ParticleEmission não é const porque os parâmetros dela são alterados
//string referente ao nome do documento de texto(xml)
void Storage::load(Gui &guiParticle) {
	//cria documento de texto(xml)
	ofFileDialogResult file = ofSystemLoadDialog("Load File");
	if (file.bSuccess) {
		string path = file.getPath();
		ofXml xml;
		//carrega xml com o nome enviado por parâmetro
		xml.load(path);
		//se ele encontrar a tag <EMITTER>
		if (xml.getName() == "EMITTER") {
			//se dentro de <EMITTER> existir a tag <Sprite>
			if (xml.exists("Sprite")) {
				//seta caminho da sprite pra um valor do tipo string 
				// que está dentro da tag <Sprite> do documento de texto(xml)
				guiParticle.SetSprite(xml.getValue<string>("Sprite"));
			}
			//se dentro de <EMITTER> existir a tag <Size>
			if (xml.exists("Size")) {
				//seta tamanho da particula pra um valor do tipo float 
				// que está dentro da tag <Size> do documento de texto(xml)
				guiParticle.SetSizeParticle(xml.getValue<float>("Size"));
			}
			//se dentro de <EMITTER> existir a tag <Position>
			if (xml.exists("Position")) {
				//seta posição da particula pra um valor do tipo ofVex2f 
				// que está dentro da tag <Position> do documento de texto(xml)
				guiParticle.SetOrigin(xml.getValue<ofVec2f>("Position"));
			}
			//se dentro de <EMITTER> existir a tag <Direction>
			if (xml.exists("Direction")) {
				//seta direção da particula pra um valor do tipo ofVex2f 
				// que está dentro da tag <Direction> do documento de texto(xml)
				guiParticle.SetDirection(xml.getValue<ofVec2f>("Direction"));
			}
			//se dentro de <EMITTER> existir a tag <OpenAngle>
			if (xml.exists("OpenAngle")) {
				guiParticle.SetOpenAngle(xml.getValue<float>("OpenAngle"));
			}
			//se dentro de <EMITTER> existir a tag <Lifetime>
			if (xml.exists("Lifetime")) {
				//seta tempo de vida da particula pra um valor do tipo float 
				// que está dentro da tag <Lifetime> do documento de texto(xml)
				guiParticle.SetLifeTime(xml.getValue<float>("Lifetime"));
			}
			//se dentro de <EMITTER> existir a tag <Velocity>
			if (xml.exists("Velocity")) {
				//seta speed da particula pra um valor do tipo float 
				// que está dentro da tag <Velocity> do documento de texto(xml)
				guiParticle.SetSpeed(xml.getValue<float>("Velocity"));
			}
			//se dentro de <EMITTER> existir a tag <TimeSpawn>
			if (xml.exists("TimeSpawn")) {
				//seta spawn da particula pra um valor do tipo float 
				// que está dentro da tag <TimeSpawn> do documento de texto(xml)
				guiParticle.SetSpawnTime(xml.getValue<float>("TimeSpawn"));
			}
			//se dentro de <EMITTER> existir a tag <Color>
			if (xml.exists("Color")) {
				//seta cor da particula pra um valor do tipo ofColor 
				// que está dentro da tag <Color> do documento de texto(xml)
				guiParticle.SetColor(xml.getValue<ofColor>("Color"));
			}
		}
	}

	
}
