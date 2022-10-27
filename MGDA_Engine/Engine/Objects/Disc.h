#ifndef DISC_H
#define DISC_H

#include "./Object.h"
#include "../Math/Vector3D.h"

class Disc : public Object {
	
	static const float PI;

	float radius;

public :
	
	Disc(float r, Vector3D p) : Object(p), radius(r) {}

	float getRadius() { return radius; }

	void setRadius(float f);

	float getArea() override;
	bool intersects(Disc d);

};

#endif