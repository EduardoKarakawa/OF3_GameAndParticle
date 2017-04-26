#include "Menu.h"
void Menu::Setup()
{
	m_buttonList.push_back(MyButton("Start Game", false, ofVec2f(ofGetWidth() / 2.0f - 50, (ofGetHeight() / 2.0f) - 150 - 70.0f), 100, 70));
	m_buttonList.push_back(MyButton("Particle Editor", false, ofVec2f(ofGetWidth() / 2.0f - 100, (ofGetHeight() / 2.0f) - 70.0f), 200, 70));
	m_buttonList.push_back(MyButton("Exit", false, ofVec2f(ofGetWidth() / 2.0f - 50, (ofGetHeight() / 2.0f) + 150 - 70.0f), 100, 70));
	for (int i = 0; i < m_buttonList.size(); i++) {
		m_buttonList[i].SetFontColor(50,50,50,255);
		m_buttonList[i].SetColor(ofColor(255, 110, 0), ofColor(150, 130, 0));
	}
}

int Menu::Update() {
	m_option = 0;

		ofVec2f tmpMousePos = ofVec2f(ofGetMouseX(), ofGetMouseY());
		for (int i = 0; i < m_buttonList.size(); i++) {
			m_buttonList[i].Update();
			if (m_buttonList[i].IsPressed()) {
				m_buttonList[i].SetValue(false);
				return i + 1;
			}
		}
	
	return 0;
}
void Menu::Draw() {
	for (MyButton i : m_buttonList) {
		i.Draw();
	}

}
