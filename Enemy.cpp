#include "Enemy.h"
#include"Environment.h"
#include"CollisionManager.h"

Enemy::Enemy() {
	pos_ = { kWindowSize.x / 2.0f,200.0f };
	width_ = 64.0f;
	height_ = 64.0f;
	radius_ = width_ / 2.0f;
	gh_ = Novice::LoadTexture("white1x1.png");
	color_ = 0xa0f0faff;
	Character::VertexInit();
	spawnTimer_ = 120;

	CollisionManager* collisionManager = CollisionManager::GetInstance();
	collisionManager->CollisionSubscrive(this);
}

Enemy::~Enemy() {}

void Enemy::Init() {
	spawnTimer_ = 120;
	isAlive_ = true;
}

void Enemy::Spawn() {
	if (spawnTimer_ <= 0) {
		this->Init();
	}
}

void Enemy::OnCollision() {
	hp_--;
}

void Enemy::Move() {

}

void Enemy::Update() {
	if (isAlive_) {
		this->Move();
		this->OnCollision();
	} else {
		spawnTimer_--;
		this->Spawn();
	}
}

void Enemy::Draw() {
	Character::Draw();
}