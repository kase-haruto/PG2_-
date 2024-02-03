#pragma once
#include "Actor.h"
class Character :
    public Actor {

protected:

	enum VertexNum {
		LT,RT,
		LB,RB
	};

	float width_;
	float height_;
	Vec2f vertex_[4];
	Vec2f velocity_;
	Vec2f imageSize_ = { 1,1 };
	int gh_;
	int hp_;
	int initHP_;
	bool isAlive_;

public:
	Character();
	virtual ~Character();

	void VertexInit();
	virtual void Draw();


	Vec2f GetLtVertex() const;
	Vec2f GetRtVertex() const;
	Vec2f GetLbVertex() const;
	Vec2f GetRbVertex() const;

	void SetLtVertex(const Vec2f pos);
	void SetRtVertex(const Vec2f pos);
	void SetLbVertex(const Vec2f pos);
	void SetRbVertex(const Vec2f pos);

	Vec2f GetVelocity() const;
	void SetVelocity(const Vec2f velocity);

	float GetWidth() const;
	void SetWidth(const float width);

	float GetHeight() const;
	void SetHeight(const float height);

	int GetHP() const;
	void SetHP(const int HP);

	bool GetIsAlive()const;
	void SetIsAlive(const bool isAlive);
};

