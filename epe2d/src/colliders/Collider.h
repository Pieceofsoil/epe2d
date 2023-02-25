#pragma once

#include<src/epeMath/Vec2.h>
#include<src/Transformable.h>

namespace epe {

	class World; //Forward declaration for epe::World
	class Body; //Forward declaration for epe::Body

	class Collider : public Transformable
	{
	public:
		Body* body = nullptr;
		Collider();
		virtual ~Collider() = default;
		virtual void checkCollision(World &_world) = 0;
	};
}

