#pragma once
#include "GameObject.h"

using namespace std;
#define GAMEMANAGER GameManager::instance()

class GameManager {
private:
	std::vector<GameObject*> objects;
	std::vector<GameObject*> dead;
	GameManager();
public:
	static GameManager& instance();
	void add(GameObject* object);
	void clear();
	void update(float secs, const ofVec2f& camera);
	void draw(const ofVec2f& camera);
	~GameManager();
};