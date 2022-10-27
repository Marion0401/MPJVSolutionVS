#include "./Drag.h"

void Drag::setDC(float ndc) 
{
	dragCoeff = ndc;
}

void Drag::update(float deltatime) {
	float v = p.getVelocity().getNorm();
	appliedForce = p.getVelocity().normalize() * (-1) * v * v * dragCoeff;
}

