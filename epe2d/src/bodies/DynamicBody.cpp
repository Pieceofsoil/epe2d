#include "DynamicBody.h"

#include<src/colliders/Collider.h>

epe::DynamicBody::DynamicBody(Vec2 _position, World &_world) {
	setPosition(_position);
	_world.addBody(*this);
	world = &_world;
}

void epe::DynamicBody::update() {

	collider->setPosition(getPosition()); //Make collider follow the body

	if(useGravity) addAcceleration(world->gravity); //Gravity
	if(useDrag) addAcceleration(-(acceleration * world->drag)); //Drag
	
	if (collider != nullptr) collider->checkCollision(*world); //Collision check

	move();
}

void epe::DynamicBody::addAcceleration(Vec2 _acceleration) {
	Vec2 _acc = _acceleration * 0.00001f;
	velocity += _acc;
}

void epe::DynamicBody::addImpulse(Vec2 _impulse) {
	Vec2 _imp = _impulse * 0.01f;
	velocity += _imp;
}

void epe::DynamicBody::move() {
	setPosition(getPosition() + velocity);
}