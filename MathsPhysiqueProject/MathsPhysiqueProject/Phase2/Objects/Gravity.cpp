#include "../Headers/Gravity.h"


override void Gravity::update(Particle p, float deltatime) {
	appliedForce = p.getMass() * gconst * Vector3D::Down;
}

