#include "../Headers/Matrix3.h"

Matrix3::Matrix3(){
    mat = new float*[3]{new float[3]{0,0,0},new float[3]{0,0,0},new float[3]{0,0,0}};
}
Matrix3::Matrix3(Matrix3& matrix): Matrix3(matrix.getRow(0),matrix.getRow(1),matrix.getRow(2)){}
Matrix3::Matrix3(float a, float b, float c, float d, float e, float f, float g, float h, float i){
    mat = new float*[3]{new float[3]{a,b,c},new float[3]{d,e,f},new float[3]{g,h,i}};
}
Matrix3::Matrix3(float r0[3], float r1[3], float r2[3]) : Matrix3() {
    setRow(0, r0);
    setRow(1, r1);
    setRow(2, r2);
}
Matrix3::~Matrix3(){
    delete mat[0];
    delete mat[1];
    delete mat[2];
    delete mat;
}
void Matrix3::setElement(int i, int j, float e){
    mat[i][j] = e;
}
void Matrix3::setColumn(int i, float c[3]){
    for(int j = 0; j < 3; j++){
        setElement(j,i, c[j]);
    }
}
void Matrix3::setRow(int i, float r[3]){
    for(int j = 0; j < 3; j++){
        setElement(i,j, r[j]);
    }
}

Matrix3& Matrix3::operator=(const Matrix3 & m)
{ 
    if ( this != &m ) 
    { 
        for (int i=0; i<3; i++)
        {
            for  (int j=0; j<3; j++)
            {
                setElement(i,j,m.getElement(i,j));
            }   
        }
    } 
    return *this; 
} 

Matrix3 Matrix3::operator+(const Matrix3& m) {
    Matrix3 res = Matrix3();
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            res.setElement(i, j, getElement(i,j) + m.getElement(i,j));
        }
    }
    return res;
}

Matrix3 Matrix3::operator-(const Matrix3& m) {
    Matrix3 res = Matrix3();
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            res.setElement(i, j, getElement(i,j) - m.getElement(i,j));
        }
    }
    return res;
}

Matrix3 Matrix3::operator*(const Matrix3& m) {
    Matrix3 res = Matrix3();
    float temp;
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            temp = 0;
            for (int k=0;k<3;k++) {
                temp += getElement(i,k)*m.getElement(k,j);
            }
            res.setElement(i,j,temp);
        }
    }
    return res;
}

Matrix3 Matrix3::operator*(const float k) {
    Matrix3 res = Matrix3();
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            res.setElement(i,j,getElement(i,j)*k);
        }
    }
    return res;
}

Vector3D Matrix3::operator*(const Vector3D& v) {
    Vector3D res = Vector3D(
        getElement(0,0)*v.getX()+getElement(0,1)*v.getY()+getElement(0,2)*v.getZ(),
        getElement(1,0)*v.getX()+getElement(1,1)*v.getY()+getElement(1,2)*v.getZ(),
        getElement(2,0)*v.getX()+getElement(2,1)*v.getY()+getElement(2,2)*v.getZ()
    );
    return res;
}

Matrix3 Matrix3::transpose(){
    Matrix3 res = Matrix3();
    for (int i=0; i<3; i++) {
        for (int j=0;j<3;j++) {
            res.setElement(i,j,getElement(j,i));
        }
    }
    return res;
}

float Matrix3::det(){
    return getElement(0,0)*getElement(1,1)*getElement(2,2)
    + getElement(0,1)*getElement(1,2)*getElement(2,0)
    + getElement(0,2)*getElement(1,0)*getElement(2,1)
    - getElement(0,0)*getElement(1,2)*getElement(2,1)
    - getElement(0,1)*getElement(1,0)*getElement(2,2)
    - getElement(0,2)*getElement(1,1)*getElement(2,0);
} 

float Matrix3::DetAdjMat(int i, int j){
    if(i == 0 && j == 0)
    {
        return getElement(1,1)*getElement(2,2)-getElement(1,2)*getElement(2,1);
    } else if (i == 0 && j == 1)
    {
        return getElement(1,0)*getElement(2,2)-getElement(1,2)*getElement(2,0);
    } else if (i == 0 && j == 2)
    {
        return getElement(1,0)*getElement(2,1)-getElement(1,1)*getElement(2,0);
    } else if (i == 1 && j == 0)
    {
        return getElement(0,1)*getElement(2,2)-getElement(0,2)*getElement(2,1);
    } else if (i == 1 && j == 1)
    {
        return getElement(0,0)*getElement(2,2)-getElement(0,2)*getElement(2,0);
    } else if (i == 1 && j == 2)
    {
        return getElement(0,0)*getElement(2,1)-getElement(0,1)*getElement(2,0);
    } else if (i == 2 && j == 0)
    {
        return getElement(0,1)*getElement(1,2)-getElement(0,2)*getElement(1,1);
    } else if (i == 2 && j == 1)
    {
        return getElement(0,0)*getElement(1,2)-getElement(0,2)*getElement(1,0);
    } else 
    {
        return getElement(0,0)*getElement(1,1)-getElement(0,1)*getElement(1,0);
    }   
}

Matrix3 Matrix3::inverse(){
    Matrix3 res = Matrix3();
    float d = det();
    if(d != 0)
    {
        for (int i=0; i<3; i++) {
            for (int j=0;j<3;j++) {
                if((i+j)%2 == 0)
                {
                    res.setElement(i,j,DetAdjMat(i,j));
                } else 
                {
                    res.setElement(i,j,-DetAdjMat(i,j));
                }
                
            }
        }
        res = res*(1/d);
    } 
    return res.transpose();
}

bool Matrix3::isOrthogonal()
{
    if(det() != 0)
    {
        Matrix3 tM = Matrix3(*this).transpose();
        Matrix3 invM = Matrix3(*this).inverse(); 
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(tM.getElement(i,j) != invM.getElement(i,j)) return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

//Commit test

Matrix3 Matrix3::gramSchmidt() {
    Matrix3 res = Matrix3();
    Vector3D c1 = Vector3D(getColumn(0));
    Vector3D c2 = Vector3D(getColumn(1));
    Vector3D c3 = Vector3D(getColumn(2));
    c1 = c1.normalize();
    res.setColumn(0,c1.getArray());
    c2 = c2 - c1*(c2.scalProd(c1));
    res.setColumn(1, c2.normalize().getArray());
    c3 = c3 - c1*(c3.scalProd(c1)) - c2*(c3.scalProd(c2));
    res.setColumn(2, c3.normalize().getArray());
    return res;
}


