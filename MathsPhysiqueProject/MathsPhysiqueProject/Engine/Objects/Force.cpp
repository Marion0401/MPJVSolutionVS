#include "../Headers/Force.h"

void Force::setPart(Particle np) 
{ 
	p = np; 
}

void Force::setAF(Vector3D v){
	appliedForce = v;
}

Force Force::operator+(Force f) {
	if (f.p = p) {
		return Force(p, appliedForce + f.getAF());
	}
	else throw std::logic_error;
}