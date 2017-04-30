#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	srand(time(NULL));

	//Inicia o player passado (posicao.x    , posicao.y         , speed);
	gamePlayer = new Player("Player", ofGetWidth() / 2, ofGetHeight() / 2, 500.0f);

	// Inicia o Estado do Game
	gameStats = new GameStats();
	gameStats->changeStats(0);

	// Inicia a contagem de tempo
	gameTime = new GameTime();
	startTime = 0;

	//Inicia o enemy
	enemys = new EnemyControl();

	// Inicia o tiro
	bullets = new BulletControl();

	// Configura o Editor de Particula
	partEditor.Setup();

	// Configura o Menu
	menu.Setup();
}

//--------------------------------------------------------------
void ofApp::update() {
	// Pega o tempo entre o ultimo frame e o atual
	float deltaTime = ofGetLastFrameTime();
	gameTime->TimeGame();
	int time = gameTime->GetTimeGame() / 100;

	// Verifica o estado atual do jogo se esta em menu, editor, jogo ou fim de jogo
	switch (gameStats->GetEstado())
	{
		// ------------------------------ MENU -------------------------------------------------
	case 0:
		gameStats->changeStats(menu.Update());
		break;


		// ------------------------------ GAME -------------------------------------------------
	case 1:
		ofSetBackgroundColor(255, 255, 255);
		if (startTime == 0)
		{
			startTime = 1;
			gameTime->StartTime();
		}
		// Atualiza a posicao do player
		gamePlayer->Update(deltaTime);

		// Cria novos enemys, atualiza a posição e elimina os que levaram dano
		enemys->Update(time, deltaTime, gamePlayer->GetPosition(), bullets);

		// Cria novos tiros, atualiza a posição e elimina os que sairam da tela e que receberam dano
		bullets->Update(gamePlayer, deltaTime);
		
		gameTime->EndTime();
		break;

		// ------------------------------ EDITOR -----------------------------------------------
	case 2:
		partEditor.Update(deltaTime);
		break;


		// ------------------------------ GAME OVER ---------------------------------------------
	case 3://GAME OVER
		break;
	}


}

//--------------------------------------------------------------
void ofApp::draw() {
	switch (gameStats->GetEstado())
	{

		//MENU
	case 0:
		menu.Draw();
		break;

		//GAME
	case 1:
		// Desenha o Player
		gamePlayer->Draw();

		// Desenha os tiros
		bullets->Draw();
		
		// Desenha os enemys
		enemys->Draw();

		break;

		//EDITOR
	case 2:
		partEditor.Draw();
		break;

		//GAME OVER
	case 3:
		break;
	}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == OF_KEY_BACKSPACE) {
		gameStats->changeStats(0);
	}


	switch (gameStats->GetEstado())
	{
	case 0://MENU
		break;
	case 1://GAME
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

	case 2://EDITOR
		if (key == 'h' || key == 'H') {
			//PROVISÓRIO: save tecla H
			partEditor.Save();
		}
		if (key == 'l' || key == 'L') {
			//PROVISÓRIO: save tecla L
			partEditor.Load();
			cout << "1 apertou L" << endl;
		}
		break;

	case 3://GAME OVER
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	if (key == OF_KEY_BACKSPACE) {
		gameStats->changeStats(0);
	}

	switch (gameStats->GetEstado())
	{
		//MENU
	case 0:
		break;

		//GAME
	case 1:
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

		//EDITOR
	case 2:
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
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
