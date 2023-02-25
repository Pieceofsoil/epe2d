#pragma once

#include<src/epeMath/Vec2.h>
#include<src/colliders/Collider.h>
#include<src/bodies/Body.h>
#include<src/bodies/DynamicBody.h>
#include<src/World.h>

namespace epe {
	class BoxCollider : public Collider
	{
	private:
		Vec2 size = Vec2(0, 0);
	public:
		Vec2 getSize();
		void setSize(Vec2 _size);

		BoxCollider(Vec2 _size);
		BoxCollider(Vec2 _position, Vec2 _size);

		void checkCollision(World &_world) override;
	};
}
