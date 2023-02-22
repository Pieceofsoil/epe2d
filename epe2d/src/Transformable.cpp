#include "Transformable.h"

epe::Transformable::Transformable() {
	position = epe::Vec2(0, 0);
}

epe::Transformable::Transformable(Vec2 _position) {
	position = _position;
}

epe::Vec2 epe::Transformable::getPosition() {
	return position;
}

void epe::Transformable::setPosition(Vec2 _position) {
	position = _position;
}