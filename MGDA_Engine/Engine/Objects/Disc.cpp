#include "./Disc.h"

void Disc::setRadius(float r) {
	radius = r;
}

float Disc::getArea() {
	return radius * radius * PI;
}

bool Disc::intersects(Disc d) {
	return (position - d.getPosition()).getNorm() < radius + d.getRadius()
}