#include "StaticBody.h"

epe::StaticBody::StaticBody(Vec2 _position, World &_world) {
	setPosition(_position);
	_world.addBody(*this);
}