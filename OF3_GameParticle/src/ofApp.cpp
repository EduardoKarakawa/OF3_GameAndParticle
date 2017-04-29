#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	srand(time(NULL));

	//Inicia o player passado (posicao.x    , posicao.y         , speed);
	gamePlayer = new Player(ofGetWidth() / 2, ofGetHeight() / 2, 500.0f);
	
	// Inicia o Estado do Game
	gameStats = new GameStats();
	gameStats->changeStats(0);

	// Inicia a contagem de tempo
	gameTime = new GameTime();

	lastTime = 0;
	startTime = 0;

	ofVec2f zero;
	zero.set(0, 0);
	bulletP.push_back(new Bullet(zero, -1));
	enemy.push_back(new Enemy(zero));

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
	int time = gameTime->GetTimeGame()/100;

	// Verifica o estado atual do jogo se esta em menu, editor, jogo ou fim de jogo
	switch (gameStats->GetEstado())
	{
		// ------------------------------ MENU -------------------------------------------------
	case 0:
		gameStats->changeStats(menu.Update());
		break;


		// ------------------------------ GAME -------------------------------------------------
	case 1:
		if (startTime == 0)
		{
			startTime = 1;
			gameTime->StartTime();
		}
		// Atualiza a posicao do player
		gamePlayer->Update(deltaTime);

		// Verifica se o player atirou e cria um novo tiro
		if (gamePlayer->GetShooting())
		{
			gamePlayer->AddCounter();
			bulletP.push_back(new Bullet(gamePlayer->GetPosition(), gamePlayer->GetArrowKey()));
		}

		// Verifica se exitem tiros para serem processados
		if (bulletP.size() > 1)
		{
			// Percorre a lista de tiros para atualizar a posicao deles
			for (int i = 0; i < bulletP.size(); i++)
			{
				bool bulletLife = true;
				bulletLife = bulletP.at(i)->Update(deltaTime);
				// Percorre a lista de enemys para verificar a colisão com o tiro
				for (int j = 0; j < enemy.size(); j++)
				{
					if (enemy.at(j)->enemyLife(bulletP.at(i)->GetPosition()) == false)
					{
						enemy.erase(enemy.begin() + j);
					}
				}
				if (bulletLife == false) bulletP.erase(bulletP.begin() + i);
			}

		}

		//Verfica se está no momento para criar novos inimigos
		if (time % 6 == 0 && time != lastTime)
		{
			lastTime = time;
			enemy.push_back(new Enemy(gamePlayer->GetPosition()));
		}

		//Verifica se exitem inimigos para serem processados
		if (enemy.size() > 1)
		{
			// Percorre a lista de inimigos para atualizar a posição deles
			for (int i = 0; i < enemy.size(); i++)
			{
				enemy.at(i)->Update(gamePlayer->GetPosition(), deltaTime);
			}
		}

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
		gamePlayer->Draw();	// Desenha o Player

		// Desenha os tiros
		if (bulletP.size() > 1)
		{
			for (int i = 1; i < bulletP.size(); i++)
			{
				bulletP.at(i)->Draw();
			}
		}

		// Desenha os Inimigos
		if (enemy.size() > 1)
		{
			for (int i = 1; i < enemy.size(); i++)
			{
				enemy.at(i)->Draw();
			}
		}

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
			//gui->hide();
		}
		break;
	case 3://GAME OVER
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
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
