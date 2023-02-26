#pragma once
#include<string>

namespace epe { 
	class Vec2 {
	public:
		float x = 0;
		float y = 0;

		Vec2();
		Vec2(float _x, float _y);

		Vec2 operator*(double _s);
		Vec2 operator/(double _s);
		Vec2 operator+(const Vec2& _v);
		Vec2 operator-(const Vec2& _v);
		Vec2 operator-();
		Vec2& operator+=(const Vec2& _v);
		Vec2& operator-=(const Vec2& _v);
		operator std::string() const;
	};
}