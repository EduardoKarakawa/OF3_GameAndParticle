#include "Gui.h"

void Gui::SetSprite(string sprite) { this->sprite = sprite; }
void Gui::SetOrigin(ofVec2f origin) { this->worldPos = origin; }
void Gui::SetDirection(ofVec2f direction) { this->direction = direction;}
void Gui::SetOpenAngle(float openAngle) { this->angle = openAngle; }
void Gui::SetSpeed(float speed) { this->velocity = speed; }
void Gui::SetSizeParticle(float radius) { this->radius = radius; }
void Gui::SetLifeTime(float lifeTime) { this->lifeTime = lifeTime; }
void Gui::SetSpawnTime(float timeSpawn) { this->timeSpawn = timeSpawn; }
void Gui::SetColor(ofColor color) { this->color = color; }


void Gui::Init() {
	gui.setup();
	// Desenha a direcao e cone de spawn
	gui.add(drawParameters.setup		("Show Direction/Cone", true));

	// Define o tempo de vida da particula
	gui.add(lifeTime.setup				("Life Time: ", 1.5f, 1.0f / 500.0f, 25));
	
	// Ajusta o tempo de spawn de uma particula
	gui.add(timeSpawn.setup				("Time Spawn: ", 0.03f, 1.0f / 500.0f, 1.0f));
	
	// Angulo de abertura para o emissor
	gui.add(angle.setup					("Open Angle: ", 30, 1, 360)); 
	
	// Define a velocidade com que a particula movimenta
	gui.add(velocity.setup				("Velocity: ", 500, 0, 1000));

	// Raio para definir o tamanho da particula
	gui.add(radius.setup				("Radius Particle: ", 30, 10, 300));

	// Habilita para mover para o mouse
	gui.add(worldPosToMouse.setup		("Origin to Mouse", false));

	//Slider para setar a Posicao de Origem
	gui.add(worldPos.setup				("Position Emissor: ",	ofVec2f(ofGetWidth()*.5, ofGetHeight()*.5), 
																ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));

	// Habilita para mover para o mouse
	gui.add(directionPosToMouse.setup	("Direction to Mouse", false));

	//Slider para setar a Direcao
	gui.add(direction.setup				("Direction: ",	ofVec2f(ofGetWidth()*.4, ofGetHeight()*.5),
														ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight()))); 
	// Muda a cor das particulas
	gui.add(color.setup					("Color: ", ofColor(255, 159, 17), ofColor(0, 0), ofColor(255, 255)));

	// Botao de save
	gui.add(saveButton.setup			("Salve", false, 100, 50));

	sprite = "/sprites/particula.png";
}


void Gui::Update(ParticleEmission &emissor) {



	ChangeDirectionAndPosition();

	emissor.SetOrigin(worldPos);
	emissor.SetDirection(direction);
	emissor.SetOpenAngle(angle);
	emissor.SetSpeed(velocity);
	emissor.SetLifeTime(lifeTime);
	emissor.SetSpawnTime(timeSpawn);
	emissor.SetSprite(sprite);
	emissor.SetSizeParticle(radius);
	emissor.SetColor(color);

	if (saveButton) {
		saveButton = false;
	}
}

void Gui::Draw() {

	if (!buttonHide) {
		gui.draw();
	}
	if (drawParameters) {
		DrawDirectionAndCone(worldPos, direction);
	}



}


void Gui::Hide() {
	buttonHide = !buttonHide;
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
		direction = mousePositon;
		if (ofGetMousePressed(OF_MOUSE_BUTTON_3)) {
			directionPosToMouse = false;
		}
	}

	// Altera somente a Origem
	if (worldPosToMouse) {
		antPosition = worldPos;
		worldPos = mousePositon;
		direction = ofVec2f(direction) + (ofVec2f(worldPos) - antPosition);

		if (ofGetMousePressed(OF_MOUSE_BUTTON_3)) {
			worldPosToMouse = false;
		}
	}

}


void Gui::DrawDirectionAndCone(ofVec2f posit, ofVec2f direct)
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
