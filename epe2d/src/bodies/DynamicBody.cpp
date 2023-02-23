#include "DynamicBody.h"

epe::DynamicBody::DynamicBody(Vec2 _position, World &_world) {
	setPosition(_position);
	_world.addBody(this);
}

void epe::DynamicBody::update() {
	if(useGravity) addAcceleration(world.gravity); //Gravity
	if(useDrag) addAcceleration(-(acceleration * world.drag)); //Drag
	//Acceleration(Vec2(4, 0));

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