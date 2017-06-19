#include "Game.h"
#include "GameManager.h"
#include "Shoot.h"

void Game::init() {
	background.load("bg1.jpg");
	camera.init(ofVec2f(background.getWidth(), background.getHeight()));
	player = new Player(ofVec2f(background.getWidth() / 2, background.getHeight() / 2));
	//Player* player2 = new Player(ofVec2f(background.getWidth() / 4, background.getHeight() / 2));
	GAMEMANAGER.add(player);
	GAMEMANAGER.add(new Player(ofVec2f(background.getWidth() / 4, background.getHeight() / 2)));
}

void Game::update(float secs) {
	camera.update(player->getPosition());
	player->setLimits(ofVec2f(background.getWidth(), background.getHeight()));
	GAMEMANAGER.update(secs, camera.getPosition());
	if ((OF_MOUSE_BUTTON_1)) {
		GAMEMANAGER.add(new Shoot(player->getHandPosition(), camera.getPosition()));
	}
}

void Game::draw() {
	background.draw(ofVec2f(0,0)-camera.getPosition());
	GAMEMANAGER.draw(camera.getPosition());
}