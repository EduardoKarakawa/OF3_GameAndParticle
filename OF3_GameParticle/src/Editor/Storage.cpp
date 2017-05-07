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


void Storage::reset(Gui &guiParticle, ParticleEmission & particleList) {
	guiParticle.Init();
	particleList = ParticleEmission();

}

//método salvar recebe como parâmetro por referência uma partícula criada
//string referente ao nome do documento de texto (xml)
void Storage::save(const ParticleEmission &particle, std::string fatherTag) {

	ofFileDialogResult file = ofSystemSaveDialog("default.xml", "Save");
	if (file.bSuccess) {
		string path = file.getPath();
		bool hasXml = false;
		
		// Verifica se tem .xml no final do path, se nao tiver ele eh colocado
		hasXml = path[path.length() - 4]== '.' &&
				 path[path.length() - 3] == 'x' &&
				 path[path.length() - 2] == 'm' &&
				 path[path.length() - 1] == 'l' ;
		if (!hasXml) {
			path += ".xml";
		}

		//cria um documento de texto(xml)
		ofXml xml;

		//cria uma tag principal chamada EMITTER
		xml.addChild("EMITTER");

		//entra na tag EMITTER
		xml.setTo("EMITTER");

		//cria "subtags" dentro da tag EMITTER com todos os parâmetros necessários
		xml.addValue("Father", fatherTag);
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
		//se ele encontrar a tag <EMITTER> eh carregado os parametros
		if (xml.getName() == "EMITTER") {
			if (xml.exists("Sprite")) {
				guiParticle.SetSprite(xml.getValue<string>("Sprite"));
			}
			if (xml.exists("Size")) {
				guiParticle.SetSizeParticle(xml.getValue<float>("Size"));
			}
			if (xml.exists("Position")) {
				guiParticle.SetOrigin(xml.getValue<ofVec2f>("Position"));
			}
			if (xml.exists("Direction")) {
				guiParticle.SetDirection(xml.getValue<ofVec2f>("Direction"));
			}
			if (xml.exists("OpenAngle")) {
				guiParticle.SetOpenAngle(xml.getValue<float>("OpenAngle"));
			}
			if (xml.exists("Lifetime")) {
				guiParticle.SetLifeTime(xml.getValue<float>("Lifetime"));
			}
			if (xml.exists("Velocity")) {
				guiParticle.SetSpeed(xml.getValue<float>("Velocity"));
			}
			if (xml.exists("TimeSpawn")) {
				guiParticle.SetSpawnTime(xml.getValue<float>("TimeSpawn"));
			}
			if (xml.exists("Color")) {
				guiParticle.SetColor(xml.getValue<ofColor>("Color"));
			}
		}
	}

	
}


void Storage::load(ParticleEmission &Particle, ofXml &file) {

}


// Cria botoes de acordo com as tags Colocadas no arquivos Tags.xml, 
// verifica qual delas foi preciona e armazena essa tag ou tambem eh possivel digitar outras 
std::string Storage::GetFather(std::vector<MyButton> &buttons) {
	ofFile file("/particles/Tags.xml");
	std::string outTag = "";

	if (file.is_open()) {
		ofXml tags(file.path());


		int i = 0;

		if (buttons.size() > 0) {
			for (int i = 0; i < buttons.size(); i++) {
				buttons[i].Update();
				if (buttons[i].IsPressed()) {
					outTag = buttons[i].GetText();
					break;
				}

			}
			if (outTag == "Other") {
				outTag = ofSystemTextBoxDialog("Digite a Tag do objeto Pai:", "");
			}
		}
		else{
			while (tags.exists("tag" + ofToString(i))) {
				MyButton tmp(tags.getValue<string>("tag" + ofToString(i)), false, ofGetWidth() / 2.0f, 100 + 75 * i, 150, 74);
				tmp.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
				buttons.push_back(tmp);
				i++;
			}

			MyButton tmp("Other", false, ofGetWidth() / 2.0f, 100 + 75 * i, 150, 74);
			tmp.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
			buttons.push_back(tmp);
		}

	}
	else {
		outTag = ofSystemTextBoxDialog("Digite a Tag do objeto Pai:", "");
	}

	return outTag;
}