#include "Gui.h"
#include "Storage.h"


const ofVec2f& Gui::Position()	const { return ofVec2f(_textPositionX.GetValue(), _textPositionY.GetValue()); }
const ofVec2f& Gui::Direction() const { return ofVec2f(_textDirectionX.GetValue(), _textDirectionY.GetValue()); }
void Gui::Position(ofVec2f& position) { _textPositionX.SetValue(position.x);	_textPositionY.SetValue(position.y); }
void Gui::Direction(ofVec2f& position) { _textDirectionX.SetValue(position.x); _textDirectionY.SetValue(position.y); }

void Gui::SetTotalParticleSpawn(int value) {
	_textTotalSpawnByTime.SetValue(value);
	changeValues = true;
}
void Gui::SetOrigin(ofVec2f origin) {
	Position(origin);
	changeValues = true;
}
void Gui::SetDirection(ofVec2f direction) {
	Direction(direction);
	changeValues = true;
}
void Gui::SetOpenAngle(float openAngle) {
	this->angle = openAngle;
	changeValues = true;
}
void Gui::SetSpeed(float speed) {
	this->velocity = speed;
	changeValues = true;
}
void Gui::SetSizeParticle(float radius) {
	this->radius = radius;
	changeValues = true;
}
void Gui::SetLifeTime(float lifeTime) {
	this->lifeTime = lifeTime;
	changeValues = true;
}
void Gui::SetSpawnTime(float timeSpawn) {
	this->timeSpawn = timeSpawn;
	changeValues = true;
}
void Gui::SetColor(ofColor color) {
	this->color = color;
	changeValues = true;
}
void Gui::SetSprite(std::string local) {
	sprite = local;
	changeValues = true;
}
void Gui::SetBackground(string bg) {
	background = bg;
	changeValues = true;
}
void Gui::SetRandomSpawn(bool value) { randomSpawn = value; }

void Gui::MoveOriginParticle() { worldPosToMouse = !worldPosToMouse; }
void Gui::MoveDirectionParticle() { directionPosToMouse = !directionPosToMouse; }


void Gui::Init() {
	gui.setup();
	// Desenha a direcao e cone de spawn
	gui.add(drawParameters.setup("Show Direction/Cone", true));

	gui.add(randomSpawn.setup("Random Direction: ", false));

	// Define o tempo de vida da particula
	gui.add(lifeTime.setup("Life Time: ", 1.5f, 0.2f, 25));

	// Ajusta o tempo de spawn de uma particula
	gui.add(timeSpawn.setup("Time Spawn: ", 0.03f, 1.0f / 500.0f, 1.0f));

	// Angulo de abertura para o emissor
	gui.add(angle.setup("Open Angle: ", 30, 1, 360));

	// Define a velocidade com que a particula movimenta
	gui.add(velocity.setup("Velocity: ", 500, 0, 1000));

	// Raio para definir o tamanho da particula
	gui.add(radius.setup("Radius Particle: ", 30, 10, 300));


	// Botao toggle para calcular o local da particula apartir do centro
	gui.add(localPosition.setup("Local Position", true));

	// Muda a cor das particulas
	gui.add(color.setup("Color: ", ofColor(255, 159, 17), ofColor(0, 0), ofColor(255, 255)));

	// Define se esta movimentando a origem ou a direcao para falso
	worldPosToMouse = false;
	directionPosToMouse = false;
	changeValues = true;


	// Botoes 
	_textTotalSpawnByTime = IntTextBox("Total to Spawn:", MyButton::FONT_LEFT, 10, ofVec2f(_textTotalSpawnByTime.GetStringSize("Total to Spawn:").x + BORDER_LEFT, ofGetScreenHeight()/2 - 100), 1,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textTotalSpawnByTime.SetSize(80, 27);
	_textTotalSpawnByTime.SetSprite("teal.png", "teal2.png");

	_textPositionX = IntTextBox("Position X:", MyButton::FONT_LEFT, 10, ofVec2f(_textPositionX.GetStringSize("Position X:").x + BORDER_LEFT, ofGetScreenHeight() / 2 - 70),
		ofGetWidth() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textPositionX.SetSize(80, 27);
	_textPositionX.SetSprite("teal.png", "teal2.png");

	_textPositionY = IntTextBox("Y:", MyButton::FONT_LEFT, 10, ofVec2f(_textPositionX.GetStringSize("Position X:").x + 120 + _textDirectionY.GetStringSize("Y:").x + BORDER_LEFT, ofGetScreenHeight() / 2 - 70),
		ofGetHeight() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textPositionY.SetSize(80, 27);
	_textPositionY.SetSprite("teal.png", "teal2.png");

	_textDirectionX = IntTextBox("Direction X:", MyButton::FONT_LEFT, 10, ofVec2f(_textDirectionX.GetStringSize("Direction X:").x + BORDER_LEFT, ofGetScreenHeight() / 2 - 40),
		ofGetWidth() / 2 - 200,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textDirectionX.SetSize(80, 27);
	_textDirectionX.SetSprite("teal.png", "teal2.png");

	_textDirectionY = IntTextBox("Y:", MyButton::FONT_LEFT, 10,
		ofVec2f(_textDirectionX.GetStringSize("Direction X:").x + 120 + _textDirectionY.GetStringSize("Y:").x + BORDER_LEFT, ofGetScreenHeight() / 2 - 40),
		ofGetHeight() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textDirectionY.SetSize(80, 27);
	_textDirectionY.SetSprite("teal.png", "teal2.png");


	m_loadImageButton = MyButton("Image Load", MyButton::FONT_CENTER, 1.5f, false, 0, (ofGetHeight() - 200.0f), 120, 30);
	//m_loadImageButton.SetPosition(0, (ofGetHeight() - 100.0f));
	m_loadImageButton.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
	m_loadImageButton.SetSprite("teal.png", "teal2.png");

	m_resetButton = MyButton("Reset", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight() - 150, 203, 50);
	m_resetButton.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
	m_resetButton.SetSprite("teal.png", "teal2.png");

	m_saveButton = MyButton("Save", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight() - 50, 100, 50);
	m_saveButton.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));

	m_loadButton = MyButton("Load", MyButton::FONT_CENTER, 0, false, 103, ofGetHeight() - 50, 100, 50);
	m_loadButton.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));

	m_playButton = MyButton("Play", MyButton::FONT_CENTER, 0, false, ofGetWidth() / 2.0f, ofGetHeight() - 50, 100, 50);
	m_playButton.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));

	m_exit = MyButton("Sair", MyButton::FONT_CENTER, 0, false, ofGetWidth() - 100, ofGetHeight() - 50, 100, 50);
	m_exit.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));

	m_loadBackground = MyButton("Background", MyButton::FONT_CENTER, 0, false, 103, ofGetHeight() - 100, 100, 50);
	m_loadBackground.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));



	sprite = "/sprites/particula.png";
	background = "bgtest.png";


}

