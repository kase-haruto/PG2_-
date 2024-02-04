#include "Scene_GameOver.h"
#include"Environment.h"
Scene_GameOver::Scene_GameOver() {
	Vec2f barPos = { kWindowSize.x/2.0f,300.0f };
	int barGH = Novice::LoadTexture("./Resources/Images/gameOver.png");
	clearBar.Init(barPos, { 800.0f,250.0f }, barGH, { 800.0f,250.0f });

	Vec2f pressSpaceGHPos = { kWindowSize.x / 2.0f,kWindowSize.y / 2.0f };
	int pressSpaceGH = Novice::LoadTexture("./Resources/Images/pressT.png");
	pressSpace.Init(pressSpaceGHPos, { 750.0f,200.0f }, pressSpaceGH, { 800.0f,250.0f });

}

void Scene_GameOver::Init() {

}

void Scene_GameOver::Update() {
	pressSpace.Blinking();

	//シーンの切り替え
	if (InputManager::TriggerKeys(DIK_T)) {
		Scene_Base::sceneNum = SCENE_TITLE;
	}
}

void Scene_GameOver::Draw() {
	clearBar.Draw();
	pressSpace.Draw();
}

void Scene_GameOver::Unload() {

}