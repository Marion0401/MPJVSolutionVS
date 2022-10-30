#ifndef ROD_H
#define ROD_H

#include "Collision.h"

class Rod : public Collision {

	float l;

public :

	void resolveCollision() override;

};

#endif