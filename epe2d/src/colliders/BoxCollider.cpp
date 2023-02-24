#include "BoxCollider.h"

epe::BoxCollider::BoxCollider(Vec2 _size) {
	setPosition(Vec2(0, 0));
	setSize(_size);
}

epe::BoxCollider::BoxCollider(Vec2 _position, Vec2 _size) {
	setPosition(_position);
	setSize(_size);
}

epe::Vec2 epe::BoxCollider::getSize() {
	return size;
}

void epe::BoxCollider::setSize(Vec2 _size) {
	size = _size;
}

void epe::BoxCollider::checkCollision() const {

}