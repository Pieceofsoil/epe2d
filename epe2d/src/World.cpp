#include"World.h"

epe::World::World() {
	gravity = Vec2(0, 9.81f);
}

epe::World::World(Vec2 _gravity) {
	gravity = _gravity;
}