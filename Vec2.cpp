#include"Vec2.h"

#include <math.h>

float Vec2f::Length() const {
	const float sqrLength = SqrLength();
	if (sqrLength > 0.0f) {
		return sqrtf(sqrLength);
	} else {
		return 0.0f;
	}
}

float Vec2f::SqrLength() const {
	return x * x + y * y;
}

float Vec2f::Distance(const Vec2f& other) const {
	const float distX = other.x - x;
	const float distY = other.y - y;
	return sqrtf(distX * distX + distY * distY);
}

float Vec2f::DotProduct(const Vec2f& other) const {
	return x * other.x + y * other.y;
}

float Vec2f::CrossProduct(const Vec2f& other) const {
	return x * other.y - y * other.x;
}

bool Vec2f::IsZero(float tolerance) const {
	return (fabsf(x) < tolerance) && (fabsf(y) < tolerance);
}

Vec2f Vec2f::Normalize() const {
	const float sqrLength = SqrLength();
	if (sqrLength > 0.0f) {
		const float invLength = 1.0f / sqrtf(sqrLength);
		return { x * invLength, y * invLength };
	} else {
		return { 0.0f,0.0f };
	}
}

Vec2f Vec2f::GetUnitVector() const {
	const float length = Length();
	if (length > 0.0f) {
		const float invLength = 1.0f / length;
		return { x * invLength, y * invLength };
	} else {
		return { 0.0f, 0.0f };
	}
}

Vec2f Vec2f::RotateVector(const float& angle) const {
	const float cos = cosf(angle);
	const float sin = sinf(angle);
	return { x * cos - y * sin, x * sin + y * cos };
}

Vec2f Vec2f::operator*(const float& scalar) const {
	return { x * scalar,y * scalar };
}

Vec2f& Vec2f::operator*=(float scalar) {
	x *= scalar;
	y *= scalar;
	return *this;
}

Vec2f& Vec2f::operator/=(float divisor) {
	x /= divisor;
	y /= divisor;
	return *this;
}


// ベクトルの加算
Vec2f Vec2f::operator+(const Vec2f& other) const {
	return Vec2f(x + other.x, y + other.y);
}
Vec2f Vec2f::operator+=(const Vec2f& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

// ベクトルの減算
Vec2f Vec2f::operator-(const Vec2f& other) const {
	return Vec2f(x - other.x, y - other.y);
}
Vec2f Vec2f::operator-=(const Vec2f& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

//ベクトルの乗算
Vec2f Vec2f::operator*(const Vec2f& other) const {
	return Vec2f(x * other.x, y * other.y);
}

Vec2f Vec2f::operator*=(const Vec2f& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}
