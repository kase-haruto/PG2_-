#pragma once
#include "BaseOBJ.h"
#include"Collider.h"
class Actor :
	public Collider {
protected:
	
	float speed_;
	unsigned int color_;

public:
	Actor() {}
	
	virtual void Draw() = 0;

	float GetSpeed() const;
	void SetSpeed(const float speed);

};

