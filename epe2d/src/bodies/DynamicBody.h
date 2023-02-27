#pragma once

#include<src/epeMath/Vec2.h>
#include<src/bodies/Body.h>
#include<src/World.h>

namespace epe {
	class DynamicBody : public Body, Updatable
	{
	public:
		float mass = 0;
		float restitution = 0;
		Vec2 acceleration = Vec2();
		Vec2 velocity = Vec2();

		World* world;

		bool useDrag = true;
		bool useGravity = true;

		DynamicBody(Vec2 _position, World &_world);

		void update() override;
		void addForce(Vec2 _acceleration);
		void addVelocity(Vec2 _direction);
	private:
		void move();
		Vec2 oldVelocity = Vec2();
	};
}

