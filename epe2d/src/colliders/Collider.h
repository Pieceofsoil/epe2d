#pragma once

#include<src/epeMath/Vec2.h>
#include<src/Transformable.h>

namespace epe {

	class World; //Forward declaration for epe::World

	class Collider : public Transformable
	{
	public:
		Collider();
		virtual ~Collider() = default;
		virtual void checkCollision() const = 0;
	};
}

