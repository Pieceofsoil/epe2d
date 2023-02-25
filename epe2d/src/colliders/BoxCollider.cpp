#include "BoxCollider.h"

#include<iostream>

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

void epe::BoxCollider::checkCollision(World &_world) {
	std::vector<Collider*> allColliders;
	for (Body* body : _world.getBodies()) {
		if (body->getCollider() == this) continue;
		allColliders.push_back(body->getCollider());
	}

	std::vector<BoxCollider*> allBoxColliders;
	for (Collider* col : allColliders) {
		if (BoxCollider* boxCol = dynamic_cast<BoxCollider*>(col)) {
			allBoxColliders.push_back(boxCol);
		}
	}

	float x = getPosition().x;
	float y = getPosition().y;
	float w = getSize().x;
	float h = getSize().y;
	
	for (int i = 0; i < allBoxColliders.size(); i++) {
		float xi = allBoxColliders[i]->getPosition().x;
		float yi = allBoxColliders[i]->getPosition().y;
		float wi = allBoxColliders[i]->getSize().x;
		float hi = allBoxColliders[i]->getSize().y;

		//std::cout << (x < xi + wi) << " " << (x + w > xi) << " " << (y < yi + hi) << " " << (y + h > yi) << '\n';

		if (x < xi + wi && x + w > xi && y < yi + hi && y + h > yi) { // COLLISION DETECTED
			
		}

		/*std::cout << "This collider: " << this << "  Pos: " << getPosition().x << ", " << getPosition().y << " | Size: " << getSize().x << ", " << getSize().y << '\n';
		std::cout << "Other collider: " << allBoxColliders[i] << "  Pos: " << allBoxColliders[i]->getPosition().x << ", " << allBoxColliders[i]->getPosition().y 
			<< " | Size: " << allBoxColliders[i]->getSize().x << ", " << allBoxColliders[i]->getSize().y << '\n';*/
	}
}