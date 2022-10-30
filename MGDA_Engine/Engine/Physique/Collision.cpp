#include "Collision.h"

void Collision::resolveCollision() {
	float penDist = -((d2.getPosition() - d1.getPosition()).getNorm() - d1.getRadius() - d2.getRadius());
	d1.move((d1.getMass() / d1.getMass() + d2.getMass()) * penDist * normal);
	d2.move(-(d2.getMass() / d1.getMass() + d2.getMass()) * penDist * normal);

	float k = (elasticConst + 1) * relVelocity * normal / (d1.getInverseMass() + d2.getInverseMass());
	d1.addVelocity(- k * normal / d1.getMass());
	d2.addVelocity(k * normal / d2.getMass());
}