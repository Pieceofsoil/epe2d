#pragma once

#include<src/epeMath/Vec2.h>

namespace epe {
	class Transformable
	{
	private:
		Vec2 position = Vec2(0, 0);
	public:
		Transformable();
		Transformable(Vec2 _position);
		Vec2 getPosition();
		void setPosition(Vec2 _position);
	};
}

