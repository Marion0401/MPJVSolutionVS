#ifndef OBJECT_H
#define OBJECT_H

#include <vector>

#include "./Particle.h"
#include "../Physique/Force.h"
#include "../Physique/Collision.h"

class Object : public Particle {

protected:
	std::vector<Force> forces;
	Vector3D resForce;

	std::vector<Collision> collisions;

	void updateResForce();

public :

	Object(Vector3D p) : Particle(p) {};

	std::vector<Force> getForces() { return forces; }
	Vector3D getResForce() { return resForce; }

	void addForce(Force f);
	void clearForces();

	std::vector<Collision> getCollisions() { return collisions; }
	void addCollision(Collision c);
	void removeCollision(Collision c);

	virtual void update(float deltaTime);

	virtual bool intersects(Object o);
	virtual float getArea();


};

#endif