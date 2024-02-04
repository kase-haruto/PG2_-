#include "Scene_Clear.h"
#include"Environment.h"
Scene_Clear::Scene_Clear() {
	Vec2f barPos = { 250,300.0f };
	int barGH = Novice::LoadTexture("./Resources/Images/clear.png");
	clearBar.Init(barPos, { 500.0f,250.0f }, barGH, { 500.0f,250.0f });

	Vec2f pressSpaceGHPos = { kWindowSize.x / 2.0f,kWindowSize.y / 2.0f };
	int pressSpaceGH = Novice::LoadTexture("./Resources/Images/pressT.png");
	pressSpace.Init(pressSpaceGHPos, { 750.0f,200.0f }, pressSpaceGH, { 800.0f,250.0f });

}

void Scene_Clear::Init() {
	
}

void Scene_Clear::Update() {
	pressSpace.Blinking();

	//シーンの切り替え
	if (InputManager::TriggerKeys(DIK_T)) {
		Scene_Base::sceneNum = SCENE_TITLE;
	}
}

void Scene_Clear::Draw() {
	clearBar.Draw();
	pressSpace.Draw();
}

void Scene_Clear::Unload() {

}