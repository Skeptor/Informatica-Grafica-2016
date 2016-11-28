#include "jerarquico.h"
using namespace std;

Jerarquico::Jerarquico(){};

void Jerarquico::crearPata(){
	glPushMatrix();
	glScalef(0.2,1,0.2);
	glTranslatef(-150,-50,-150);
	mcubo.draw(tipo);
	glTranslatef(0,0,300);
	mcubo.draw(tipo);
	glTranslatef(300,0,0);
	mcubo.draw(tipo);
	glTranslatef(0,0,-300);
	mcubo.draw(tipo);
	glPopMatrix();
};

void Jerarquico::crearMesa(){
	glPushMatrix();
	//glTranslatef(0,50,0);
	glScalef(1,0.3,1);
	cilindro.draw(tipo);
	glPopMatrix();
};


void Jerarquico::dibujarObjeto(float angulom, float angulop, int horizontal, int vertical,int bajap){
	glPushMatrix();
	glRotatef(angulom,0.0,1.0,0.0);
	portatil.dibujaPortatil(angulop,horizontal,vertical);	
	crearMesa();
	glPopMatrix();
	glPushMatrix();
	glScalef(1,bajap,1);
	crearPata();
	glPopMatrix();
};

	void Jerarquico::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};
