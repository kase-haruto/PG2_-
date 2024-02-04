#pragma once
#include"Vec2.h"
class Collider {
public:
	enum CollisionType {
		PLAYER,
		ENEMY,
		BULLET,
		NONE
	};
protected:
	Vec2f pos_;
	int objectType_;
	float radius_;
	bool isCollisionEnabled_; //当たり判定をとるかどうか

public:
	Collider();
	virtual ~Collider();

	virtual void OnCollision() = 0;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	int GetObjectType()const { return objectType_; }
	float GetRadius()const { return radius_; }

	Vec2f GetPos()const { return pos_; }
	void SetPos(const Vec2f pos) { pos_ = pos; }

	void SetOBJType(const int type) { objectType_ = type; }

	bool GetIsCollisionEnabled()const { return isCollisionEnabled_; }
};

