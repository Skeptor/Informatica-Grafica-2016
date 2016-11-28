#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "objeto3D.h"
#include "cubo.h"
#include "tetraedro.h"
#include "ply.h"
#include "file_ply_stl.h"
#include "revolucion.h"
#include "jerarquico.h"
#include "portatil.h"

class Escena {
private:
// tamaño de los ejes
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

//Transformación de cámara
	void change_projection();
	void change_observer();


public:

int modo_vista=4;
int tipo_modelo=5;
int segmentos = 20;
bool tapas = true;
float angulo_mesa;
float angulo_portatil;
float despl_hor;
float despl_vert;
int bajap;
//int angulo_revolucion=360;

Objeto3D modelo;
Cubo modelo_cubo;
Tetraedro modelo_tetraedro;
FiguraPLY modelo_ply = FiguraPLY("PLY/beethoven.ply");
FiguraPLY modelo_revolucion_ply = FiguraPLY("PLY/cilindro.ply");
Jerarquico modelo_jerarquico;
Portatil portatil;


     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void setMode(int m);
	void setType(int t);
	int getMode();
	int getType();
	bool cambiaTapas();
	void girarPortatil();
	void girarPortatilI();
	void girarMesa();
	void girarMesaI();
};
#endif
