#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vector3D.h"

class Particle {

protected:
    Vector3D position, velocity, acceleration;
    float mass;


public:
    Particle() = default;
    Particle(float mass, Vector3D position) : mass(mass), position(position){};
    Particle(float mass, Vector3D position, Vector3D velocity) : mass(mass), position(position), velocity(velocity){};
    Particle(float mass, Vector3D position, Vector3D velocity, Vector3D acceleration) : mass(mass),  position(position), velocity(velocity), acceleration(acceleration){};

    float getX() const {return position.getX();}
    float getY() const {return position.getY();}
    float getZ() const {return position.getZ();}
    Vector3D getPosition() const {return position;}
    Vector3D getVelocity() const {return velocity;}
    Vector3D getAcceleration() const {return acceleration;}
    float getMass() const {return mass;}
    float getInverseMass() const {return 1/mass;}

    void setX(float nx);
    void setY(float ny);
    void setZ(float nz);
    void setPosition(Vector3D newPos);
    void setVelocity(Vector3D newV);
    void setAcceleration(Vector3D newA);
    void setMass(float nMass);

    void addVelocity(Vector3D v);
    void addAcceleration(Vector3D a);

    void integrer(float deltaTime);
};

std::ostream& operator<<(std::ostream& o, const Particle p);

#endif