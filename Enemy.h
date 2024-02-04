#pragma once
#include "Character.h"

class Stage;

class Enemy :
    public Character {
private:
	int spawnTimer_;

	int respawnLimit_;
	int respawnCount_;

private:
	void Move();
	void Spawn();
	void SpawnInit();
	void Reflection();

public:
	Enemy();
	~Enemy();

	void OnCollision()override;

	void Init();
	void Update();
	void Draw()override;

	void spawnCountReset() { respawnCount_ = 0; }
};

