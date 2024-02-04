#pragma once
#include "Scene_Base.h"
#include"Quad.h"

class Scene_GameOver :
	public Scene_Base {



	Quad clearBar;
	Quad pressSpace;


public:
	Scene_GameOver();

	void Init()override;
	void Update()override;
	void Draw()override;
	void Unload()override;

};
