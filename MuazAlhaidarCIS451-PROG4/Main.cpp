// Name: Muaz Alhaidar
//
// Description:
// Draw a staple remover jaw using Evaluators and the data given
// 
// Date: 11/26/2019

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glut.h>

GLfloat ctrlpoints[13][3] = {
		{1.0,	1.0,	0.0},
		{7.0,	1.0,	0.0},
		{9.0,	1.0,	0.0},
		{9.0,	3.0,	0.0},
		{7.0,	3.0,	0.0},
		{6.0,	3.0,	0.0},
		{5.5,	2.5,	0.0},
		{5.0,	2.0,	0.0},
		{2.0,	2.0,	0.0},
		{1.2,	2.0,	0.0},
		{1.0,	3.0,	0.0},
		{0.7,	2.0,	0.0},
		{1.0,	1.0,	0.0}
};

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void drawStaplerJaw(void) {

	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &ctrlpoints[0][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[1][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &ctrlpoints[4][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[5][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &ctrlpoints[7][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[8][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[10][0]);
	glEnable(GL_MAP1_VERTEX_3);

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i <= 100; i++)
		glEvalCoord1f((GLfloat)i / 100.0);
	glEnd();

	/* The following code displays the control points as dots. */
	glPointSize(3.0);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	for (i = 0; i < 13; i++)
		glVertex3fv(&ctrlpoints[i][0]);
	glEnd();
}

void display(void)
{
	
	drawStaplerJaw();

	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-1.0, 11.0, -5.0 * (GLfloat)h / (GLfloat)w, 5.0 * (GLfloat)h / (GLfloat)w, -5.0, 5.0);
	else
		glOrtho(-1.0 * (GLfloat)w / (GLfloat)h, 11.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Muaz Alhaidar PROG-4 Stapler Jaw");

	init();

	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutMainLoop();
	return 0;
}