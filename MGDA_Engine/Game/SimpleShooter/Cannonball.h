#ifndef CANNONBALL_H
#define CANNONBALL_H

#include "./Projectile.h"

static float cannonball_radius = 8;
static float cannonball_mass = 15;
static float cannonball_velocity = 100;

class Cannonball : public Projectile {
    public : 
    Cannonball(Vector3D position, Vector3D velocity, Vector3D acceleration):Projectile(cannonball_radius, cannonball_mass, position, velocity, acceleration) 
    {
        if (velocity.getNorm() == 1) { velocity *= cannonball_velocity;} 
    }
};

#endif