#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <ostream>

class Vector3D 
{
    float x, y, z;
    float norm;

    void updateNorm();

    public:

    static const Vector3D up;
    static const Vector3D down;
    static const Vector3D left;
    static const Vector3D right;
    static const Vector3D front;
    static const Vector3D back;

    Vector3D();
    Vector3D(float x, float y, float z);
    Vector3D(float c[3]);
    
    float* getArray() const {return new float[3]{x,y,z};}
    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }
    float getNorm() const { return norm; }
    float getSqrNorm() const { return norm*norm; }

    void setX(float nx);
    void setY(float ny);
    void setZ(float nz);

    Vector3D normalize();
    void scalMult( float scal);
    Vector3D compProd ( Vector3D v);
    float scalProd ( Vector3D v);
    Vector3D vectProd (Vector3D v);

    Vector3D operator*(float scal) const;
    Vector3D operator+(const Vector3D& v);
    Vector3D operator-(const Vector3D& v);
    float operator*(Vector3D v);
    Vector3D operator^(const Vector3D& v);
    Vector3D& operator+=(const Vector3D& v);
    Vector3D& operator-=(const Vector3D& v);
    Vector3D& operator*=(const float f);
};

std::ostream& operator<<(std::ostream& o, const Vector3D v);

#endif
