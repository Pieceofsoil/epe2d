#include"World.h"

#include<iostream>

#include<src/bodies/Body.h>

epe::World::World() {
	gravity = Vec2(0, 9.81f);
}

epe::World::World(Vec2 _gravity, float _drag) {
	gravity = _gravity;
	drag = _drag;
}

void epe::World::addBody(Body &_body) {
	bodies.push_back(&_body);
}

std::vector<epe::Body*> epe::World::getBodies() {
	return bodies;
}