#pragma once
#include<src/Transformable.h>
#include<src/Updatable.h>
#include<src/colliders/Collider.h>
#include<src/World.h>

namespace epe {
	class Body : public Transformable
	{
	public:
		Collider collider;
		World world;
		Body();
		void attachCollider(Collider& _collider);
	};
}

