#pragma once

#include<src/epeMath/Vec2.h>
#include<src/bodies/Body.h>
#include<src/World.h>

namespace epe {
	class StaticBody : public Body
	{
	public:
		World world;

		StaticBody(Vec2 _position, World &_world);
	};
}

