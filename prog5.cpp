#include<stdlib.h>
#include<glut.h>
#include<cmath>


float tx = 0.0, ty = 0.0,tz=0.0;
float scale = 1.0;
float anglex = 0.0, angley = 0.0, anglez = 0.0;


void init() {
	glEnable(GL_DEPTH_TEST);
}

void drawcube() {
	glBegin(GL_QUADS);

	//Front face:

	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);


	//Back FACE:
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	//left face:
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, 0.5,- 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, -0.5,0.5);


	//Rightface:
	glColor3f(1.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(0.5,-0.5, 0.5);

	//topface:
	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	//bottomface:
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

}

void display()
{
	glClearColor(1, 1, 1,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(tx, ty, tz);
	glRotatef(anglex, 1, 0, 0);
	glRotatef(angley, 0, 1,0);
	glRotatef(anglez, 0, 0, 1);
	glScalef(scale, scale, scale);
	drawcube();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':anglex += 5.0; break;
	case 'X':anglex -= 5.0; break;
	case 'y':angley += 5.0; break;
	case 'Y':angley -= 5.0; break;
	case 'z':anglez += 5.0; break;
	case 'Z':anglez -= 5.0; break;
	case '+':scale += 0.1; break;
	case '-':scale -= 0.1; break;
	case 'w':ty += 0.1; break;
	case 'W':ty -= 0.1; break;
	case 'a':tx += 0.1; break;
	case 'A':tx -= 0.1; break;
	case 's':tz += 0.1; break;
	case 'S':tz -= 0.1; break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D cube");
	init();
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}

