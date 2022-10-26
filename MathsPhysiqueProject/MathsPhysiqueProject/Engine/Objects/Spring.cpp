#include "../Headers/Spring.h"
#include <cmath>
#include "Vector3D.h"

void Spring::setAttachParticle(Particle np) {
	attachParticle = np;
}

void Spring::update(float deltatime) override {

	Vector3D springVector = p.getPosition() - attachParticle.getPosition();
	l = springVector.getNorm();

	appliedForce = -k * (l - l0) * springVector.normalize();
}