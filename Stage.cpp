#include "Stage.h"

bool Stage::isClear = false;
bool Stage::isGameOver = false;

Stage::Stage() {	
	player = new Player();
	enemy = new Enemy();
}

Stage::~Stage() {
	delete player;
	delete enemy;
}

void Stage::Init() {
	enemy->Init();
	player->Init();
}

void Stage::Update() {
	player->Update();
	enemy->Update();

	collision->CollisionUpdate();
}

void Stage::Draw() {
	player->Draw();
	enemy->Draw();
}