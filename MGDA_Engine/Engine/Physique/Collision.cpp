#include "Collision.h"
#include "Gravity.h"

void Collision::resolveCollision(float deltaTime) {
	float penDist = -((d2.getPosition() - d1.getPosition()).getNorm() - d1.getRadius() - d2.getRadius());
	d1.move((d1.getMass() / d1.getMass() + d2.getMass()) * penDist * normal);
	d2.move(-(d2.getMass() / d1.getMass() + d2.getMass()) * penDist * normal);

	if (d1.getVelocity().getNorm() > Gravity::gconst * deltaTime) {
		float k = (elasticConst + 1) * relVelocity * normal / (d1.getInverseMass() + d2.getInverseMass());
		d1.addVelocity(-k * normal / d1.getMass());
		d2.addVelocity(k * normal / d2.getMass());
	}
}