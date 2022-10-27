#include <cmath>

#include "./Spring.h"
#include "../Math/Vector3D.h"

void Spring::setAttachParticle(Particle np) {
	attachParticle = np;
}

void Spring::update(float deltatime) {

	Vector3D springVector = p.getPosition() - attachParticle.getPosition();
	l = springVector.getNorm();

	appliedForce = springVector.normalize() * (-k) * (1-10);
}