#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

int centerX, centerY, radiusX, radiusY, radius;
bool firstclick = false;

void drawCircle(int xc, int yc, int r) {
    glColor3f(0, 0, 0);
    int x = 0, y = r;
    int d = 3 - (2 * r);
    while (x <= y) {
        glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
        glVertex2i(xc + y, yc + x);
        glVertex2i(xc - y, yc + x);
        glVertex2i(xc + y, yc - x);
        glVertex2i(xc - y, yc - x);
        glEnd();
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear before drawing
    switch (key) {
        case '1':
            glColor3f(1, 0, 0);
            drawCircle(centerX, centerY, radius);
            drawCircle(centerX + radius * 2, centerY, radius);
            drawCircle(centerX - radius * 2, centerY, radius);
            drawCircle(centerX, centerY + radius * 2, radius);
            drawCircle(centerX, centerY - radius * 2, radius);
            break;

        case '2':
            glColor3f(1, 0, 0);
            drawCircle(centerX, centerY, radius);
            drawCircle(centerX + radius, centerY, radius);
            drawCircle(centerX - radius, centerY, radius);
            drawCircle(centerX, centerY + radius, radius);
            drawCircle(centerX, centerY - radius, radius);
            break;

        case '3':
            glColor3f(1, 0, 0);
            drawCircle(centerX, centerY, radius);
            drawCircle(centerX, centerY + (radius + radius / 2), radius / 2);
            drawCircle(centerX - radius, centerY + radius, radius / 2);
            drawCircle(centerX + (radius + radius / 2), centerY, radius / 2);
            drawCircle(centerX + radius, centerY - radius, radius / 2);
            drawCircle(centerX - (radius + radius / 2), centerY, radius / 2);
            drawCircle(centerX - radius, centerY - radius, radius / 2);
            drawCircle(centerX + radius, centerY + radius, radius / 2);
            drawCircle(centerX, centerY - (radius + radius / 2), radius / 2);
            break;

        case '4':
            glColor3f(1, 0, 0);
            drawCircle(centerX, centerY, radius);
            drawCircle(centerX + radius * 2, centerY, radius);
            drawCircle(centerX - radius * 2, centerY, radius);
            drawCircle(centerX - radius, centerY + radius, radius);
            drawCircle(centerX + radius, centerY + radius, radius);
            break;
    }
    glFlush();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!firstclick) {
            centerX = x;
            centerY = y;
            firstclick = true;
        } else {
            radiusX = x;
            radius = abs(radiusX - centerX);
            glClear(GL_COLOR_BUFFER_BIT);
            drawCircle(centerX, centerY, radius);
            glutKeyboardFunc(keyboard);
            firstclick = false;
        }
    }
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 1000, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("SIB60 Assignment 4");
    cout << "\n 1. FOUR CONCENTRIC CIRCLES";
    cout << "\n 2. FOUR INTERSECTING CIRCLES";
    cout << "\n 3. EIGHT CONCENTRIC CIRCLES";
    cout << "\n 4. OLYMPIC CIRCLES";
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
