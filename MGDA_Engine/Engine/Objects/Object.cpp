#include "./Object.h"

void Object::updateResForce() {
	Force res(this);
	for each (Force f in forces)
	{
		res += f;
	}
	resForce = res;
}

virtual void Object::update(float deltaTime) {
	for each (Force f in forces)
	{
		f.update(deltaTime);
	}
	updateResForce();

	acceleration = resForce.getAF() / mass;
	integrer();
}

void Object::addForce(Force f) {
	forces.push_back(f);
}

void Object::clearForces() {
	forces.clear();
}