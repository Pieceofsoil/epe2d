#pragma once

#include<src/Transformable.h>
#include<src/Updatable.h>

namespace epe {

	class Collider; //Forward declaration for epe::Collider

	class Body : public Transformable
	{
	public:
		Collider* collider = nullptr;
		Body();
		void attachCollider(Collider& _collider);
		Collider& getCollider();
	};
}

