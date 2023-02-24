#include "Body.h"

epe::Body::Body() {
	setPosition(Vec2(0, 0));
}

void epe::Body::attachCollider(Collider& _collider) {
	collider = &_collider;
	collider->setPosition(getPosition());
}