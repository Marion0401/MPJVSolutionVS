#ifndef Gravity_H
#define Gravity_H

#include "Force.h"

class Gravity : public Force {

	static float gconst;

	public:
		
		Gravity(Particle p) : part(p){};

		override void update(Particle p, float deltatime);

};
#endif
