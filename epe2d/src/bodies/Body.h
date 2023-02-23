#pragma once
#include<src/Transformable.h>
#include<src/Updatable.h>
#include<src/colliders/Collider.h>

namespace epe {
	class Body : public Transformable
	{
	public:
		Collider collider;
		Body();
		void attachCollider(Collider& _collider);
	};
}

