#include "./Friction.h"


void Friction::update(float deltatime) {

	float Fx = oParticle.getX() - p.getX();
	float Fy = oParticle.getY() - p.getY();
	float Fz = oParticle.getZ() - p.getZ();

	Vector3D vector = Vector3D(Fx, Fy, Fz);

	appliedForce = vector * u * gconst * p.getMass(); 
}