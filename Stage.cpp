#include "Stage.h"
Stage::Stage() {	
	player = new Player();
	enemy = new Enemy();

}

Stage::~Stage() {
	delete player;
	delete enemy;
}

void Stage::Init() {}

void Stage::Update() {
	player->Update();
	enemy->Update();

	collision->CollisionUpdate();
}

void Stage::Draw() {
	player->Draw();
	enemy->Draw();
}