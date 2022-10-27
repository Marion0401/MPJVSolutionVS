#include <cmath>

#include "./Vector3D.h"

const Vector3D Vector3D::up = Vector3D(0, 0, 1);
const Vector3D Vector3D::down = Vector3D(0, 0, -1);
const Vector3D Vector3D::left = Vector3D(-1, 0, 0);
const Vector3D Vector3D::right = Vector3D(1, 0, 0);
const Vector3D Vector3D::front = Vector3D(0, 1, 0);
const Vector3D Vector3D::back = Vector3D(0, -1, 0);

Vector3D::Vector3D(): x(0), y(0), z(0) {
    updateNorm();
}
Vector3D::Vector3D(float x, float y, float z) : x(x), y(y), z(z) {
    updateNorm();
}
Vector3D::Vector3D(float c[3]) : Vector3D(c[0],c[1],c[2])
{}

void Vector3D::updateNorm() {
    norm = std::sqrt(x*x + y*y + z*z);
}

void Vector3D::setX(float nx) {
    x = nx;
    updateNorm();
}

void Vector3D::setY(float ny) {
    y = ny;
    updateNorm();
}

void Vector3D::setZ(float nz) {
    z = nz;
    updateNorm();
}

Vector3D Vector3D::normalize() {
    float n = sqrtf(x*x+y*y+z*z);
    Vector3D res = Vector3D(x/n,y/n,z/n);
    return res;
}

void Vector3D::scalMult(float scal) {
    x *= scal;
    y *= scal;
    z *= scal;
    norm *= scal;
}

Vector3D Vector3D::compProd(Vector3D v) {
    return Vector3D(x*v.getX(), y*v.getY(), z*v.getZ());
}

float Vector3D::scalProd(Vector3D v) {
    return x*v.getX() + y*v.getY() + z*v.getZ();
}

Vector3D Vector3D::vectProd(Vector3D v) {
    return Vector3D(y*v.getZ() - z*v.getY(), z*v.getX() - x*v.getZ(), x*v.getY() - y*v.getX());
}

Vector3D Vector3D::operator*(float scal) const {
    Vector3D res = Vector3D(x * scal, y * scal, z * scal);
    return res;
}

Vector3D Vector3D::operator+(const Vector3D& v) {
    Vector3D res = Vector3D(x + v.getX(),y + v.getY(),z + v.getZ());
    return res;
}

Vector3D Vector3D::operator-(const Vector3D& v) {
    Vector3D res = Vector3D(x - v.getX(),y - v.getY(),z - v.getZ());
    return res;
}

float Vector3D::operator*(Vector3D v) {
    return x*v.getX() + y*v.getY() + z*v.getZ();
}

Vector3D Vector3D::operator^(const Vector3D& v) {
    return Vector3D(y*v.getZ() - z*v.getY(), z*v.getX() - x*v.getZ(), x*v.getY() - y*v.getX());
}

Vector3D& Vector3D::operator+=(const Vector3D& v) {
    x += v.getX();
    y += v.getY();
    z += v.getZ();
    updateNorm();
    return *this;
}

Vector3D& Vector3D::operator-=(const Vector3D& v) {
    x -= v.getX();
    y -= v.getY();
    z -= v.getZ();
    updateNorm();
    return *this;
}

Vector3D& Vector3D::operator*=(const float f) {
    x *= f;
    y *= f;
    z *= f;
    norm *= f;
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Vector3D v) {
    o << "x = " << v.getX() << ", y = " << v.getY() << ", z = " << v.getZ() << ", norm = " << v.getNorm() << std::endl;
    return o;
}
