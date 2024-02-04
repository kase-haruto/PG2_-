#include "Enemy.h"
#include"Environment.h"
#include"CollisionManager.h"
#include"Stage.h"
Enemy::Enemy() :respawnCount_(0), respawnLimit_(3) {
	CollisionManager* collisionManager = CollisionManager::GetInstance();
	collisionManager->CollisionSubscrive(this);

	pos_ = { kWindowSize.x / 2.0f,200.0f };
	width_ = 64.0f;
	height_ = 64.0f;
	radius_ = width_ / 2.0f;
	gh_ = Novice::LoadTexture("white1x1.png");
	color_ = 0xa0f0faff;
	speed_ = 8.0f;
	Character::VertexInit();
	hp_ = 10;
	spawnTimer_ = 120;
	SetOBJType(ENEMY);
}

Enemy::~Enemy() {}

void Enemy::Init() {
	hp_ = 10;
	respawnCount_ = 0;
	isAlive_ = true;
}

void Enemy::SpawnInit() {
	hp_ = 10;
	spawnTimer_ = 120;
	respawnCount_++;
	isAlive_ = true;
}

void Enemy::Spawn() {
	if (respawnCount_ < respawnLimit_) {

		if (spawnTimer_ <= 0) {
			this->SpawnInit();
		}

	} else {//敵の最大リスポーン数を超えたらクリアにする
		Stage::isClear = true;
	}
}

void Enemy::OnCollision() {
	hp_--;
}

void Enemy::Reflection() {
	if (pos_.x + radius_ >= kWindowSize.x || pos_.x <= radius_) {
		speed_ *= -1;
	}
}

void Enemy::Move() {
	pos_.x += speed_;
	Character::VertexInit();
	this->Reflection();
}

void Enemy::Update() {
	if (isAlive_) {
		this->Move();
		if (hp_ <= 0) {
			isAlive_ = false;
		}

		isCollisionEnabled_ = true; //生きている間当たり判定をとるようにする

	} else {
		spawnTimer_--;
		this->Spawn();
		isCollisionEnabled_ = false;
	}
}

void Enemy::Draw() {
	//残機の表示
	Novice::ScreenPrintf(50, 50, "enemy：life = %d", respawnLimit_ - respawnCount_);

	if (isAlive_) {
		Character::Draw();
	}
}