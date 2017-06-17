#include "Menu.h"
void Menu::Setup()
{
	particle.load("Luna.ttf", 50, true, true, false, 0.3f, 0);
	editor.load("Luna.ttf", 35, true, true, true, 1.0f, 0);
	m_buttonList.push_back(MyButton("Game", MyButton::FONT_CENTER, 2.0f, false, ofVec2f(ofGetWidth() / 2 - 100, (ofGetHeight() / 2)), 200, 70));
	m_buttonList.push_back(MyButton("Editor", MyButton::FONT_CENTER, 2.0f, false, ofVec2f(ofGetWidth() / 2 - 100, (ofGetHeight() / 2) + 100), 200, 70));
	//m_buttonList.push_back(MyButton("Exit", false, ofVec2f(ofGetWidth() / 2 - 100, (ofGetHeight() / 2) + 200), 200, 70));
	for (int i = 0; i < m_buttonList.size(); i++) {
		//m_buttonList[i].LoadFont("thin.ttf", 24, ofColor::white);
		m_buttonList[i].SetFontColor(0, 0, 0, 255);
		m_buttonList[i].SetColor(ofColor(255, 255, 255), ofColor(255, 255, 255));
		m_buttonList[i].SetSprite("blue.png", "blue2.png");
	}

	particles.push_back(ParticleEmission(ofVec2f(0, ofGetHeight() / 2), ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), 187.68f, 255.f, 25.f, 0.25f,
		"snow.png", ofRandom(18, 40), ofColor(255, 255, 255)));
	particles.push_back(ParticleEmission(ofVec2f(ofGetWidth(), ofGetHeight() / 2), ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(-200, 0), 187.68f, 255.f, 25.f, 0.25f,
		"snow.png", ofRandom(18, 40), ofColor(0, 178, 255)));
	particles.push_back(ParticleEmission(ofVec2f(ofGetWidth()/2, ofGetHeight() / 2), ofVec2f(ofGetWidth() / 2, ofGetHeight() / 2), ofVec2f(ofRandom(-500, 500), ofRandom(-500,500)), 360.f, 255.f, 25.f, 0.25f,
		"snow.png", ofRandom(18, 40), ofColor(219, 73, 172)));
}

int Menu::Update() {
	m_option = 0;

	ofVec2f tmpMousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
	for (int i = 0; i < m_buttonList.size(); i++) {
		m_buttonList[i].Update();
		if (m_buttonList[i].IsPressed()) {
			m_buttonList[i].SetToggleValue(false);
			return i + 1;
		}
	}

	for (int i = 0; i < particles.size(); i++) {
		particles[i].Update(ofGetLastFrameTime());
	}
	return 0;
}
void Menu::Draw() {
	ofSetColor(255, 255, 255);
	ofBackground(0, 0, 0);
	for (int i = 0; i < particles.size(); i++) {
		particles[i].Draw();
	}
	ofSetColor(ofColor::white);
	particle.drawString("PARTICLE", 320, 200.0f);
	ofSetColor(ofColor::blueSteel);
	editor.drawString("EDITOR", 410, 250.0f);
	ofSetColor(255, 255, 255);
	for (MyButton i : m_buttonList) {
		i.Draw();
	}
}
