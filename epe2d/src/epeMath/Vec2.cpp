#include"Vec2.h"

epe::Vec2::Vec2(float _x, float _y) {
	x = _x;
	y = _y;
}

epe::Vec2::Vec2() {
	x = 0;
	y = 0;
}

epe::Vec2 epe::Vec2::operator*(double _s)
{
	return Vec2(x * _s, y * _s);
}

epe::Vec2 epe::Vec2::operator/(double _s)
{
	return Vec2(x / _s, y / _s);
}

epe::Vec2 epe::Vec2::operator+(const Vec2& _v)
{
	return Vec2(x + _v.x, y + _v.y);
}

epe::Vec2 epe::Vec2::operator-(const Vec2& _v)
{
	return Vec2(x - _v.x, y - _v.y);
}

epe::Vec2 epe::Vec2::operator-()
{
	return Vec2(-x, -y);
}

epe::Vec2& epe::Vec2::operator+=(const Vec2& _v)
{
	x += _v.x;
	y += _v.y;
	return *this;
}

epe::Vec2& epe::Vec2::operator-=(const Vec2& _v)
{
	x -= _v.x;
	y -= _v.y;
	return *this;
}

epe::Vec2::operator std::string() const {
	return "Vec2(" + std::to_string(x) + ", " + std::to_string(y) + "); ";
}
