#pragma once
#include "Scene_Base.h"
#include"Stage.h"

class Scene_Play :
    public Scene_Base {

	Stage* stage;

public:
	Scene_Play();
	~Scene_Play();
	void Init()override;
	void Update()override;
	void Draw()override;

	void Unload()override;
};

