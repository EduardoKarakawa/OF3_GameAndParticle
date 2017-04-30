#include "ParticleEditor.h"
#include "Storage.h"

ParticleEditor::ParticleEditor()
{
	//m_guiEditor.Init();
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
	m_guiEditor.Update(m_particlesList);
	m_particlesList.Update(deltaTime);

	if (m_guiEditor.m_saveButton.IsPressed()) {
		Save();
		m_guiEditor.m_saveButton.SetValue(false);
	}
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

	//chama metodo save da classe Storage, parâmetros: ParticleEmission e string

	STORAGE.save(m_particlesList, "teste.xml");
}

void ParticleEditor::Load() {
	cout << "2 Entrou no ParticleEditor::Load()" << endl;

	//chama metodo load da classe Storage, parâmetros: ParticleEmission e string
	STORAGE.load(m_guiEditor, "teste.xml");
	
}
