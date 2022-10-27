#include "./Projectile.h"

float fireball_radius = 5; //in cm
float fireball_mass = 0.005;  //in kg
float fireball_velocity = 10; //in m/s
float bullet_radius = 0.3;
float bullet_mass = 0.040;
float bullet_velocity = 250;
float cannonball_radius = 8;
float cannonball_mass = 15;
float cannonball_velocity = 100;
float lazer_radius = 1;
float lazer_mass = 0;
float lazer_velocity = 300000000;


void Projectile::setRadius(float newR) {
    radius = newR;
}

bool Projectile::isHit(Vector3D pos) {
    if ((pos - position).getNorm() < radius) {
        return true;
    }
    return false;
}

Projectile Projectile::fireball(Vector3D position, Vector3D velocity, Vector3D acceleration) {
    if (velocity.getNorm() == 1) {
        return Projectile(fireball_radius, fireball_mass, position, velocity*fireball_velocity, acceleration);
    } else {
        return Projectile(fireball_radius, fireball_mass, position, velocity, acceleration);
    }
}

Projectile Projectile::bullet(Vector3D position, Vector3D velocity, Vector3D acceleration) {
    if (velocity.getNorm() == 1) {
        return Projectile(bullet_radius, bullet_mass, position, velocity*bullet_velocity, acceleration);
    } else {
        return Projectile(bullet_radius, bullet_mass, position, velocity, acceleration);
    }
}

Projectile Projectile::cannonball(Vector3D position, Vector3D velocity, Vector3D acceleration) {
    if (velocity.getNorm() == 1) {
        return Projectile(cannonball_radius, cannonball_mass, position, velocity*cannonball_velocity, acceleration);
    } else {
        return Projectile(cannonball_radius, cannonball_mass, position, velocity, acceleration);
    }
}

Projectile Projectile::lazer(Vector3D position, Vector3D velocity, Vector3D acceleration) {
    if (velocity.getNorm() == 1) {
        return Projectile(lazer_radius, lazer_mass, position, velocity*lazer_velocity, acceleration);
    } else {
        return Projectile(lazer_radius, lazer_mass, position, velocity, acceleration);
    }
}
