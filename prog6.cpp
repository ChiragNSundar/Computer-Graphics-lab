#include<glut.h>
#include<cmath>


bool roten = false;
float angle=0.0f;
float x, y, r = 50;
void init()
{	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	if (roten == true)
	{
		angle += 0.1f;
		if (angle >= 360)
			angle = 0.0f;
	}
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h)
	{
		gluOrtho2D(-100.0*w/h,100.0*w / h, -100, 100);
	}
	else
		gluOrtho2D(-100, 100, -100.0*h / w, 100.0*h / w);
	glMatrixMode(GL_MODELVIEW);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		roten = true;
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		roten = false;
	}
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	x = r * cos(angle * 3.14 / 180.0);
	y = r * sin(angle * 3.14 / 180.0);
	glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(-y, x);
		glVertex2f(-x, -y);
		glVertex2f(y, -x);
		glEnd();
		glutSwapBuffers();
}


int main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotating Square");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}