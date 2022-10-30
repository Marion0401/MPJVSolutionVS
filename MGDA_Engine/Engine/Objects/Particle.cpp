#include "./Particle.h"

void Particle::setX(float nx) {
    position.setX(nx);
}

void Particle::setY(float ny) {
    position.setY(ny);
}

void Particle::setZ(float nz) {
    position.setZ(nz);
}

void Particle::setPosition(Vector3D newPos) {
    position = newPos;
}

void Particle::setVelocity(Vector3D newV) {
    velocity = newV;
}

void Particle::setAcceleration(Vector3D newV) {
    acceleration = newV;
}

void Particle::setMass(float nMass) {
    mass = nMass;
}

void Particle::move(Vector3D v) {
    position += v;
}

void Particle::addVelocity(Vector3D v) {
    velocity += v;
}

void Particle::addAcceleration(Vector3D a) {
    acceleration += a;
}

void Particle::integrer(float time) {
    position += velocity*time;
    velocity += acceleration*time;
}

bool Particle::operator==(const Particle& other) {
    if (mass == other.mass && velocity == other.velocity && position == other.position && acceleration == other.acceleration)
        return true;
    else
        return false;
}


std::ostream& operator<<(std::ostream& o, const Particle p) {
    o << "Mass : " << p.getMass() << std::endl;
    o << "Position : " << p.getPosition() << std::endl;
    o << "Velocity : " << p.getVelocity() << std::endl;
    o << "Acceleration : " << p.getAcceleration() << std::endl;
    return o;
}
