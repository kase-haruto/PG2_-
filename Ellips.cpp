#include "Ellips.h"

void Ellips::Init(int drawType) {
	drawType_ = drawType;
}

void Ellips::Draw() {
	switch (drawType_) {
	case SOLID:
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			angle_, color_,
			kFillModeSolid
		);
		break;

	case WIREFRAME:
		Novice::DrawEllipse(
			static_cast<int>(pos_.x),
			static_cast<int>(pos_.y),
			static_cast<int>(radius_),
			static_cast<int>(radius_),
			angle_, color_,
			kFillModeWireFrame
		);
		break;
	}

}