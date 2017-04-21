#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	//Inicia o player passado (posicao.x    , posicao.y         , speed);

	gamePlayer = new Player(ofGetWidth() / 2, ofGetHeight() / 2, 500.0f);

	gameS = new GameStats();
	gameS->changeStats(1);

	partEditor.Setup();


}

//--------------------------------------------------------------
void ofApp::update() {
	// Pega o tempo entre o ultimo frame e o atual
	float deltaTime = ofGetLastFrameTime();

	// Verifica o estado atual do jogo se esta em menu, editor, jogo ou fim de jogo
	switch (gameS->GetEstado())
	{

		// ------------------------------ MENU -------------------------------------------------
		case 0:	
			break;


		// ------------------------------ EDITOR -----------------------------------------------
		case 1:
			partEditor.Update(deltaTime);
			break;


		// ------------------------------ GAME -------------------------------------------------
		case 2:
			
			// Atualiza a posicao do player
			gamePlayer->Update(deltaTime);

			break;


		// ------------------------------ GAME OVER ---------------------------------------------
		case 3://GAME OVER
			break;
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (gameS->GetEstado())
	{
		
		//MENU
		case 0:
			break;

		//EDITOR
		case 1:
			partEditor.Draw();
			break;

		//GAME
		case 2:
			gamePlayer->Draw();


			break;

		//GAME OVER
		case 3:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (gameS->GetEstado())
	{
		case 0://MENU
			break;
		case 1://EDITOR
			if (key == 'h' || key == 'H') {
				//gui->hide();
			}
			break;
		case 2://GAME
			if (key == OF_KEY_UP)
				gamePlayer->Press(0);
			if (key == OF_KEY_DOWN)
				gamePlayer->Press(1);
			if (key == OF_KEY_RIGHT)
				gamePlayer->Press(2);
			if (key == OF_KEY_LEFT)
				gamePlayer->Press(3);
			if (key == 'w' || key == 'W')
				gamePlayer->Press(4);
			if (key == 's' || key == 'S')
				gamePlayer->Press(5);
			if (key == 'd' || key == 'D')
				gamePlayer->Press(6);
			if (key == 'a' || key == 'A')
				gamePlayer->Press(7);
			if (key == 'z' || key == 'Z')
				gamePlayer->Press(8);
			if (key == GLFW_KEY_SPACE)
				gamePlayer->Press(9);
			break;
		case 3://GAME OVER
			break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (gameS->GetEstado())
	{
		//MENU
		case 0:
			break;
	
		//EDITOR
		case 1:
			break;

		//GAME
		case 2:
			if (key == OF_KEY_UP)
				gamePlayer->Release(0);
			if (key == OF_KEY_DOWN)
				gamePlayer->Release(1);
			if (key == OF_KEY_RIGHT)
				gamePlayer->Release(2);
			if (key == OF_KEY_LEFT)
				gamePlayer->Release(3);
			if (key == 'w' || key == 'W')
				gamePlayer->Release(4);
			if (key == 's' || key == 'S')
				gamePlayer->Release(5);
			if (key == 'd' || key == 'D')
				gamePlayer->Release(6);
			if (key == 'a' || key == 'A')
				gamePlayer->Release(7);
			if (key == 'z' || key == 'Z')
				gamePlayer->Release(8);
			if (key == GLFW_KEY_SPACE)
				gamePlayer->Release(9);
			break;

		//GAME OVER
		case 3:
			break;
	}
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	partEditor.SetMousePosition(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	switch (gameS->GetEstado())
	{
	//MENU
	case 0: 
		break;

	//EDITOR
	case 1: 
		//gui->resize(w, h);
		break;

	//GAME
	case 2:
		break;

	//GAME OVER
	case 3:
		break;

	}
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
