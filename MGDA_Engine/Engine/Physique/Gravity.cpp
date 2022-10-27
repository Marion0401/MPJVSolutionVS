#include "./Gravity.h"


Gravity::gconst = 9.81;

void Gravity::update(float deltatime) override {
	appliedForce = p.getMass() * gconst * Vector3D::down;
}

