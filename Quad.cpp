#include "Quad.h"

Quad::Quad() {

}

void Quad::Blinking() {
	displayTimer_++;
	if (displayTimer_ % 25 == 0) {
		isDisplay_ = !isDisplay_;
	}
}

void Quad::Init(Vec2f pos, Vec2f size, int gh, Vec2f imageSize) {
	pos_ = pos;
	size_ = size;
	gh_ = gh;
	imageSize_ = imageSize;

	vertex_[0] = { pos_.x - size_.x / 2.0f,pos_.y - size_.y / 2.0f };
	vertex_[1] = { pos_.x + size_.x / 2.0f,pos_.y - size_.y / 2.0f };
	vertex_[2] = { pos_.x - size_.x / 2.0f,pos_.y + size_.y / 2.0f };
	vertex_[3] = { pos_.x + size_.x / 2.0f,pos_.y + size_.y / 2.0f };
	isDisplay_ = true;
}

void Quad::Draw() {
	if (isDisplay_) {
		Novice::DrawQuad(
			static_cast<int>(vertex_[0].x),
			static_cast<int>(vertex_[0].y),
			static_cast<int>(vertex_[1].x),
			static_cast<int>(vertex_[1].y),
			static_cast<int>(vertex_[2].x),
			static_cast<int>(vertex_[2].y),
			static_cast<int>(vertex_[3].x),
			static_cast<int>(vertex_[3].y),
			0, 0,
			static_cast<int>(imageSize_.x),
			static_cast<int>(imageSize_.y),
			gh_, color_
		);
	}
}
