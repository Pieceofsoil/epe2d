#pragma once

#include<vector>
#include<src/epeMath/Vec2.h>

namespace epe {

	class Body; //Forward declaration for epe::Body

	class World {
	public:
		Vec2 gravity = Vec2(0, 0);
		float drag = 0.01f;

		World();
		World(Vec2 _gravity, float _drag);
		void update();

		void addBody(Body &_body);
		std::vector<Body*> getBodies();
	private:
		std::vector<Body*> bodies;
	};
}