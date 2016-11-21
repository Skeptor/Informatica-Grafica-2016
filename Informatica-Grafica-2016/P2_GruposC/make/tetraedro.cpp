#include "tetraedro.h"

	Tetraedro::Tetraedro(){
		vertices.push_back(_vertex3f(50.0f,-50.0f,50.0f));				//0
		vertices.push_back(_vertex3f(50.0f,-50.0f,-50.0f));			//1
		vertices.push_back(_vertex3f(-50.0f,-50.0f,-50.0f));			//2
		vertices.push_back(_vertex3f(-50.0f,-50.0f,50.0f));			//3
		vertices.push_back(_vertex3f(0,50.0f,0));					//Pico

		caras.push_back(_vertex3i(0,1,2));			
		caras.push_back(_vertex3i(2,3,1));			
		caras.push_back(_vertex3i(0,1,4));			
		caras.push_back(_vertex3i(1,2,4));		
		caras.push_back(_vertex3i(2,3,4));			
		caras.push_back(_vertex3i(3,0,4));		

		caras_par.push_back(_vertex3i(0,1,2));			
		caras_impar.push_back(_vertex3i(2,3,1));			
		caras_par.push_back(_vertex3i(0,1,4));			
		caras_impar.push_back(_vertex3i(1,2,4));		
		caras_par.push_back(_vertex3i(2,3,4));			
		caras_impar.push_back(_vertex3i(3,0,4));		

		principio_caras = &caras[0];
		principio_vertices = &vertices[0];	
		carasp = &caras_par[0];
		carasi = &caras_impar[0];

		for(int i=0; i < vertices.size(); i++){
				color_par.push_back(_vertex3f(0,0,1));
				color_impar.push_back(_vertex3f(1,0,0));
		}
		colorp = &color_par[0];
		colori = &color_impar[0];

		num_triangulos = 6;
	};

	
