#include "portatil.h"
using namespace std;

Portatil::Portatil(){
};
void Portatil::dibujaBase(){
	glPushMatrix();
	glTranslatef(0,25,0);
	glScalef(0.5,0.05,0.5);
	mcubo.draw(tipo);
	glPopMatrix();
}

void Portatil::dibujaTapa(){
	glPushMatrix();
	glTranslatef(25,38,0);
	glScalef(0.05,0.3,0.5);
	mcubo.draw(tipo);
	glPopMatrix();
}
void Portatil::dibujaPortatil(float angulo, int horizontal, int vertical){
	glPushMatrix();
	glRotatef(angulo,0.0,1.0,0.0);
	glTranslatef(horizontal,0,vertical);
	dibujaBase();
	dibujaTapa();
	glPopMatrix();
};


void Portatil::setTipo(Objeto3D::DrawMode tip){
		tipo = tip;
	};