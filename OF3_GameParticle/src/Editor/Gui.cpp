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
void Gui::SetInitialColor(const ofColor& initialColor) {
	this->initialColor = initialColor;
	changeValues = true;
}
void Gui::SetFinalColor(const ofColor& finalColor) {
	this->finalColor = finalColor;
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

	// Muda a cor inicial das particulas
	gui.add(initialColor.setup("Initial Color: ", ofColor(255, 159, 17), ofColor(0, 0), ofColor(255, 255)));
	
	// Muda a cor final das particulas
	gui.add(finalColor.setup("Final Color: ", ofColor(255, 159, 17), ofColor(0, 0), ofColor(255, 255)));

	// Define se esta movimentando a origem ou a direcao para falso
	worldPosToMouse = false;
	directionPosToMouse = false;
	changeValues = true;

	font.load("Luna.ttf", 10, true, true, false, 0.3f, 0);
	// Botoes 
	//TOTAL SPAWN TIME 
	_textTotalSpawnByTime = IntTextBox("Total to Spawn:", MyButton::FONT_CENTER, 10, ofVec2f(_textTotalSpawnByTime.GetStringSize("Total to Spawn:").x + BORDER_LEFT, ofGetHeight() / 2 - 10), 1,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textTotalSpawnByTime.SetSize(70, 27);
	//_textTotalSpawnByTime.SetValue(0.0f);
	_textTotalSpawnByTime.LoadFont("Luna.ttf", 8, ofColor(255, 255, 255));
	_textTotalSpawnByTime.SetFontPosition(ofVec2f(0, ofGetHeight() / 2 + 10));
	_textTotalSpawnByTime.SetSprite("blue.png", "blue2.png");

	//POSITION X
	_textPositionX = IntTextBox("P X:", MyButton::FONT_CENTER, 10, ofVec2f(_textPositionX.GetStringSize("P X:").x + BORDER_LEFT, ofGetHeight() / 2 + 40),
		ofGetWidth() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textPositionX.SetSize(80, 27);
	_textPositionX.LoadFont("Luna.ttf", 8, ofColor(255, 255, 255));
	_textPositionX.SetFontPosition(ofVec2f(0, ofGetHeight() / 2 + 60));
	_textPositionX.SetSprite("blue.png", "blue2.png");

	//POSITION Y
	_textPositionY = IntTextBox("Y:", MyButton::FONT_CENTER, 10, ofVec2f(_textPositionY.GetStringSize("P X:").x + 100 + _textPositionY.GetStringSize("Y:").x + BORDER_LEFT, ofGetHeight() / 2 + 40),
		ofGetHeight() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textPositionY.SetSize(80, 27);
	_textPositionY.LoadFont("Luna.ttf", 8, ofColor(255, 255, 255));
	_textPositionY.SetFontPosition(ofVec2f(_textPositionY.GetStringSize("P X:").x + 90 + _textPositionY.GetStringSize("Y:").x, ofGetHeight() / 2 + 60));
	_textPositionY.SetSprite("blue.png", "blue2.png");

	//DIRECTION X
	_textDirectionX = IntTextBox("D X:", MyButton::FONT_CENTER, 10, ofVec2f(_textDirectionX.GetStringSize("D X:").x + BORDER_LEFT, ofGetHeight() / 2 + 80),
		ofGetWidth() / 2 - 200,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textDirectionX.SetSize(80, 27);
	_textDirectionX.LoadFont("Luna.ttf", 8, ofColor(255, 255, 255));
	_textDirectionX.SetFontPosition(ofVec2f(0, ofGetHeight() / 2 + 100));
	_textDirectionX.SetSprite("blue.png", "blue2.png");

	//DIRECTION Y
	_textDirectionY = IntTextBox("Y:", MyButton::FONT_CENTER, 10,
		ofVec2f(_textPositionY.GetStringSize("P X:").x + 100 + _textPositionY.GetStringSize("Y:").x + BORDER_LEFT, ofGetHeight() / 2 + 80),
		ofGetHeight() / 2,
		ofColor(150, 150, 150),
		ofColor(170, 170, 170),
		ofColor(255, 255, 255));
	_textDirectionY.SetSize(80, 27);
	_textDirectionY.LoadFont("Luna.ttf", 8, ofColor(255, 255, 255));
	_textDirectionY.SetFontPosition(ofVec2f(_textDirectionY.GetStringSize("D X:").x + 90 + _textDirectionY.GetStringSize("Y:").x, ofGetHeight() / 2 + 100));
	//_textDirectionY.SetFontPosition(ofVec2f(0,ofGetHeight()/2));
	_textDirectionY.SetSprite("blue.png", "blue2.png");


	//IMAGE BUTTON
	m_loadImageButton = MyButton("Image Load", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight()/2 + 120, 120, 30);
	//m_loadImageButton.SetPosition(0, 500);
	m_loadImageButton.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255,255,255));
	m_loadImageButton.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_loadImageButton.SetSprite("blue.png", "blue2.png");

	//BACKGROUND BUTTON
	m_loadBackground = MyButton("Background", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight()/2 + 160, 120, 30);
	m_loadBackground.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_loadBackground.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_loadBackground.SetSprite("blue.png", "blue2.png");

	//RESET BUTTON
	m_resetButton = MyButton("Reset", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight()/2 + 200, 120, 30);
	m_resetButton.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_resetButton.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_resetButton.SetSprite("blue.png", "blue2.png");

	//SAVE BUTTON
	m_saveButton = MyButton("Save", MyButton::FONT_CENTER, 0, false, 0, ofGetHeight() - 40, 100, 40);
	m_saveButton.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_saveButton.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_saveButton.SetSprite("blue.png", "blue2.png");
	
	//LOAD BUTTON
	m_loadButton = MyButton("Load", MyButton::FONT_CENTER, 0, false, 103, ofGetHeight() - 40, 100, 40);
	m_loadButton.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_loadButton.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_loadButton.SetSprite("blue.png", "blue2.png");

	//PLAY BUTTON
	m_playButton = MyButton("Play", MyButton::FONT_CENTER, 0, false, ofGetWidth() / 2.0f, ofGetHeight() - 40, 100, 40);
	m_playButton.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_playButton.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_playButton.SetSprite("blue.png", "blue2.png");

	//EXIT BUTTON
	m_exit = MyButton("Exit", MyButton::FONT_CENTER, 0, false, ofGetWidth() - 100, ofGetHeight() - 40, 100, 40);
	m_exit.LoadFont("Ancherr-Personal-Use.ttf", 20, ofColor(255, 255, 255));
	m_exit.SetFontPosition(MyButton::FONT_CENTER, 0.0f);
	m_exit.SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
	m_exit.SetSprite("blue.png", "blue2.png");

	sprite = "/sprites/particula.png";
	background = "bgtest.png";
}

void Gui::Update(ParticleEmission &emissor) {

	if (!m_saveButton.IsPressed()) {
		emissor.SetParticleProcess(m_playButton.IsPressed());
		emissor.SetRandomDirection(randomSpawn);
		ChangeDirectionAndPosition();


		// Reajusta a posicao dos botoes de acordo com o tamanho da tela
		m_loadImageButton.SetPosition(0, ofGetHeight()/2 + 120);
		m_loadBackground.SetPosition(0, ofGetHeight()/2 + 160);
		m_resetButton.SetPosition(0, ofGetHeight()/2 + 200);
		m_saveButton.SetPosition(0, ofGetHeight() - 40);
		m_loadButton.SetPosition(103, ofGetHeight() - 40);
		m_playButton.SetPosition(ofGetWidth() / 2.0f, ofGetHeight() - 40);

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
		emissor.SetInitialColor(initialColor);
		emissor.SetFinalColor(finalColor);
		emissor.SetSizeParticle(radius);
		emissor.SetSprite(sprite);
		emissor.SetTotalOfSpawnParticle(_textTotalSpawnByTime.GetValue());
		emissor.ListSweeping(true);
		changeValues = false;
	}
}

void Gui::Draw() {
	
	//font.drawString("Position:", 0, ofGetHeight() / 2 + 100);
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
		emissor.GetInialColor() != initialColor ||
		emissor.GetFinalColor() != finalColor ||
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
	SetInitialColor(config.initialColor);
	SetFinalColor(config.finalColor);
	SetTotalParticleSpawn(config._textTotalSpawnByTime.GetValue());
	SetRandomSpawn(config.randomSpawn);
}