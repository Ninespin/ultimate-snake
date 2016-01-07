#include "Vec2.h"

namespace maths {

	Vec2::Vec2() : Vec2(0)
	{
	}

	Vec2::Vec2(int a) : Vec2(a, a)
	{
	}

	Vec2::Vec2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	Vec2::Vec2(const Vec2& copy) : Vec2(copy.x, copy.y)
	{
	}


	Vec2& Vec2::add(const Vec2& vecToAdd)
	{
		this->x += vecToAdd.x;
		this->y += vecToAdd.y;
		return *this;
	}

	Vec2& Vec2::sub(const Vec2& vecToSub)
	{
		this->x -= vecToSub.x;
		this->y -= vecToSub.y;
		return *this;
	}

	Vec2& Vec2::mul(int scalar)
	{
		this->x *= scalar;
		this->y *= scalar;
		return *this;
	}
	Vec2& Vec2::div(int scalar)
	{
		this->x /= scalar;
		this->y /= scalar;
		return *this;
	}


	Vec2& Vec2::operator+=(const Vec2& other)
	{
		return add(other);
	}
	Vec2& Vec2::operator-=(const Vec2& other)
	{
		return sub(other);
	}
	Vec2& Vec2::operator*=(int scalar)
	{
		return mul(scalar);
	}
	Vec2& Vec2::operator/=(int scalar)
	{
		return div(scalar);
	}


	Vec2 operator+(const Vec2 & left, const Vec2 & right)
	{
		return Vec2(left).add(right);
	}
	Vec2 operator-(const Vec2 & left, const Vec2 & right)
	{
		return Vec2(left).sub(right);
	}
	Vec2 operator*(const Vec2 & left, int right)
	{
		return Vec2(left).mul(right);
	}
	Vec2 operator/(const Vec2 & left, int right)
	{
		return Vec2(left).div(right);
	}


	bool operator==(const Vec2 & left, const Vec2 & right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	bool maths::operator!=(const Vec2 & left, const Vec2 & right)
	{
		return !(left == right);
	}
}

