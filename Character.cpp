#include "Character.h"

Character::Character() {

	this->VertexInit();
}

Character::~Character(){}

void Character::VertexInit() {
	vertex_[LT] = { pos_.x - width_ / 2.0f,pos_.y - height_ / 2.0f };
	vertex_[RT] = { pos_.x + width_ / 2.0f,pos_.y - height_ / 2.0f };
	vertex_[LB] = { pos_.x - width_ / 2.0f,pos_.y + height_ / 2.0f };
	vertex_[RB] = { pos_.x + width_ / 2.0f,pos_.y + height_ / 2.0f };
}


void Character::Draw() {
	Novice::DrawQuad(
		static_cast<int>(vertex_[LT].x),
		static_cast<int>(vertex_[LT].y),
		static_cast<int>(vertex_[RT].x),
		static_cast<int>(vertex_[RT].y),
		static_cast<int>(vertex_[LB].x),
		static_cast<int>(vertex_[LB].y),
		static_cast<int>(vertex_[RB].x),
		static_cast<int>(vertex_[RB].y),
		0, 0, 1, 1,
		gh_, color_
	);
}

Vec2f Character::GetLtVertex() const { return vertex_[LT]; }
Vec2f Character::GetRtVertex() const { return vertex_[RT]; }
Vec2f Character::GetLbVertex() const { return vertex_[LB]; }
Vec2f Character::GetRbVertex() const { return vertex_[RB]; }

void Character::SetLtVertex(const Vec2f pos) { vertex_[LT] = pos; }
void Character::SetRtVertex(const Vec2f pos) { vertex_[RT] = pos; }
void Character::SetLbVertex(const Vec2f pos) { vertex_[LB] = pos; }
void Character::SetRbVertex(const Vec2f pos) { vertex_[RB] = pos; }

Vec2f Character::GetVelocity() const { return velocity_; }
void Character::SetVelocity(const Vec2f velocity) { velocity_ = velocity; }


float Character::GetWidth() const { return width_; }
void Character::SetWidth(const float width) { width_ = width; }

float Character::GetHeight() const { return height_; }
void Character::SetHeight(const float height) { height_ = height; }

int Character::GetHP() const { return hp_; }
void Character::SetHP(const int HP) { hp_ = HP; }

bool Character::GetIsAlive()const { return isAlive_; }
void Character::SetIsAlive(const bool isAlive) { isAlive_ = isAlive; }