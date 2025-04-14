#include <GL/glut.h>

float x = 300, y = 300;
float dx = 2.0f, dy = 3.0f;
int windowWidth = 600, windowHeight = 600;

void displayPoint(float x, float y) {
    glColor3f(1, 0, 0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    displayPoint(x, y);
    glFlush();
}

void timer(int value) {
    x += dx;
    y += dy;

    if (x <= 0 || x >= windowWidth) dx = -dx;
    if (y <= 0 || y >= windowHeight) dy = -dy;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Bouncing Point Animation");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;
}
