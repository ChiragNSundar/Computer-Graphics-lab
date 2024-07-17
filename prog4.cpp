#include<glut.h>
#include<stdlib.h>
#include<cmath>


float scale = 1.0;
float tx = 0.0, ty = 0.0;
float angle = 0.0;

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w,int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
		gluOrtho2D(-10.0*w/h, 10.0*w/h, -10.0, 10.0);
	else
		gluOrtho2D(-10.0, 10.0, -10.0*h/w, 10.0*h/w);
	glMatrixMode(GL_MODELVIEW);
}

void display()
{
	glClearColor(1.0,1.0,1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(tx, ty, 0.0);
	glScalef(scale, scale, 1.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.5, -0.5);
	glVertex2f(0.5, 0.5);
	glVertex2f(-0.5, 0.5);
	glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case '+':
		if(scale<2.0)
			scale += 0.1;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case '-':
		if (scale > 0.1)
			scale -= 0.1;
		reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;
	case 'd':
		tx += 0.1;
		break;
	case 'a':
		tx -= 0.1;
		break;
	case 'w':
		ty += 0.1;
		break;
	case 's':
		ty -= 0.1;
		break;
	case 'r':
		angle += 5;
		break;
	case 'l':
		angle -= 5;
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformations inbuilt");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}