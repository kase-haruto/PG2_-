#pragma once
#include "Scene_Base.h"
#include"Quad.h"
class Scene_Title :
    public Scene_Base {

	Quad titleBar;
	Quad pressSpace;

public:
	Scene_Title();
	void Init()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

};

