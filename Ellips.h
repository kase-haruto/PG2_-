#pragma once
#include"BaseOBJ.h"

class Ellips :
	public BaseOBJ {	
protected:

	enum FillMode {
		SOLID,
		WIREFRAME
	};
	
	float radius_;
	float angle_;
	int drawType_;

public:
	Ellips() {}

	void Init(int drawType);
	void Draw();

	float GetRadius()const { return radius_; }
	void SetRadius(const float radius) { radius_ = radius; }

	float GetAngle()const { return angle_; }
	void SetAngle(const float angle) { angle_ = angle; }

	int GetDrawType()const { return drawType_; }
	void SetDrawType(const int drawType) { drawType_ = drawType; }
};

