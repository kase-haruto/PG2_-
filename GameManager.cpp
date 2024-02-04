#include "GameManager.h"

GameManager::GameManager() {
	inputManater = new InputManager();
	sceneManager = new SceneManager();
}

GameManager::~GameManager() {
	delete inputManater, sceneManager;
}

void GameManager::Run() {

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		
		// フレームの開始
		Novice::BeginFrame();

		inputManater->Update();

		sceneManager->Update();

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::TriggerKeys(DIK_ESCAPE)) {
			break;
		}

	}

}