#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../Engine/Objects/Particle.h"
#include "../../Engine/Math/Vector3D.h"

class Projectile : public Particle {

    float radius;

    public:

    Projectile(float radius, float mass, Vector3D position, Vector3D velocity = Vector3D(), Vector3D acceleration = Vector3D()) : Particle(mass, position, velocity, acceleration), radius(radius){};
    Projectile(const Projectile& p) : Particle(p.getMass(), p.getPosition(), p.getVelocity(), p.getAcceleration()), radius(p.getRadius()) {};
    
    static Projectile fireball(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile bullet(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile cannonball(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile lazer(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());

    float getRadius() const {return radius;}

    void setRadius(float newR);

    bool isHit(Vector3D pos);

};

#endif