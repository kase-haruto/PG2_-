#include "Scene_Title.h"
#include"Environment.h"
#include"Stage.h"
Scene_Title::Scene_Title() {

	Vec2f barPos = { kWindowSize.x / 2.0f,300.0f };
	int barGH = Novice::LoadTexture("./Resources/Images/title.png");
	titleBar.Init(barPos, { 500.0f,250.0f }, barGH, { 500.0f,250.0f });

	Vec2f pressSpaceGHPos = { kWindowSize.x / 2.0f,kWindowSize.y / 2.0f };
	int pressSpaceGH = Novice::LoadTexture("./Resources/Images/pressSpace.png");
	pressSpace.Init(pressSpaceGHPos, { 750.0f,200.0f }, pressSpaceGH, { 800.0f,250.0f });
}

void Scene_Title::Init() {
	Stage::isClear = false;
	Stage::isGameOver = false;
}

void Scene_Title::Update() {
	pressSpace.Blinking();


	//プレイシーンに切り替え
	if (InputManager::TriggerKeys(DIK_SPACE)) {
		Scene_Base::sceneNum = SCENE_PLAY;
	}
}

void Scene_Title::Draw() {
	titleBar.Draw();
	pressSpace.Draw();
}

void Scene_Title::Unload() {

}