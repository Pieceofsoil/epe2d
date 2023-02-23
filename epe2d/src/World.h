#pragma once

#include<vector>

#include<src/epeMath/Vec2.h>

#include<src/bodies/Body.h>

namespace epe {
	class World {
	public:
		Vec2 gravity = Vec2(0, 0);
		float drag = 0.01f;

		World();
		World(Vec2 _gravity, float _drag);

		void addBody(Body* _body);
		std::vector<Body*> getBodies();
	private:
		std::vector<Body*> bodies;
	};
}