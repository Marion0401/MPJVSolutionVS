#include <GL/glut.h>


#include<iostream>


using namespace std;


int rx = 100, ry = 125;
int xCenter = 250, yCenter = 250;

void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void setPixel(GLint x, GLint y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawFilledCircle() {
    int i, x, y;
    double radius = 25;
    int triangleAmount = 20;

    glColor3ub(255, 0, 0);
    double twicePi = 2.0 * 3.142;
    x = 0, y = 0;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(xCenter, yCenter); // center of circle

    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            (xCenter + (radius * cos(i * twicePi / triangleAmount))),
            (yCenter + (radius * sin(i * twicePi / triangleAmount)))
        );
    }
    glEnd();
    glFlush(); //END
}


void ellipseMidPoint()
{
    float x = 0;
    float y = ry;
    float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
    float dx = 2 * (ry * ry) * x;
    float dy = 2 * (rx * rx) * y;
    glColor3ub(255, 0, 0);


    while (dx < dy)
    {
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p1 < 0)
        {
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            p1 = p1 + dx + (ry * ry);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + dx - dy + (ry * ry);
        }

    }
    glFlush();
    float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y
        - 1) * (y - 1) - (rx * rx) * (ry * ry);
    glColor3ub(255, 0, 0);
    while (y > 0)
    {
        setPixel(xCenter + x, yCenter + y);
        setPixel(xCenter - x, yCenter + y);
        setPixel(xCenter + x, yCenter - y);
        setPixel(xCenter - x, yCenter - y);
        if (p2 > 0)
        {
            x = x;
            y = y - 1;
            dy = 2 * (rx * rx) * y;
            p2 = p2 - dy + (rx * rx);
        }
        else
        {
            x = x + 1;
            y = y - 1;
            dy = dy - 2 * (rx * rx);
            dx = dx + 2 * (ry * ry);
            p2 = p2 + dx -
                dy + (rx * rx);
        }
    }
    glFlush();
}

//keyboard controlling

void specialKey(int key, int x, int y) {
    switch (key)
    {
    case GLUT_KEY_UP:
        yCenter = yCenter + 1;
        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        yCenter--;
        cout << y << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        xCenter--;
        cout << x << endl;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        xCenter++;
        cout << x << endl;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(1.0);

    drawFilledCircle();
    //ellipseMidPoint();
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("User_Name");
    myinit();
    glutDisplayFunc(display);
    glutSpecialFunc(specialKey); // sets the special keyboard callback for the current w
    glutMainLoop();
    return 0;
}