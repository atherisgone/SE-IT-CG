#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std;
void display();
float x1_, y1_, x2_, y2_;
bool firstClick = true;
int ch = 1;
void displayPoint(float x,float y) {
glColor3f(0, 0, 1);
glPointSize(2);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
void drawLine(float x1,float y1, float x2, float y2) {
float dx = x2 - x1, dy = y2 - y1;
float step = max(abs(dx), abs(dy));
float xinc = dx / step, yinc = dy / step;
float x = x1, y = y1;

for (int i = 0; i <= step; i++) {
displayPoint(x, y);
x += xinc;
y += yinc;
}
glFlush();
}
void drawCircle(int x1, int y1, int r1) {
int x = 0, y = r1;
int d = 3 - 2 * r1;
glBegin(GL_POINTS);
while (x <= y) {
glVertex2i(x1 + x, y1 + y);
glVertex2i(x1 - x, y1 + y);
glVertex2i(x1 + x, y1 - y);
glVertex2i(x1 - x, y1 - y);
glVertex2i(x1 + y, y1 + x);
glVertex2i(x1 - y, y1 + x);
glVertex2i(x1 + y, y1 - x);
glVertex2i(x1 - y, y1 - x);
x++;
if (d > 0) {
y--;
d = d + 4 * (x - y) + 10;
} else {
d = d + 4 * x + 6;}
}
glEnd();
glFlush();
}
void drawShape(float x,float y,float a) {
if (ch == 1) {
float r = a * 0.288675;
drawLine(x, y, x + a, y);
drawLine(x, y, x + 0.5 * a, y + 0.866 * a);
drawLine(x + 0.5 * a, y + 0.866 * a, x + a, y);
drawCircle(x + 0.5*a, y + r, r);
} else if (ch == 2) {
drawLine(x, y, x + a, y);
drawLine(x, y, x, y + a);
drawLine(x + a, y, x + a, y + a);
drawLine(x, y + a, x + a, y + a);
drawLine(x + 0.5 * a, y, x + a, y + 0.5 * a);
drawLine(x + 0.5 * a, y, x, y + 0.5 * a);
drawLine(x, y + 0.5 * a, x + 0.5 * a, y + a);
drawLine(x + 0.5 * a, y + a, x + a, y + 0.5 * a);
drawCircle(x + 0.5 * a, y + 0.5 * a, a * 0.3535);
}
}
void mouse(int button, int state, int x, int y) {
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
if (firstClick) {
x1_ = x;
y1_ = 600 - y;
firstClick = false;
} else {
x2_ = x;
y2_ = 600 - y;
float sideLength = sqrt(pow(x2_ - x1_, 2) + pow(y2_ - y1_, 2));
drawShape(x1_, y1_, sideLength);
firstClick = true;
}
}else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
display();
}
}
void keyboard(unsigned char key, int x, int y) {
glClear(GL_COLOR_BUFFER_BIT);
if (key == '1') {
ch = 1;
cout << "Triangle selected. Click two points to deﬁne the base and size.\n";
} else if (key == '2') {
ch = 2;
cout << "Square selected. Click two points to deﬁne the corner and size.\n";
}
glFlush();
}
void init() {
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 600, 0, 600);
}
void display() {
glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowSize(600, 600);
glutInitWindowPosition(300, 300);
glutCreateWindow("SIB55 Assignment 5");

init();
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutKeyboardFunc(keyboard);
glutMainLoop();
return 0;
}

