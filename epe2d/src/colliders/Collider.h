#pragma once

#include<src/epeMath/Vec2.h>
#include<src/Transformable.h>

namespace epe {
	class Collider : public Transformable
	{
	public:
		Collider();
		virtual ~Collider() = default;
		virtual void checkCollision() const = 0;
	};
}

