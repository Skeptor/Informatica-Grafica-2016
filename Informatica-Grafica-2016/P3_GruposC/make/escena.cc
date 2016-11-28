#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

	angulo_mesa = 45.0;
	angulo_portatil = 30.0;
	despl_hor = 0;
	despl_vert = 0;
	bajap = 1;
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

	switch(getType()){
		case 1:
			modelo = modelo_cubo;
			switch (modo_vista){
				case 1: //Puntos
					modelo.draw(Objeto3D::POINTS);
					break;
				case 2: //Aristas
					modelo.draw(Objeto3D::LINES);
					break;
				case 3: //Solido
					modelo.draw(Objeto3D::SOLID);
					break;
				case 4: //Ajedrez
					modelo.draw(Objeto3D::CHESS);
					break;
				}
			break;
		case 2:
			modelo = modelo_tetraedro;
			switch (modo_vista){
				case 1: //Puntos
					modelo.draw(Objeto3D::POINTS);
					break;
				case 2: //Aristas
					modelo.draw(Objeto3D::LINES);
					break;
				case 3: //Solido
					modelo.draw(Objeto3D::SOLID);
					break;
				case 4: //Ajedrez
					modelo.draw(Objeto3D::CHESS);
					break;
			} 
			break;
		case 3:		//Beethoven
			modelo = modelo_ply;
			switch (modo_vista){
				case 1: //Puntos
					modelo.draw(Objeto3D::POINTS);
					break;
				case 2: //Aristas
					modelo.draw(Objeto3D::LINES);
					break;
				case 3: //Solido
					modelo.draw(Objeto3D::SOLID);
						break;
				case 4: //Ajedrez
					modelo.draw(Objeto3D::CHESS);
					break;
			} 
			break;
		case 4:{		//Revolucion
			Revolucion modelo_revolucion = Revolucion(modelo_revolucion_ply.vertices,segmentos,tapas,360);
			modelo = modelo_revolucion;
			switch (modo_vista){
				case 1: //Puntos
					modelo.draw(Objeto3D::POINTS);
					break;
				case 2: //Aristas
					modelo.draw(Objeto3D::LINES);
					break;
				case 3: //Solido
					modelo.draw(Objeto3D::SOLID);
					break;
				case 4: //Ajedrez
					modelo.draw(Objeto3D::CHESS);
					break;
			} }
			break;
		case 5:
			switch (modo_vista){
				case 1: //Puntos
					modelo_jerarquico.setTipo(Objeto3D::POINTS);
					portatil.setTipo(Objeto3D::POINTS);					
					modelo_jerarquico.dibujarObjeto(angulo_mesa,angulo_portatil,despl_hor,despl_vert,bajap);
				break;
				case 2: //Aristas
				modelo_jerarquico.setTipo(Objeto3D::LINES);
				portatil.setTipo(Objeto3D::LINES);
					modelo_jerarquico.dibujarObjeto(angulo_mesa,angulo_portatil,despl_hor,despl_vert,bajap);
				break;
				case 3: //Solido
					modelo_jerarquico.setTipo(Objeto3D::SOLID);
					portatil.setTipo(Objeto3D::SOLID);
					modelo_jerarquico.dibujarObjeto(angulo_mesa,angulo_portatil,despl_hor,despl_vert,bajap);
				break;
				case 4: //Ajedrez
					modelo_jerarquico.setTipo(Objeto3D::CHESS);	
					portatil.setTipo(Objeto3D::CHESS);
					modelo_jerarquico.dibujarObjeto(angulo_mesa,angulo_portatil,despl_vert,despl_hor,bajap);
				break;
			} 
			break;
	}
	
}


void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla" << Tecla1<< std::endl;
	switch(Tecla1){
		case ',': girarPortatil();break;
		case '.': girarPortatilI();break;
		case 'k': girarMesa();break;
		case 'l': girarMesaI();break;
		case 'y': despl_vert+=10;break;
		case 'g': despl_hor-=10;break;
		case 'h': despl_vert-=10;break;
		case 'j': despl_hor+=10;break;
		case 'b': bajap +=1.5;break;
	}

	if (toupper(Tecla1)=='Q') return 1;
	else return 0;
	

}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}

void Escena::setMode(int m){
	modo_vista=m;
}
void Escena::setType(int t){
	tipo_modelo=t;
}
int Escena::getMode(){
	return modo_vista;
}
int Escena::getType(){
	return tipo_modelo;
}
bool Escena::cambiaTapas(){
	return tapas= !tapas;
}
void Escena::girarPortatil(){
	angulo_portatil += 10;
}
void Escena::girarMesa(){
	angulo_mesa += 10;
}
void Escena::girarPortatilI(){
	angulo_portatil -= 10;
	}
void Escena::girarMesaI(){
	angulo_mesa -= 10;
}