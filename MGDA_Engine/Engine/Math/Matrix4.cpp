#include "./Matrix4.h"
#include "./Matrix3.h"
#include "./Vector3D.h"

Matrix4::Matrix4(){
    mat = new float*[4]{new float[4]{0,0,0},new float[4]{0,0,0},new float[4]{0,0,0}, new float[4]{0,0,0}};
}
Matrix4::Matrix4(Matrix4& matrice): Matrix4(matrice.getRow(0),matrice.getRow(1),matrice.getRow(2),matrice.getRow(3)){}
Matrix4::Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p){
    mat = new float*[4]{new float[4]{a,b,c,d},new float[4]{e,f,g,h},new float[4]{i,j,k,l}, new float[4]{m,n,o,p}};
}
Matrix4::Matrix4(float row0[4], float row1[4], float row2[4], float row3[4]) : Matrix4()
{
    setRow(0, row0);
    setRow(1, row1);
    setRow(2, row2);
    setRow(3, row3);
}
Matrix4::~Matrix4(){
    delete mat[0];
    delete mat[1];
    delete mat[2];
    delete mat[3];
    delete mat;
}
void Matrix4::setElement(int iRow, int iColumn, float element){
    mat[iRow][iColumn] = element;
}
void Matrix4::setColumn(int iColumn, float column[4])
{
    for(int index = 0; index < 4; index++){
        setElement(index,iColumn, column[index]);
    }
}

void Matrix4::setRow(int iRow, float row[4]){
    for(int index = 0; index < 4; index++)
    {
        setElement(iRow,index, row[index]);
    }
}

Matrix4 & Matrix4::operator=(const Matrix4 & mat)
{ 
    if ( this != &mat ) 
    { 
        for (int i=0; i<4; i++)
        {
            for  (int j=0; j<4; j++)
            {
                setElement(i,j,mat.getElement(i,j));
            }   
        }
    } 
    return *this; 
} 

Matrix4 Matrix4::operator+(const Matrix4& m){
    Matrix4 result = Matrix4();
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            result.setElement(i, j, getElement(i,j) + m.getElement(i,j));
        }
    }
    return result;
}

Matrix4 Matrix4::operator-(const Matrix4& m){
    Matrix4 result = Matrix4();
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            result.setElement(i, j, getElement(i,j) - m.getElement(i,j));
        }
    }
    return result;
}

Matrix4 Matrix4 :: operator*(const float k){
    Matrix4 result = Matrix4();
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            result.setElement(i, j, getElement(i,j)*k);
        }
    }
    return result;
}

Matrix4 Matrix4 :: operator*(const Matrix4 &m)
{
    Matrix4 result = Matrix4();
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            float temp = 0;
            for (int k=0;k<4;k++) {
                temp += getElement(i,k)*m.getElement(k,j);
            }
            result.setElement(i, j, temp);
        }
    }
    return result;
}

Matrix4 Matrix4::transpose(){
    Matrix4 result = Matrix4();
    for (int i=0; i<4; i++) {
        for (int j=0;j<4;j++) {
            result.setElement(i,j,getElement(j,i));
        }
    }
    return result;
}

float Matrix4::determinant()
{
    Matrix3 mat31;
    Matrix3 mat32;
    Matrix3 mat33;
    Matrix3 mat34;

    mat31=Matrix3(getElement(1,1), getElement(1,2),getElement(1,3),getElement(2,1),getElement(2,2),getElement(2,3), getElement(3,1),getElement(3,2),getElement(3,3));
    mat32=Matrix3(getElement(1,0),getElement(1,2),getElement(1,3),getElement(2,0),getElement(2,2),getElement(2,3),getElement(3,0),getElement(3,2),getElement(3,3));
    mat33=Matrix3(getElement(1,0),getElement(1,1),getElement(1,3),getElement(2,0),getElement(2,1),getElement(2,3),getElement(3,0),getElement(3,1),getElement(3,3));
    mat34=Matrix3(getElement(1,0),getElement(1,1),getElement(1,2),getElement(2,0),getElement(2,1),getElement(2,2),getElement(3,0),getElement(3,1),getElement(3,2));

    return getElement(0,0)*mat31.det() - getElement(0,1)*mat32.det() + getElement(0,2)*mat33.det() - getElement(0,3)*mat34.det();

}

/*
Matrix4 Matrix4 ::adj()
{
    Matrix4 mAdj;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(j%2!=0)
            {
                mAdj.setElement(i,j,-getElement(i,j));
            }
            else{
                mAdj.setElement(i,j,getElement(i,j));
            }
        }
    }
    return mAdj;
}
*/

/*
Matrix4 Matrix4::inverseMatrix(){
    Matrix4 result;
    result= adj() * (1/determinant());
    return result.transpose();
}
*/
