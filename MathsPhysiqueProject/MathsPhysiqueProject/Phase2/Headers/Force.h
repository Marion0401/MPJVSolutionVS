#ifndef Force_H
#define Force_H

#include "Particle.h"
#include "Vector3D.h"

class Force {

	protected:
	Vector3D appliedForce;
	Particle p;

	public:
		Force();
		Force(Vector3D v, Particle p) : appliedForce(v), p(p) {};

		Particle getParticle() const { return p; }
		Vector3D getAF() const { return appliedForce; }

		void setPart(Particle p);
		void setVect(Vector3D v);

		virtual void update(Particle p, float deltatime);




};
#endif