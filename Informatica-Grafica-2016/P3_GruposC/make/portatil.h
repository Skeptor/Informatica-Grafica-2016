#ifndef _PORTATIL
#define _PORTATIL

#include "objeto3D.h"
#include "cubo.h"
#include <GL/glut.h>
#include <vector>

class Portatil: public Objeto3D{
private:
	Objeto3D::DrawMode tipo = Objeto3D::CHESS;

public:
	Cubo mcubo;
	Portatil();
	void dibujaBase();
	void dibujaTapa();
	void dibujaPortatil(float angulo,int horizontal, int vertical);
	void setTipo(Objeto3D::DrawMode tip);

};

#endif