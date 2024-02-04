#pragma once
#include "InputManager.h"
#include"SceneManager.h"
#include<Novice.h>

class GameManager {
private:
	InputManager* inputManater;
	SceneManager* sceneManager;

public:
	GameManager();
	~GameManager();

	void Run();
};

