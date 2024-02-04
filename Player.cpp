#include "Player.h"
#include"Environment.h"
#include"InputManager.h"
#include"CollisionManager.h"
#include"Stage.h"

Player::Player() {
	SetOBJType(PLAYER);

	CollisionManager* collisionManager = CollisionManager::GetInstance();
	collisionManager->CollisionSubscrive(this);

	gh_ = Novice::LoadTexture("white1x1.png");
	pos_ = { kWindowSize.x / 2.0f,kWindowSize.y / 2.0f };
	speed_ = 8.0f;
	width_ = 64.0f;
	height_ = 64.0f;
	radius_ = 64 / 2;
	color_ = 0xffffffff;
	hp_ = 10;
	initHP_ = 10;

	this->InitializeBullets();
	
}

Player::~Player() {}


void Player::InitializeBullets() {
	bullets_.push_back(std::make_unique<Bullet>());
}

void Player::Init() {
	pos_ = { kWindowSize.x / 2.0f,kWindowSize.y / 2.0f };
	hp_ = initHP_;//体力のリセット
	isAlive_ = true;//フラグのリセット
}

void Player::Move() {
	Vec2f movementVector = { 0.0f, 0.0f };

	if (InputManager::PressKeys(DIK_A)) {
		movementVector.x--;
	} else if (InputManager::PressKeys(DIK_D)) {
		movementVector.x++;
	}

	if (InputManager::PressKeys(DIK_W)) {
		movementVector.y--;
	} else if (InputManager::PressKeys(DIK_S)) {
		movementVector.y++;
	}

	velocity_ = movementVector.GetUnitVector() * speed_;
	// 移動
	pos_ += velocity_;
	//各頂点の更新
	Character::VertexInit();
}

void Player::DeleteInactive() {
	//使用していない配列の削除
	bullets_.erase(std::remove_if(bullets_.begin(), bullets_.end(), [](const std::unique_ptr<Bullet>& bullet) {
		return !bullet->GetIsShoot();
				   }), bullets_.end());
}

void Player::Shoot() {

	if (InputManager::TriggerKeys(DIK_SPACE)) {
		bullets_.push_back(std::make_unique<Bullet>());
		bullets_.back()->Init(this->pos_);
	}

	for (auto& bullet : bullets_) {
		bullet->Update();
	}

//	this->DeleteInactive();
}


//playerが何かと衝突した際の処理
void Player::OnCollision() {
	hp_--;
}

void Player::Dead() {
	if (hp_ <= 0) {
		Stage::isGameOver = true;
	}
}

void Player::Update() {
	if (isAlive_) {
		this->Move();
		this->Shoot();

		isCollisionEnabled_ = true; //生きている間当たり判定をとるようにする
		Dead();
	} else {
		this->Init();

		isCollisionEnabled_ = false; //生きている間当たり判定をとるようにする
	}
}

void Player::Draw() {
	Novice::ScreenPrintf(50, 80, "player：life = %d", hp_);
	if (isAlive_) {
		Character::Draw();
	}

	for (auto& bullet : bullets_) {
		bullet->Draw();
	}
}


std::vector<std::unique_ptr<Bullet>>& Player::GetBullets() {
	return bullets_;
}