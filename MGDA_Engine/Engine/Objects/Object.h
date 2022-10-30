#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "./Particle.h"
#include "../Physique/Force.h"

class Object : public Particle {

protected:
	std::vector<Force> forces;
	Vector3D resForce;

	void updateResForce();

public :

	Object(Vector3D p) : Particle(p) {};

	std::vector<Force> getForces() { return forces; }
	Vector3D getResForce() { return resForce; }

	void addForce(Force f);
	void clearForces();


	virtual void update(float deltaTime);

	virtual bool intersects(Object o);
	virtual float getArea();


};

#endif