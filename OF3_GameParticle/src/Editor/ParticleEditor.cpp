#include "ParticleEditor.h"
#include "Storage.h"

ParticleEditor::ParticleEditor()
{
	m_guiEditor.Init();
}

void ParticleEditor::Setup() {
	LoadParticles();
	m_particlesList = ParticleEmission(	ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f), 
							ofVec2f(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f - 50),
							50, 50, 2, 1.0f / 5.0f, 
							"/sprites/particula.png", 30);
}


void ParticleEditor::Update(float &deltaTime) {
	m_guiEditor.Update(m_particlesList);
	m_particlesList.Update(deltaTime);

}

void ParticleEditor::Draw() {
	m_guiEditor.Draw();
	m_particlesList.Draw();
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

void ParticleEditor::Save() {
	STORAGE.save(m_particlesList, "teste.xml");
}

void ParticleEditor::Load() {
	cout << "2 Entrou no ParticleEditor::Load()" << endl;
	STORAGE.load(m_particlesList, "teste.xml");
	
}
