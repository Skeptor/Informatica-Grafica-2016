#ifndef _JERARQUICO
#define _JERARQUICO

#include "objeto3D.h"
#include "ply.h"
#include "revolucion.h"
#include "portatil.h"
#include <GL/glut.h>
#include <vector>


class Jerarquico : public Objeto3D{
private:
	Objeto3D::DrawMode tipo = Objeto3D::CHESS;
		

public:
	Jerarquico();
	void crearPata();
	void crearMesa();
	void dibujarObjeto(float angulom, float angulop,int horizontal,int vertical,int bajap);
	void setTipo(Objeto3D::DrawMode tip);
	Cubo mcubo;
	int segmentos = 20;
	Portatil portatil;
	FiguraPLY ply_cilindro = FiguraPLY("PLY/cilindro.ply");
	Revolucion cilindro = Revolucion(ply_cilindro.vertices,segmentos,true,360);

};


#endif