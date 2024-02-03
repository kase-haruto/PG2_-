#pragma once
#include"Vec2.h"
#include<Novice.h>
#include"Collider.h"
class BaseOBJ{
protected:
	Vec2f pos_;
	unsigned int color_;

public:
	BaseOBJ() {}


	Vec2f GetPos()const { return pos_; }
	void SetPos(const Vec2f pos) { pos_ = pos; }

	unsigned int GetColor()const { return color_; }
	void SetColor(const unsigned int color) { color_ = color; }
};

