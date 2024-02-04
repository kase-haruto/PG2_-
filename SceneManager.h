#pragma once
#include"Scene_Title.h"
#include"Scene_Play.h"
#include"Scene_GameOver.h"
#include"Scene_Clear.h"
#include<memory>

class SceneManager {
	std::unique_ptr<Scene_Base> sceneArr_[4];

	int preScene_;
	int sceneNum_;

public:

	SceneManager();
	void Init();
	void Update();
};

