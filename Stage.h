#pragma once
#include "Player.h"
#include"Enemy.h"
#include"CollisionManager.h"

class Stage {

public:
	static bool isClear;
	static bool isGameOver;

private:
	Collider* player;
	Collider* enemy;

	// シングルトンインスタンスを保持
	 CollisionManager* collision = CollisionManager::GetInstance();

public:
	Stage();
	~Stage();

	void Init();
	void Update();
	void Draw();
};

