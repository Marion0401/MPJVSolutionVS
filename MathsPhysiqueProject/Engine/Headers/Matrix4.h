#ifndef MATRIX4_H
#define MATRIX4_H

class Matrix4
{
    float** mat;

    float DetAdjMat(int i, int j);

    public :

    Matrix4();
    Matrix4(Matrix4& matrice);
    Matrix4(float row0[4],float row1[4],float row2[4],float row3[4]);
    Matrix4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p);
    ~Matrix4();

    float* getMat() const {return *mat;}
    float getElement(int i, int j) const {
        return mat[i][j];
    }
    float* getColumn(int i) const {
        float* col = new float[4];
        col[0] = mat[0][i];
        col[1] = mat[1][i];
        col[2] = mat[2][i];
        col[3] = mat[3][i];
        return col;
    }
    float* getRow(int iRow) const {return mat[iRow];}

    void setElement(int iRow, int iColumn, float element);
    void setColumn(int iColumn, float column[4]);
    void setRow(int iRow, float row[4]);

    Matrix4& operator=(const Matrix4 &m);
   
    Matrix4 operator+(const Matrix4& m);
    Matrix4 operator-(const Matrix4& m);
    Matrix4 operator*(const Matrix4& m);
    Matrix4 operator*(const float k);

    Matrix4 transpose();
    float determinant();
    Matrix4 inverseMatrix();
    bool isOrthogonal();
    
};

#endif
