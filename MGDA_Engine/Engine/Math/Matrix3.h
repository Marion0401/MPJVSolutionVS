#ifndef MATRIX3_H
#define MATRIX3_H

#include <iostream>
#include <math.h>

#include "./Vector3D.h"

class Matrix3 {

    float** mat;

    float DetAdjMat(int i, int j);

    public:
    
    Matrix3();
    Matrix3(const Matrix3& matrix);
    Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i);
    Matrix3(float r0[3], float r1[3], float r2[3]); 
    ~Matrix3();
    
    float* getMat() const {return *mat;}
    float getElement(int i, int j) const {
        return mat[i][j];
    }
    float* getColumn(int i) const {
        float* col = new float[3];
        col[0] = mat[0][i];
        col[1] = mat[1][i];
        col[2] = mat[2][i];
        return col;
    }
    float* getRow(int i) const {return mat[i];}

    void setElement(int i, int j, float e);
    void setColumn(int i, float c[3]);
    void setRow(int i, float r[3]);

    Matrix3& operator=(const Matrix3& m);

    Matrix3 operator+(const Matrix3& m);
    Matrix3 operator-(const Matrix3& m);
    Matrix3 operator*(const Matrix3& m);
    Matrix3 operator*(const float k);
    Vector3D operator*(const Vector3D& v);

    Matrix3 transpose();
    float det();
    Matrix3 inverse();
    bool isOrthogonal();
    Matrix3 gramSchmidt();

    static Matrix3 matRot(int axe, float theta) 
    {
        // axe 0 = x, axe 1 = y, axe 2 = z
        // theta in radians
        switch (axe)
        {
            case 0:
                return Matrix3(
                    1,0,0,
                    0,cosf(theta),-sinf(theta),
                    0,sinf(theta),cosf(theta)
                );
                break;
            case 1:
                return Matrix3(
                    cosf(theta),0,-sinf(theta),
                    0,1,0,
                    sinf(theta),0,cosf(theta)
                    );
                break;
            case 2:
                return Matrix3(
                    cosf(theta),-sinf(theta),0,
                    sinf(theta),cosf(theta),0,
                    0,0,1
                );
            break;
            default:
                return Matrix3();
                break;
        }
    }
    static Matrix3 matScale(float kx, float ky, float kz)
    {
        return Matrix3(kx,0,0,0,ky,0,0,0,kz);
    }
    static Matrix3 matProjection(bool px, bool py, bool pz)
    {
        return Matrix3(px,0,0,0,py,0,0,0,pz);
    }
    
};

#endif