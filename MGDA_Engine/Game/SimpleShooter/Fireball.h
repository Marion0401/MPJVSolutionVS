#ifndef FIREBALL_H
#define FIREBALL_H

#include "./Projectile.h"

    static float fireball_radius = 5; //en cm
    static float fireball_mass = 0.005;  // en kg
    static float fireball_velocity = 10; // en m/s

class Fireball : public Projectile {
    public : 
    Fireball(Vector3D position, Vector3D velocity, Vector3D acceleration):Projectile(fireball_radius, fireball_mass, position, velocity, acceleration) 
    {
        if (velocity.getNorm() == 1) { velocity *= fireball_velocity;} 
    }
};

#endif