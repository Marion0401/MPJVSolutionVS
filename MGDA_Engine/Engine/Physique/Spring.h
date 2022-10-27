#ifndef Spring_H
#define Spring_H

#include "./Force.h"

class Spring : public Force {

	
	const float l0;
	const float k;
	float l;
	Particle attachParticle;

	public:
		Spring(const float lo, const float k, float l, Particle particle) : Force(p) {};

		float const getL0() { return l0; }
		float const getK() { return k; }
		float getL() { return l; }
		Particle getAttachParticle() { return attachParticle; }

		void setAttachParticle(Particle np);

		void update(float deltaTime) override;

};
#endif

