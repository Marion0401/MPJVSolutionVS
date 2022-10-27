#ifndef FRICTION_H
#define FRICTION_H

#include "./Force.h"

class Friction : public Force {

	// F = u * mg
	const float u;
	const float gconst;
	

public:
	Friction(float u, float gconst, Particle p) : Force(p), u(u), gconst(gconst) {};

	const float getU() { return u; }
	const float getGconst() { return gconst; }

	void update( float deltatime) override;

};
#endif