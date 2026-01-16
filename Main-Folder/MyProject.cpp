#include <GL/glut.h>
#include <cmath>

// positions
float x1 = -1.0f;
float x2 = 1.0f;
float y_pos = -1.0f;  // changed from y1 to y_pos

// draw circle function
void drawCircle(float cx, float cy, float r) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416 / 180;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

// display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 🔴 Moving Circle 1
    glColor3f(1, 0, 0);
    drawCircle(x1, 0.5f, 0.1f);

    // 🔵 Moving Circle 2
    glColor3f(0, 0, 1);
    drawCircle(x2, -0.3f, 0.12f);

    // 🟩 Moving Square
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, y_pos);
        glVertex2f( 0.2f, y_pos);
        glVertex2f( 0.2f, y_pos + 0.3f);
        glVertex2f(-0.2f, y_pos + 0.3f);
    glEnd();

    glFlush();
}

// animation timer
void timer(int) {
    x1 += 0.01f;
    x2 -= 0.015f;
    y_pos += 0.01f;

    // reset positions
    if (x1 > 1.2f) x1 = -1.2f;
    if (x2 < -1.2f) x2 = 1.2f;
    if (y_pos > 1.2f) y_pos = -1.2f;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);  // ~60 FPS
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Multiple Animated Objects - GLUT");

    glClearColor(0, 0, 0, 1);

    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
