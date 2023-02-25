#include "Body.h"

#include<iostream>
#include<string>

#include<src/colliders/Collider.h>

epe::Body::Body() {
	setPosition(Vec2(0, 0));
}

void epe::Body::attachCollider(Collider& _collider) {
	collider = &_collider;
	collider->body = this;
	collider->setPosition(getPosition());
}

epe::Collider* epe::Body::getCollider() {
	return collider;
}