#ifndef FORCE_H
#define FORCE_H

#include "../Objects/Particle.h"
#include "../Math/Vector3D.h"

class Force {

	protected:
	Vector3D appliedForce;
	Particle p;

	public:
		Force() = default;
		Force(Particle p) : p(p) {}
		Force(Vector3D v, Particle p) : appliedForce(v), p(p) {}

		Particle getParticle() const { return p; }
		Vector3D getAF() const { return appliedForce; }

		void setPart(Particle p);
		void setAF(Vector3D v);

		virtual Force& operator+(Force& f);

		virtual void update(float deltatime);




};
#endif