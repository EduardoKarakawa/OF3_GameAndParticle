#include "GameControl.h"

GameControl::GameControl() {

	m_player = Player("Player", ofGetWidth() / 2, ofGetHeight() / 2, 300.0f);	//Inicia o player passado (posicao.x, posicao.y, speed);

	m_enemyControl = EnemyControl();	//Inicia o enemy

	m_keyInput.Up = false;
	m_keyInput.Down = false;
	m_keyInput.Left = false;
	m_keyInput.Right = false;
	m_keyInput.MouseLeft = false;

	m_exit = MyButton("Sair", false, ofGetWidth() - 100, ofGetHeight() - 50, 100, 50);
	m_exit.SetColor(ofColor(120, 120, 120), ofColor(80, 80, 80));
}

void GameControl::Update(float &deltatime, GameStats &status) {
	m_player.Update(deltatime);
	m_enemyControl.Update(deltatime, m_player, status);

	if (!m_keyInput.Up && !m_keyInput.Down && !m_keyInput.Left && !m_keyInput.Right) {
		m_player.SetDirectionX(0);
		m_player.SetDirectionY(0);
	}

	m_player.Shooting(m_keyInput.MouseLeft);
	m_exit.Update();
}

void GameControl::Draw() {

	m_player.Draw();
	m_enemyControl.Draw();
	m_exit.Draw();
}

void GameControl::Key(const int &key) {
	if (key == 'W' || key == 'w') {
		m_player.SetDirectionY(-1);
		m_keyInput.Up = true;
	}
	else if (key == 'S' || key == 's') {
		m_player.SetDirectionY(1);
		m_keyInput.Down = true;
	}


	if (key == 'A' || key == 'a') {
		m_player.SetDirectionX(-1);
		m_keyInput.Left = true;
	}
	else if (key == 'D' || key == 'd') {
		m_player.SetDirectionX(1);
		m_keyInput.Right = true;
	}

	if (key == OF_MOUSE_BUTTON_1) {
		m_keyInput.MouseLeft = true;
	}
}

void GameControl::KeyRelease(const int &key) {
	if (key == 'W' || key == 'w')
		m_keyInput.Up = false;
	if (key == 'S' || key == 's')
		m_keyInput.Down = false;
	if (key == 'A' || key == 'a')
		m_keyInput.Left = false;
	if (key == 'D' || key == 'd')
		m_keyInput.Right = false;
	if (key == OF_MOUSE_BUTTON_1)
		m_keyInput.MouseLeft = false;

}


GameControl::~GameControl(){}

