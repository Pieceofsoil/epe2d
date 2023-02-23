#pragma once

#include<src/epeMath/Vec2.h>
#include<src/bodies/Body.h>

namespace epe {
	class Collision
	{
	public:
		Vec2 normal;
		Vec2 point;
		Body other;

		Collision();
	};
}

