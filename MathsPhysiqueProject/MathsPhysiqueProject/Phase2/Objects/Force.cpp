#include "../Headers/Force.h"

void Force::setPart(Particle np) 
{ 
	p = np; 
}

void Force::setAF(Vector3D v){
	appliedForce = v;
}

virtual void Update(Particle p, float deltatime) = 0;