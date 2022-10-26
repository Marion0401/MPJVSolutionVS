#ifndef DRAG_H
#define DRAG_H

#include "Force.h"

class Drag : public Force {

	float dragCoeff;


public:
	Drag(float c, Particle p) : Force(p), dragCoeff(c) {};

	float getDC() { return dragCoeff; }

	void setDC(float ndc);

	void update(float deltatime) override;

};
#endif