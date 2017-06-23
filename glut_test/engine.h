#include "api.h"

#ifndef __ENGINE
#define __ENGINE

class Engine {
	GLshort Angl;
	GLsizei Height, Width;
	GLvoid SetProjectionMatrix(GLvoid);						// Задание проективного преобразования
	GLvoid SetModelviewMatrix(GLvoid);						// Задание преобразования модели-вида
public:
	GLvoid Rotate(GLshort angl);
	GLvoid Resize(GLsizei width, GLsizei height);			// Функция, вызываемая при изменении размеров окна
	GLvoid Init(GLvoid);									// Функция, для задания начальных параметров
	GLvoid Draw(GLshort angl);									// Отрисовка (render) сцены
};

#endif