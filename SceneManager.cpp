#include "SceneManager.h"
#include"Environment.h"
//==========================
//  コンストラクタ
SceneManager::SceneManager() {
	sceneArr_[SCENE_TITLE] = std::make_unique<Scene_Title>();
	sceneArr_[SCENE_PLAY] = std::make_unique<Scene_Play>();
	sceneArr_[SCENE_CLEAR] = std::make_unique<Scene_Clear>();
	sceneArr_[SCENE_GAMEOVER] = std::make_unique<Scene_GameOver>();

	//初期シーン
	Scene_Base::sceneNum = SCENE_PLAY;
	sceneArr_[Scene_Base::sceneNum]->Init();
}

void SceneManager::Init() {}

void SceneManager::Update() {
	///=========================
	///  更新処理

	//前フレームのシーンの保存
	preScene_ = sceneNum_;

	//シーンの取得
	sceneNum_ = Scene_Base::sceneNum;
	//シーンが切り替わったら初期化
	if (sceneNum_ != preScene_) {
		sceneArr_[sceneNum_]->Init();
	}

	//現在のシーンの更新
	sceneArr_[sceneNum_]->Update();

	///========================= 


	///=========================
	///  描画処理

	//背景の描画
	Novice::DrawBox(0, 0, kWindowWidth, kWindowHeight,0.0f, 0x000000ff, kFillModeSolid);

	//現在のシーンの描画
	sceneArr_[sceneNum_]->Draw();

	///========================= 
}