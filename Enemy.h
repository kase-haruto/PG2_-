#pragma once
#include "Character.h"

class Enemy :
    public Character {
private:
	int spawnTimer_;

private:
	void Move();
	void Spawn();

public:
	Enemy();
	~Enemy();

	void OnCollision()override;

	void Init();
	void Update();
	void Draw()override;
};

