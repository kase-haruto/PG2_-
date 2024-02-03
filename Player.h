#pragma once
#include "Character.h"
#include"Bullet.h"
#include<vector>
#include<memory>

class Player final :
	public Character {
private:
	Vec2f velocity_;
	std::vector<std::unique_ptr<Bullet>> bullets_;

private:
	void Move();
	void Shoot();
	void InitializeBullets();
	void DeleteInactive(); //使用していない弾の配列の削除

public:
	Player();
	~Player();

	void OnCollision() override;

	void Init();
	void Update()override;
	void Draw()override;


	std::vector<std::unique_ptr<Bullet>>& GetBullets();
};
