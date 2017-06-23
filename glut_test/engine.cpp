#include "engine.h"

GLvoid Engine::SetProjectionMatrix(GLvoid){
	glMatrixMode(GL_PROJECTION);						// �������� ����� ������������� � �������� ��������
	glLoadIdentity();									// ������� ������� (��������) ������������ �� ���������
	glFrustum(-1, 1, -1, 1, 3, 10);						// ��������������� ������������� ��������
}

GLvoid Engine::SetModelviewMatrix(GLvoid){
	glMatrixMode(GL_MODELVIEW);							// �������� ����� ������������� � �������� ������
	glLoadIdentity();									// ������� ������� (������) ������������ �� ���������
	glTranslatef(0.0, 0.0, -7.0);						// ������� ��������� ����������� �� 8 ������ ������ �����													
	//glRotatef(30.0, 1.0, 0.0, 0.0);						// � �������������� �� 30 �������� ������ ��� x,
	//glRotatef(70.0, 0.0, 1.0, 0.0);						// � ����� �� 70 �������� ������ ��� y
}

GLvoid Engine::Resize(GLsizei width, GLsizei height){
	if (height == 0)									
	{
		height = 1;										
	}

	glViewport(0, 0, width, height);					// ��������������� ������� ���������

	Height = height;
	Width = width;

	SetProjectionMatrix();
	SetModelviewMatrix();
}

GLvoid Engine::Init(GLvoid){
	glClearColor(0.2f, 0.5f, 0.75f, 1.0f);				// ��������������� ����� ���
	glClearDepth(1.0f);									// ��������������� �������� ���
														// ���������� ������ ������� �� ���������
	glEnable(GL_DEPTH_TEST);							// ���������� ���� �������
	glDepthFunc(GL_LEQUAL);								// ��������������� ��������, ������������
														// � ���������� ��� �������������
														// ������ �������

	glShadeModel(GL_SMOOTH);							// ���������� ������� ���������
	glEnable(GL_LINE_SMOOTH);							// ���������� ����������� �����
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);				// ���������� ����� ������������
														// ����� ����������� ��� �����
	glEnable(GL_BLEND);									// ���������� �������� ������, �����������
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);	// ��� ������ ����������� � ��������
														// ������ ��������
}

GLvoid Engine::Draw(GLshort angl)									
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// ��������� ����� ����� � ����� �������
	glPushMatrix();										// ������������ ������� ������
	glColor3f(1.0f, 1.0f, 1.0f);						// �������� ������� ���� ����������
	glRotatef(angl, 0.0, 1.0, 0.0);	
	//glutWireCube(2.0f);									// �������� ����������� ��� �� �������� 2
	glutWireCube(1.0f);
	glPopMatrix();										// ����������������� ������� ������

	glPushMatrix();
	glTranslatef(1.5, 0.0, 0.0);
	glColor3f(0.0f, 1.0f, 1.0f);
	glRotatef(angl, 0.0, 1.0, 0.0);
	glutWireCube(1.0f);
	glPopMatrix();	
}
