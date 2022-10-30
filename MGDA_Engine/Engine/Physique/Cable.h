#ifndef CABLE_H
#define CABLE_H

#include "Collision.h"

class Cable : public Collision {
	float l;

public :
	Cable(Disc d1, Disc d2, float ce, float l) : Collision(d1, d2, ce), l(l) {};

	void resolveCollision() override;
};

#endif
