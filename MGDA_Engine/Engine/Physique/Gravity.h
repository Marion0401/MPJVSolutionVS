#ifndef GRAVITY_H
#define GRAVITY_H

#include "Force.h"

class Gravity : public Force {

	static float gconst;

public:
		
	//Gravity(Particle p) : Force(p, p.getMass()* gconst* Vector3D::down) {};

	void update(float deltatime) override;

};
#endif
