#pragma once
#include"BaseOBJ.h"
class Quad 
	:public BaseOBJ{

private:
	Vec2f pos_;
	Vec2f size_;
	Vec2f vertex_[4];
	int gh_;
	Vec2f imageSize_;

	int displayTimer_;
	bool isDisplay_;

public:
	Quad();

	void Blinking();

	void Init(Vec2f pos,Vec2f size, int gh,Vec2f imageSize);
	void Draw();

};

