#include <Novice.h>
#include"Environment.h"
#include"GameManager.h"
#include<memory>

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);
	std::unique_ptr<GameManager>gameManager = std::make_unique<GameManager>();

	gameManager->Run();
	
	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
