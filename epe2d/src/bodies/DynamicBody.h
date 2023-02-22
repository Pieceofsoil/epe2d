#pragma once

#include<src/epeMath/Vec2.h>
#include<src/bodies/Body.h>
#include<src/World.h>

namespace epe {
	class DynamicBody : public Body, Updatable
	{
	public:
		float mass = 0;
		Vec2 acceleration = Vec2(0, 0);
		Vec2 velocity = Vec2(0, 0);

		bool useDrag = true;
		bool useGravity = true;

		DynamicBody(Vec2 _position, World &_world);

		void update() override;
		void addAcceleration(Vec2 _acceleration);
		void addImpulse(Vec2 _impusle);
	private:
		void move();
	};
}