void Gui::Update(ParticleEmission &emissor) {

	if (!m_saveButton.IsPressed()) {
		emissor.SetParticleProcess(m_playButton.IsPressed());
		emissor.SetRandomDirection(randomSpawn);
		ChangeDirectionAndPosition();


		// Reajusta a posicao dos botoes de acordo com o tamanho da tela
		m_loadImageButton.SetPosition(0, ofGetHeight() - 160);
		m_loadBackground.SetPosition(0, ofGetHeight() - 120);
		m_resetButton.SetPosition(0, ofGetHeight() - 90);
		m_saveButton.SetPosition(0, ofGetHeight() - 50);
		m_loadButton.SetPosition(103, ofGetHeight() - 50);
		m_playButton.SetPosition(ofGetWidth() / 2.0f, ofGetHeight() - 50);

		// Updates dos botoes para verificar se eles foram precionados
		_textPositionX.Update();
		_textPositionY.Update();
		_textDirectionX.Update();
		_textDirectionY.Update();
		_textTotalSpawnByTime.Update();
		m_loadImageButton.Update();
		m_saveButton.Update();
		m_loadButton.Update();
		m_resetButton.Update();
		m_playButton.Update();
		m_playButton.IsPressed() ? m_playButton.SetText("Pause") : m_playButton.SetText("Play");
		m_exit.Update();
	}
	if (m_loadImageButton.IsPressed()) {
		ofFileDialogResult file = ofSystemLoadDialog("Load File", false, "sprites");

		sprite = file.getName() != "" ? file.getPath() : sprite;
		emissor.SetSprite(sprite);
		m_loadImageButton.SetToggleValue(false);
	}
	else if (m_loadBackground.IsPressed()) {
		ofFileDialogResult file = ofSystemLoadDialog("Load Background", false, "background");
		background = file.getName() != "" ? file.getPath() : background;
		m_loadImageButton.SetToggleValue(false);
	}

	else if (m_saveButton.IsPressed()) {
		DisableProcessParticle(emissor);
		//chama metodo save da classe Storage, parâmetros: ParticleEmission e string
		std::string tag = STORAGE.GetFather(m_tagButtons);
		if (tag == "NotSave") {
			ofSystemAlertDialog("Save cancelado!");
			m_saveButton.SetToggleValue(false);
		}
		else if (tag != "") {
			m_tagButtons.clear();
			ofVec2f center(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
			if (localPosition) {
				emissor.SetOrigin(emissor.GetOrigin() - center);
				emissor.SetDirection(emissor.GetDirection() - center);
			}
			STORAGE.save(emissor, tag);
			m_saveButton.SetToggleValue(false);
		}

	}
	// Verifica se o botao Load foi clicado e chama a funcao
	else if (m_loadButton.IsPressed()) {
		DisableProcessParticle(emissor);

		//chama metodo load da classe Storage, parâmetros: ParticleEmission e string
		Gui tmpGui;
		tmpGui.Init();
		STORAGE.load(tmpGui);
		CopyConfig(tmpGui);

		m_loadButton.SetToggleValue(false);
	}
	else if (m_resetButton.IsPressed()) {
		DisableProcessParticle(emissor);
		Init();
		emissor.m_particles.clear();
		m_resetButton.SetToggleValue(false);
	}

	// Atualiza as informacoes no Emissor
	if (changeValues || ParameterHasChanged(emissor)) {
		emissor.SetOrigin(Position());
		emissor.SetDirection(Direction());
		emissor.SetOpenAngle(angle);
		emissor.SetSpeed(velocity);
		emissor.SetLifeTime(lifeTime);
		emissor.SetSpawnTime(timeSpawn);
		emissor.SetColor(color);
		emissor.SetSizeParticle(radius);
		emissor.SetSprite(sprite);
		emissor.SetTotalOfSpawnParticle(_textTotalSpawnByTime.GetValue());
		emissor.ListSweeping(true);
		changeValues = false;
	}
}

void Gui::Draw() {
	gui.draw();
	m_saveButton.Draw();
	m_resetButton.Draw();
	m_loadButton.Draw();
	m_playButton.Draw();
	m_exit.Draw();
	m_loadImageButton.Draw();
	m_loadBackground.Draw();
	_textTotalSpawnByTime.Draw();
	_textPositionX.Draw();
	_textPositionY.Draw();
	_textDirectionX.Draw();
	_textDirectionY.Draw();
	if (localPosition) {
		DrawCenterAxis();
	}


	if (drawParameters) {
		DrawDirectionAndCone(Position(), Direction());
	}


	if (m_saveButton.IsPressed()) {
		for (int i = 0; i < m_tagButtons.size(); i++) {
			m_tagButtons[i].Draw();
		}
	}

}

void Gui::SetMousePosition(int x, int y) {
	mousePositon.set(x, y);
}

void Gui::ChangeDirectionAndPosition()
{
	/*
		Funcao para poder alterar a posicao da direcao e da origem caso os botoes de Toggle sejam selecionados
		Para confirmar a nova posicao, basta clicar com o botao direito do mouse
	*/

	// Altera somente a Direcao
	if (directionPosToMouse) {
		Direction(mousePositon);
		if (ofGetMousePressed(OF_MOUSE_BUTTON_1)) {
			directionPosToMouse = false;
		}
	}

	// Altera a Origem e a direcao
	if (worldPosToMouse) {
		antPosition = Position();
		Position(mousePositon);
		ofVec2f tmpDir = Direction() + (Position() - antPosition);

		if (ofGetMousePressed(OF_MOUSE_BUTTON_1)) {
			worldPosToMouse = false;
		}
	}

}

void Gui::DrawDirectionAndCone(const ofVec2f& posit, const ofVec2f& direct)
{
	// Desenha a direcao para onde sera gerado as particulas
	ofSetColor(255, 255, 255);
	ofVec3f start = ofVec3f(posit.x, posit.y, 0);
	ofVec3f end = ofVec3f(direct.x, direct.y, 0);
	ofDrawArrow(start, end, 10);


	// Desenha o cone mostrando onde sera gerado as particulas
	ofPath openAngle;
	openAngle.setArcResolution(360);
	ofVec2f tmp = ofVec2f(posit.x - direct.x, posit.y - direct.y);
	openAngle.arc(posit, -velocity * lifeTime / 2.0f, -velocity * lifeTime / 2.0f, 0, angle);
	openAngle.lineTo(posit);
	openAngle.setFilled(false);
	openAngle.setStrokeWidth(2);
	openAngle.rotate((atan2f(tmp.y, tmp.x) * 180.0f / PI) - angle / 2.0f, start);
	openAngle.draw();
}

void Gui::DrawCenterAxis() {
	ofVec2f center(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);
	ofSetColor(100, 100, 100);
	ofDrawLine(center.x - 150, center.y, center.x + 150, center.y);
	ofDrawLine(center.x, center.y - 150, center.x, center.y + 150);

}

bool Gui::ParameterHasChanged(const ParticleEmission &emissor) {
	// Verifica se os parametros do emissor e do gui estao diferentes
	changeValues = (
		emissor.GetOrigin() != Position() ||
		emissor.GetDirection() != Direction() ||
		emissor.GetOpenAngle() != angle ||
		emissor.GetSpeed() != velocity ||
		emissor.GetLifeTime() != lifeTime ||
		emissor.GetSpawnTime() != timeSpawn ||
		emissor.GetSizeParticle() != radius ||
		emissor.GetColor() != color ||
		emissor.GetSprite() != sprite ||
		emissor.GetTotalOfSpawnParticle() != _textTotalSpawnByTime.GetValue()
		);

	return changeValues;
}

void Gui::DisableProcessParticle(ParticleEmission &emissor) {
	m_playButton.SetToggleValue(false);
	emissor.SetParticleProcess(false);
}


void Gui::CopyConfig(Gui &config) {
	SetSprite(config.sprite);
	SetSizeParticle(config.size);
	SetOrigin(Position());
	SetDirection(Direction());
	SetOpenAngle(config.angle);
	SetLifeTime(config.lifeTime);
	SetSpeed(config.velocity);
	SetSpawnTime(config.timeSpawn);
	SetColor(config.color);
	SetTotalParticleSpawn(config._textTotalSpawnByTime.GetValue());
	SetRandomSpawn(config.randomSpawn);
}