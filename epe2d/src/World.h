#pragma once

#include<src/epeMath/Vec2.h>

namespace epe {
	class World {
	public:
		Vec2 gravity = Vec2(0, 0);
		float drag = 0.01f;
		World();
		World(Vec2 _gravity);
	};
}