#include "Scene_Play.h"

Scene_Play::Scene_Play() {
	stage = new Stage();
}

Scene_Play::~Scene_Play() {
	delete stage;
}

void Scene_Play::Init() {
	stage->Init();
	Stage::isClear = false;
}

void Scene_Play::Update() {
	stage->Update();
	if (Stage::isClear) {
		Scene_Base::sceneNum = SCENE_CLEAR;
	}

	if (Stage::isGameOver) {
		Scene_Base::sceneNum = SCENE_GAMEOVER;
	}
}

void Scene_Play::Draw() {
	stage->Draw();
}

void Scene_Play::Unload() {
}