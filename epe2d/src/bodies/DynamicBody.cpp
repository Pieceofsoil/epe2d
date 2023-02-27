#include "DynamicBody.h"

#include<src/colliders/Collider.h>

#include<iostream>

epe::DynamicBody::DynamicBody(Vec2 _position, World &_world) {
	setPosition(_position);
	_world.addBody(*this);
	world = &_world;

	mass = 1;
	restitution = 0;
}

void epe::DynamicBody::update() {
	collider->setPosition(getPosition()); //Make collider follow the body

	if(useGravity) addForce(world->gravity); //Gravity
	if(useDrag) addForce(-(acceleration * world->drag)); //Drag
	
	acceleration = velocity - oldVelocity;
	//std::cout << "_VEL: " << velocity.y << '\n';
	//std::cout << "_OLDVEL: " << oldVelocity.y << '\n';
	//std::cout << "_ACC: " << acceleration.y << '\n';

	if (collider != nullptr) collider->checkCollision(*world); //Collision check

	if(oldVelocity.x != velocity.x || oldVelocity.y != velocity.y) oldVelocity = velocity;
	move();
}

void epe::DynamicBody::addForce(Vec2 _acceleration) {
	Vec2 _acc = _acceleration * 0.00001f / mass;
	velocity += _acc;
}

void epe::DynamicBody::addVelocity(Vec2 _velocity) {
	setPosition(getPosition() + _velocity);
}

void epe::DynamicBody::move() {
	setPosition(getPosition() + velocity);
}