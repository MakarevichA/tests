#include "engine.h"
#include <iostream>
#include <math.h>
using namespace std;
Engine *engine;
short angl(0);

// ���� �������� ������
float angle=0.0;
// ���������� ������� ����������� �������� ������
float lx=0.0f, lz=-1.0f;
// XZ ������� ������
float x=0.0f, z=5.0f;
//����� ������� ������. ���������� ���������������� �������� ����������
//����� ������� �� ������
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;

void mouseButton(int button, int state, int x, int y) {
 
	// ������ ��� ������ ��������, ���� ������ ����� ������
	if (button == GLUT_LEFT_BUTTON) {
 
		// ����� ������ ��������
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
	{cout<<angle<<endl;}
}


void mouseMove(int x, int y) {
 
	// ���� ����� ������ �������
	if (xOrigin >= 0) {
 
		// �������� deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;
 
		// ���������� ����������� ������
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
	{cout<<deltaAngle<<endl;}
}


GLvoid display(GLvoid)
{
	cout<<"render"<<endl;
	engine->Draw(angl);
	angl+=3;
	glutSwapBuffers();
}

GLvoid mouseInOut(int state)
{
	if (state == GLUT_LEFT)
		{cout<<"mouse out"<<endl;}
	else 
		{cout<<"mouse in"<<endl;}
}

GLvoid reshape(GLsizei width, GLsizei height)
{
	engine->Resize(width, height);
}

void timf(int value) // Timer function
{
  glutPostRedisplay();  // Redraw windows
  glutTimerFunc(40, timf, 0); // Setup next timer
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	int gmWindow = glutCreateWindow("2.1. ������ OpenGL ���������� c �������������� GLUT. (�) compgraphics.info");
	//glutFullScreen();
	engine = new Engine();
	engine->Init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutEntryFunc(mouseInOut);
		glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
	glutIdleFunc(display);
	//glutTimerFunc(40, timf, 0);
	glutMainLoop();
	return 0;
}
