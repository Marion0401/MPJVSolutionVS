#ifndef COLLISION_H
#define COLLISION_H

#include "../Objects/Disc.h"

class Collision {
protected :
	Vector3D normal;
	Vector3D relVelocity;
	float elasticConst;
	Disc d1;
	Disc d2;

public :

	Collision(Disc d1, Disc d2, float f) : d1(d1), d2(d2), elasticConst(f) {
		normal = (d2.getPosition() - d1.getPosition()).normalize();
		relVelocity = (d2.getVelocity() - d1.getVelocity()).getNorm() * normal;
	}

	virtual void resolveCollision();
};

#endif
