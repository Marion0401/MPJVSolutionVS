#include "./Object.h"

void Object::updateResForce() {
	Vector3D res;
	for (Force f : forces)
	{
		res += f.getAF();
	}
	resForce = res;
}

void Object::update(float deltaTime) {
	for (Force f : forces)
	{
		f.update(deltaTime);
	}
	updateResForce();

	acceleration = resForce / mass;
	integrer(deltaTime);
}

void Object::addForce(Force f) {
	forces.push_back(f);
}

void Object::clearForces() {
	forces.clear();
}