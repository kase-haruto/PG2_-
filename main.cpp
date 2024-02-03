#include <Novice.h>
#include"Environment.h"
#include"Stage.h"
#include"InputManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 800, 800);

	InputManager* inputManater = new InputManager();
	
	Stage* stage = new Stage();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		inputManater->Update();

		// キー入力を受け取る

		///
		/// ↓更新処理ここから
		///

		stage->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		stage->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (InputManager::TriggerKeys(DIK_ESCAPE)) {
			break;
		}
	}

	delete stage;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
