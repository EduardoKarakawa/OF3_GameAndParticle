#include "ParticleEditor.h"
#include "Storage.h"

ParticleEditor::ParticleEditor()
{
	m_guiEditor.Init();
	tag = "";
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
	if (m_guiEditor.m_saveButton.IsPressed()) {
		m_particlesList.SetParticleProcess(false);
		Save();
		//m_guiEditor.m_saveButton.SetValue(false);
	}
	// Verifica se o botao Load foi clicado e chama a funcao
	else if (m_guiEditor.m_loadButton.IsPressed()) {
		m_particlesList.SetParticleProcess(false);
		Load();
		m_guiEditor.m_loadButton.SetValue(false);
	}
	else if (m_guiEditor.m_resetButton.IsPressed()) {
		Reset();
		m_particlesList.m_particles.clear();
		m_guiEditor.m_loadButton.SetValue(false);
	}


	m_particlesList.SetParticleProcess(m_guiEditor.m_playButton.IsPressed());
	m_guiEditor.Update(m_particlesList);
	m_particlesList.Update(deltaTime);

}

void ParticleEditor::Draw() {
	m_guiEditor.Draw();
	m_particlesList.Draw();
	if (m_guiEditor.m_saveButton.IsPressed()) {
		for (int i = 0; i < m_buttons.size(); i++) {
			m_buttons[i].Draw();
		}
	}
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

void ParticleEditor::Reset() {

	//chama metodo save da classe Storage, parâmetros: ParticleEmission e string

	STORAGE.reset(m_guiEditor, m_particlesList);
}

void ParticleEditor::Save() {

	//chama metodo save da classe Storage, parâmetros: ParticleEmission e string
	tag = STORAGE.GetFather(m_buttons);
	if (tag != "") {
		m_buttons.clear();
		STORAGE.save(m_particlesList, tag);
		m_guiEditor.m_saveButton.SetValue(false);
	}
}

void ParticleEditor::Load() {
	cout << "2 Entrou no ParticleEditor::Load()" << endl;

	//chama metodo load da classe Storage, parâmetros: ParticleEmission e string
	STORAGE.load(m_guiEditor);
	
}
