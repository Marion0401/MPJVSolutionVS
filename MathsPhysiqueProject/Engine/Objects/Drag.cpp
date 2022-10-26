#include "../Headers/Drag.h"

void Drag::setDC(float ndc) 
{
	dragCoeff = ndc;
}

void Drag::update(float deltatime) override {
	v = p.getVelocity().getNorm();
	appliedForce = -p.getVelocity().normalize * v * v * dragCoeff;
}

