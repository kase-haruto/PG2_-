#pragma once
#include"InputManager.h"
enum SceneNum {
	SCENE_TITLE,
	SCENE_PLAY,
	SCENE_CLEAR,
	SCENE_GAMEOVER
};

class Scene_Base {

public:
	static int sceneNum;

public:

	virtual ~Scene_Base() {};
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Unload() = 0;

};

