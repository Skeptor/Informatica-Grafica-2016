#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "objeto3D.h"
#include "cubo.h"
#include "tetraedro.h"
class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;


private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();


public:

int modo_vista=1;
int tipo_modelo=1;

Objeto3D modelo;
Cubo modelo_cubo;
Tetraedro modelo_tetraedro;


     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void setMode(int m);
	void setType(int t);
	int getMode();
	int getType();

};
#endif
