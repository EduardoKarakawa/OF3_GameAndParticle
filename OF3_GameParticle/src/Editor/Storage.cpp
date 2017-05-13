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
	std::string path = GetFilePath(fatherTag);
	bool hasXml = false;
	if (path == "") {
		std::string name = ofSystemTextBoxDialog("Digite o nome do arquivo: ");
		if (name != "") {
			path = "../data/particles/" + name;
			AddOnTags(fatherTag);
		}
		else {
			ofSystemAlertDialog("Nao foi possivel salvar.");
		}
	}
	
	if (path != "") {
	}
	// Verifica se tem .xml no final do path, se nao tiver ele eh colocado
	hasXml = path[path.length() - 4] == '.' &&
		path[path.length() - 3] == 'x' &&
		path[path.length() - 2] == 'm' &&
		path[path.length() - 1] == 'l';
	if (!hasXml) {
		path += ".xml";

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
		ofSystemAlertDialog("Configuracoes Salvas com Sucesso.");
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
				ofVec2f tmp = xml.getValue<ofVec2f>("Position");
				ofVec2f center(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
				if(tmp.x < center.x && tmp.y < center.y)
					guiParticle.SetOrigin(tmp + center);
				else
					guiParticle.SetOrigin(tmp);
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
				MyButton tmp(tags.getValue<string>("tag" + ofToString(i)), false, ofGetWidth() / 2.0f - 75, 100 + 50 * i, 150, 49);
				tmp.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
				buttons.push_back(tmp);
				i++;
			}

			MyButton tmp("Other", false, ofGetWidth() / 2.0f - 75, 100 + 50 * i, 150, 49);
			tmp.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
			buttons.push_back(tmp);
		}

	}
	else {
		outTag = ofSystemTextBoxDialog("Digite a Tag do objeto Pai:", "");
	}

	return outTag;
}


std::string Storage::GetFilePath(std::string &tag) {
	ofDirectory directory("../data/particles");
	directory.allowExt("xml");
	directory.listDir();

	for (int i = 0; i < directory.size(); i++) {
		ofXml tmp(directory.getPath(i));
		if (tmp.exists("Father") && tmp.getValue<std::string>("Father") == tag) {
			return directory.getPath(i);
		}
	}

	return "";
}


void Storage::AddOnTags(std::string &tag) {
	std::string path = ofFile("../data/particles/Tags.xml").getAbsolutePath();
	ofXml file(path);
	std::cout << file.getName() << std::endl;
	file.setTo("TAGS");
	int cont = 0;
	while (file.exists("tag" + ofToString(cont))) {
		cont++;
		std::cout << "contando " << std::endl;
	}
	std::cout << "Salvando " << tag << std::endl;
	file.addValue("tag" + ofToString(cont), tag);
	file.save(path);
}