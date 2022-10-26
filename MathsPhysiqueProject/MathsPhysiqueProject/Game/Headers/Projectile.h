#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "../../../../Engine/src/Headers/Particle.h"

class Projectile : public Particle {

    float radius;

    public:

    Projectile();
    Projectile(float radius, float mass, Vector3D position, Vector3D velocity = Vector3D(), Vector3D acceleration = Vector3D()) : Particle(mass, position, velocity, acceleration), radius(radius){};
    
    static Projectile fireball(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile bullet(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile cannonball(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());
    static Projectile lazer(Vector3D position = Vector3D(), Vector3D velocite = Vector3D(), Vector3D acceleration = Vector3D());

    float getRadius() {return radius;}

    void setRadius(float newR);

    bool isHit(Vector3D pos);

};

#endif