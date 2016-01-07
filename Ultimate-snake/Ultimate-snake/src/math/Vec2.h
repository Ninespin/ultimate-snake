#pragma once


namespace maths {
	
	struct Vec2 {
		int x, y;
		
		Vec2();
		Vec2(int a);
		Vec2(int x, int y);
		Vec2(const Vec2& copy);

		Vec2& add(const Vec2& vecToAdd);
		Vec2& sub(const Vec2& vecToSub);
		Vec2& mul(int scalar);
		Vec2& div(int scalar);

		Vec2& operator+=(const Vec2& other);
		Vec2& operator-=(const Vec2& other);
		Vec2& operator*=(int scalar);
		Vec2& operator/=(int scalar);

		friend Vec2 operator+(const Vec2& left, const Vec2& right);
		friend Vec2 operator-(const Vec2& left, const Vec2& right);
		friend Vec2 operator*(const Vec2& left, int right);
		friend Vec2 operator/(const Vec2& left, int right);

		friend bool operator==(const Vec2& left, const Vec2& right);
		friend bool operator!=(const Vec2& left, const Vec2& right);
	};

}