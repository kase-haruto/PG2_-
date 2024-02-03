#pragma once
#include "Player.h"
#include"Enemy.h"
#include"CollisionManager.h"

class Stage {

private:
	Collider* player;
	Collider* enemy;

	// シングルトンインスタンスを保持
	 CollisionManager* collision = CollisionManager::GetInstance();;

public:
	Stage();
	~Stage();

	void Init();
	void Update();
	void Draw();
};

