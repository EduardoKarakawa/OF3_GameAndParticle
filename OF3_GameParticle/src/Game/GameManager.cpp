#include "GameManager.h"

GameManager::GameManager() {

}

void GameManager::add(GameObject* object) {
	object->init();
	objects.push_back(object);
}

void GameManager::clear() {
	for each (GameObject* object in objects) {
		delete object;
	}
	objects.clear();
}

void GameManager::update(float secs, const ofVec2f& camera) {
	vector<GameObject*> toDelete;
	vector<GameObject*> alive;

	swap(toDelete, dead);

	for each (GameObject* object in objects) {
		object->update(ofGetLastFrameTime(), camera);
		if (!object->isAlive()) {
			dead.push_back(object);
		}
		else {
			alive.push_back(object);
		}
	}
	for (int i = 0; i < objects.size()-1; i++) {
		for (int j = i+1; j < objects.size(); j++) {
			if (objects[i]->bounds().intersects(objects[j]->bounds())) {
				objects[i]->collidedWith(objects[j]);
				objects[j]->collidedWith(objects[i]);
			}
		}
	}
	for each (GameObject* object in toDelete) {
		delete object;
	}
	swap(alive, objects);
}

void GameManager::draw(const ofVec2f& camera) {
	for each (GameObject* object in objects) {
		object->draw(camera);
	}
}

GameManager& GameManager::instance() {
	static GameManager manager;
	return manager;
}

GameManager::~GameManager() {
	clear();
}