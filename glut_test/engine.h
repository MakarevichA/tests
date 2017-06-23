#include "api.h"

#ifndef __ENGINE
#define __ENGINE

class Engine {
	GLshort Angl;
	GLsizei Height, Width;
	GLvoid SetProjectionMatrix(GLvoid);						// ������� ������������ ��������������
	GLvoid SetModelviewMatrix(GLvoid);						// ������� �������������� ������-����
public:
	GLvoid Rotate(GLshort angl);
	GLvoid Resize(GLsizei width, GLsizei height);			// �������, ���������� ��� ��������� �������� ����
	GLvoid Init(GLvoid);									// �������, ��� ������� ��������� ����������
	GLvoid Draw(GLshort angl);									// ��������� (render) �����
};

#endif