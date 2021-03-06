#include "ParticleEditor.h"
#include "Storage.h"

ParticleEditor::ParticleEditor()
{
	m_guiEditor.Init();
}

void ParticleEditor::Setup() {
	m_guiEditor.Init();
	image.load("bgtest.jpg");
	camera.init(image);
	image.setAnchorPoint(image.getWidth() / 2, image.getHeight() / 2);
	m_particlesList = ParticleEmission(	ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f), 
							ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f - 50),
							50, 50, 2, 1.0f / 5.0f, 
							"/sprites/particula.png", 30);
}

void ParticleEditor::Update(float &deltaTime) {
	// Verifica se o botao Save foi clicado e chama a funcao
	m_guiEditor.Update(m_particlesList, camera.getPosition());
	m_particlesList.Update(deltaTime);

	if (clicked) {
		camera.update(deltaTime);
	}

}

void ParticleEditor::Draw() {

	image.draw(ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2) - camera.getPosition());
	m_particlesList.Draw();
	m_guiEditor.Draw();
}


void ParticleEditor::SetMousePosition(int &x, int &y) {
	m_guiEditor.SetMousePosition(x, y);
}

void ParticleEditor::SetBackground(string& bg) {
	background = bg;
}
