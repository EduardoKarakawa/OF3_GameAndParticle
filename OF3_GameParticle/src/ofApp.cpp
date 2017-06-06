#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	srand(time(NULL));

	_particleEditor.Setup();	// Configura o Editor de Particula
	_game = GameControl();
	_gameStatus = GameStats();
	_menu.Setup();	// Configura o Menu
}

//--------------------------------------------------------------
void ofApp::update() {
	// Pega o tempo entre o ultimo frame e o atual
	_deltaTime = ofGetLastFrameTime();


	// Verifica o estado atual do jogo se esta em menu, editor, jogo ou fim de jogo
	switch (_gameStatus.GetStatus())
	{
		// ------------------------------ MENU -------------------------------------------------
	case 0:
		_gameStatus.ChangeStats(
			_menu.Update()
		);
		break;


		// ------------------------------ GAME -------------------------------------------------
	case 1:
		ofSetBackgroundColor(200, 200, 200);
		if (_gameStatus.GetStatus() != _gameStatus.GetPreviusStatus()) {
			_gameStatus.ChangeStats(1);
			_game = GameControl();
		}
		else {
			_game.Update(_deltaTime, _gameStatus);
			if (_game.m_exit.IsPressed()) {
				_game.m_exit.SetToggleValue(false);
				_gameStatus.ChangeStats(0);
			}
		}
		break;

		// ------------------------------ EDITOR -----------------------------------------------
	case 2:
		_particleEditor.Update(_deltaTime);
		if (_particleEditor.m_guiEditor.m_exit.IsPressed()) {
			_particleEditor.m_guiEditor.m_exit.SetToggleValue(false);
			_gameStatus.ChangeStats(0);
		}
		break;


		// ------------------------------ GAME OVER ---------------------------------------------
	case 3://GAME OVER
		break;
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (_gameStatus.GetStatus())
	{
		//MENU
	case 0:
		_menu.Draw();
		break;

		//GAME
	case 1:
		_game.Draw();

		break;

		//EDITOR
	case 2:
		_particleEditor.Draw();
		break;

		//GAME OVER
	case 3:
		break;
	}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	switch (_gameStatus.GetStatus())
	{
		case 0://MENU
			break;

		case 1://GAME
			_game.Key(key);
			break;

		case 2://EDITOR
			if (key == 'm' || key == 'M') {
				_particleEditor.m_guiEditor.MoveOriginParticle();
			}
			if (key == 'd' || key == 'D') {
				_particleEditor.m_guiEditor.MoveDirectionParticle();
			}
			break;

		case 3://GAME OVER
			break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (_gameStatus.GetStatus())
	{
	case 0://MENU
		break;

	case 1://GAME
		_game.KeyRelease(key);
		break;

	case 2://EDITOR
		//if (key == 'm' || key == 'M') {
		//	_particleEditor.m_guiEditor.MoveOriginParticle();
		//}
		//if (key == 'd' || key == 'D') {
		//	_particleEditor.m_guiEditor.MoveDirectionParticle();
		//}
		break;

	case 3://GAME OVER
		break;

	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	switch (_gameStatus.GetStatus())
	{

	case 1://GAME

		break;

	case 2://EDITOR
		_particleEditor.SetMousePosition(x, y);
		break;
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	switch (_gameStatus.GetStatus())
	{

	case 1://GAME
		_game.Key(button);
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	switch (_gameStatus.GetStatus())
	{

	case 1://GAME
		_game.KeyRelease(button);
		break;
	}
}