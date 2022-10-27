#include "../Headers/Friction.h"


void Friction::setU(const float U) {
	u = U;
}

void Friction::setGconst(const float Gconst) {
	gconst = Gconst;
}


void Friction::update(Particle particle, float deltatime) override {

	Fx = particle.getX() - p.getX();
	Fy = particle.getY() - p.getY();
	Fz = particle.getZ() - p.getZ();

	Vector = new Vector3D(Fx, Fy, Fz);

	appliedForce = u * gconst * p.getMass() * Vector; 
}