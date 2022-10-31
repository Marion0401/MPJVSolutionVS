#include "./Gravity.h"


float Gravity::gconst = 9.81F;

void Gravity::update(float deltatime) {
	appliedForce = Vector3D::down * p.getMass() * gconst;
}

