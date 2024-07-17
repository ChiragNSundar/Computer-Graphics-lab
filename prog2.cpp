#include<glut.h>
#include<cmath>
#include<stdlib.h>

float vertices[3][2] = {
	{0.0,0.5},
	{-0.5,-0.5},
	{0.5,-0.5}
};

float tx = 0.0, ty = 0.0;
float sx = 1.0, sy = 1.0;
float angle = 0.0;

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0,1.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h)
{	
	if (h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w>h)
		gluOrtho2D(-1.0*w/h, 1.0*w/h, -1.0, 1.0);
	else
		gluOrtho2D(-1.0, 1.0, -1.0*h/w, 1.0*h/w);
	glMatrixMode(GL_MODELVIEW);
	
}

void display() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	float x, y;
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		x = vertices[i][0];
		y = vertices[i][1];

		x *= sx;
		y *= sy;

		float rad = angle * 3.14 / 180.0;
		float xrot = x * (cos(rad)) - y * (sin(rad));
		float yrot = x * sin(rad) + y * cos(rad);
		x = xrot;
		y = yrot;

		x += tx;
		y += ty;
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
}

void keyboard(unsigned char button, int x, int y) {
	switch (button) {
	case 'w': ty += 0.1; break;
	case 's': ty -= 0.1; break;
	case 'a':tx -= 0.1; break;
	case 'd':tx += 0.1; break;
	case '+': sx += 0.1;
		sy += 0.1;
		if (sx > 2.0)
			sx = 0.1;
		if (sy > 2.0)
			sy = 0.1;
		break;
	case '-': sx -= 0.1;
		sy -= 0.1;
		if (sx < 0.1)
			sx = 2.0;
		if (sy < 0.1)
			sy = 2.0;
		break;
	case 'r':angle -= 5.0; break;
	case 'l':angle += 5.0; break;
	case 27: exit(0);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Transformations manual");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}


