#ifndef LAZER_H
#define LAZER_H

#include "Projectile.h"

static float lazer_radius = 1;
static float lazer_mass = 0;
static float lazer_velocity = 300000000;

class Lazer : public Projectile {
    public : 
    Lazer(Vector3D position, Vector3D velocity, Vector3D acceleration):Projectile(lazer_radius, lazer_mass, position, velocity, acceleration) 
    {
        if (velocity.getNorm() == 1) { velocity *= lazer_velocity;} 
    }
};

#endif
