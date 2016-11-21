//Clase Cubo

#include "cubo.h"

	Cubo::Cubo(){
		vertices.push_back(_vertex3f(50.0f,50.0f,50.0f));				//0
		vertices.push_back(_vertex3f(50.0f,50.0f,-50.0f));				//1
		vertices.push_back(_vertex3f(50.0f,-50.0f,50.0f));				//2
		vertices.push_back(_vertex3f(-50.0f,50.0f,50.0f));				//3
		vertices.push_back(_vertex3f(50.0f,-50.0f,-50.0f));			//4
		vertices.push_back(_vertex3f(-50.0f,50.0f,-50.0f));			//5
		vertices.push_back(_vertex3f(-50.0f,-50.0f,50.0f));			//6
		vertices.push_back(_vertex3f(-50.0f,-50.0f,-50.0f));			//7

		caras.push_back(_vertex3i(0,3,6));			//Primera cara
		caras.push_back(_vertex3i(0,6,2));			//Primera cara
		caras.push_back(_vertex3i(0,1,4));			//Segunda cara
		caras.push_back(_vertex3i(0,2,4));			//Segunda cara
		caras.push_back(_vertex3i(0,3,1));			//Tercera cara
		caras.push_back(_vertex3i(1,5,3));			//Tercera cara
		caras.push_back(_vertex3i(1,5,7));			//Cuarta cara
		caras.push_back(_vertex3i(1,7,4));			//Cuarta cara
		caras.push_back(_vertex3i(3,7,5));			//Quinta cara
		caras.push_back(_vertex3i(3,6,7));			//Quinta cara
		caras.push_back(_vertex3i(2,7,6));			//Sexta cara
		caras.push_back(_vertex3i(2,4,7));			//Sexta cara

		caras_par.push_back(_vertex3i(0,3,6));			//Primera cara
		caras_impar.push_back(_vertex3i(0,6,2));			//Primera cara
		caras_par.push_back(_vertex3i(0,1,4));			//Segunda cara
		caras_impar.push_back(_vertex3i(0,2,4));			//Segunda cara
		caras_par.push_back(_vertex3i(0,3,1));			//Tercera cara
		caras_impar.push_back(_vertex3i(1,5,3));			//Tercera cara
		caras_par.push_back(_vertex3i(1,5,7));			//Cuarta cara
		caras_impar.push_back(_vertex3i(1,7,4));			//Cuarta cara
		caras_par.push_back(_vertex3i(3,7,5));			//Quinta cara
		caras_impar.push_back(_vertex3i(3,6,7));			//Quinta cara
		caras_par.push_back(_vertex3i(2,7,6));			//Sexta cara
		caras_impar.push_back(_vertex3i(2,4,7));			//Sexta cara

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

		num_triangulos = 12;
	};
		
	
