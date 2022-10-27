#ifndef BULLET_H
#define BULLET_H

#include "./Projectile.h"

static float bullet_radius = 0.3;
static float bullet_mass = 0.040;
static float bullet_velocity = 250;

class Bullet : public Projectile {
    public : 
    Bullet(Vector3D position, Vector3D velocity, Vector3D acceleration):Projectile(bullet_radius, bullet_mass, position, velocity, acceleration) 
    {
        if (velocity.getNorm() == 1) { velocity *= bullet_velocity;} 
    }
};

#endif