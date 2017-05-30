#include "ParticleEditor.h"
#include "Storage.h"

ParticleEditor::ParticleEditor()
{
	m_guiEditor.Init();
}

void ParticleEditor::Setup() {
	m_guiEditor.Init();
	LoadParticles();
	m_particlesList = ParticleEmission(	ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f), 
							ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f - 50),
							50, 50, 2, 1.0f / 5.0f, 
							"/sprites/particula.png", 30);
}

void ParticleEditor::Update(float &deltaTime) {
	// Verifica se o botao Save foi clicado e chama a funcao
	m_guiEditor.Update(m_particlesList);
	m_particlesList.Update(deltaTime);

}

void ParticleEditor::Draw() {
	m_particlesList.Draw();
	m_guiEditor.Draw();
	/*
	ofSetColor(255, 255, 255);
	ofDrawBitmapString(" D - Muda a direcao\n M - Muda posicao", ofVec2f(ofGetWidth() / 2.0f, 25));*/
}

void ParticleEditor::LoadParticles()
{
	ofDirectory directory("/particles");
	if (directory.isDirectory())
	{
		directory.allowExt("txt");
		directory.listDir();
	}
}

void ParticleEditor::SetMousePosition(int &x, int &y) {
	m_guiEditor.SetMousePosition(x, y);
}
