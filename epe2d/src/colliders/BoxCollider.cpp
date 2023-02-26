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
	for (Body* _body : _world.getBodies()) {
		if (_body->getCollider() == this) continue;
		allColliders.push_back(_body->getCollider());
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
	
	DynamicBody* dbody = dynamic_cast<DynamicBody*>(body);

	for (int i = 0; i < allBoxColliders.size(); i++) {
		float xi = allBoxColliders[i]->getPosition().x;
		float yi = allBoxColliders[i]->getPosition().y;
		float wi = allBoxColliders[i]->getSize().x;
		float hi = allBoxColliders[i]->getSize().y;

		std::string log = "";
		log += "Acc: ";
		log += dbody->acceleration.operator std::string();
		log += '\n';
		log += "Vel: ";
		log += dbody->velocity.operator std::string();
		log += "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		std::cout << log;

		if (x < xi + wi && x + w > xi && y < yi + hi && y + h > yi) { // COLLISION DETECTED
			float overlapX = x < xi ? overlapX = x + w - xi : overlapX = xi + wi - x;
			float overlapY = y < yi ? overlapY = y + h - yi : overlapY = yi + hi - y;;

			//Resolve collision

			if (overlapX < overlapY)
			{
				if (x < xi) { //left side
					dbody->addVelocity(Vec2(-overlapX * 2, 0));
					dbody->velocity = Vec2(0, 0);
				}
				else { //right side
					dbody->addVelocity(Vec2(overlapX * 2, 0));
					dbody->velocity = Vec2(0, 0);
				}
			}
			else
			{
				if (y < yi) { //top side
					dbody->addVelocity(Vec2(0, -overlapY * 2));
					dbody->velocity = Vec2(0, 0);
				}
				else { //bottom side
					dbody->addVelocity(Vec2(0, overlapY * 2));
					dbody->velocity = Vec2(0, 0);
				}
			}
		}
	}
}