#include "Cable.h"

void Cable::resolveCollision() {
	float overDist = (d2.getPosition() - d1.getPosition()).getNorm() - l;
	if (overDist > 0) {
		d1.move((d1.getMass() / d1.getMass() + d2.getMass()) * overDist * normal);
		d2.move(-(d2.getMass() / d1.getMass() + d2.getMass()) * overDist * normal);
		
		float k = (elasticConst + 1) * relVelocity * normal / (d1.getInverseMass() + d2.getInverseMass());
		d1.addVelocity(-k * normal / d1.getMass());
		d2.addVelocity(k * normal / d2.getMass());
	}
}