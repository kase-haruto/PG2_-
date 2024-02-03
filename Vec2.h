#pragma once
struct Vec2f final {
	float x;
	float y;

	float Length() const;
	float SqrLength() const;
	float Distance(const Vec2f& other) const;
	float DotProduct(const Vec2f& other) const;
	float CrossProduct(const Vec2f& other) const;

	bool IsZero(float tolerance = 0.01f) const;

	Vec2f GetUnitVector() const;

	Vec2f Normalize() const;
	Vec2f RotateVector(const float& angle) const;

	// ベクトルのスカラー倍
	Vec2f operator*(const float& scalar) const;
	Vec2f& operator*=(float scalar);
	Vec2f& operator/=(float divisor);

	// ベクトルの加算
	Vec2f operator+(const Vec2f& other) const;
	Vec2f operator+=(const Vec2f& other);

	// ベクトルの減算
	Vec2f operator-(const Vec2f& other) const;
	Vec2f operator-=(const Vec2f& other);

	//ベクトルの乗算
	Vec2f operator*(const Vec2f& other) const;
	Vec2f operator*=(const Vec2f& other);
};

struct Vec2d final {
	int x;
	int y;
};
