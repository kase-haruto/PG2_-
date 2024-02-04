#pragma once
#include "Scene_Base.h"
#include"Quad.h"

class Scene_Clear :
    public Scene_Base {



	Quad clearBar;
	Quad pressSpace;


public:
	Scene_Clear();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

};

