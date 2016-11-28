#include "ply.h"
#include "file_ply_stl.h"
#include <iostream>
#include <vector>
using namespace std;

FiguraPLY::FiguraPLY(char * file){
	vector<float> vertices_ply;
	vector<int> caras_ply;
	_file_ply archivo_ply;
	archivo_ply.open(file);
	archivo_ply.read(vertices_ply,caras_ply);
	for(int v=0; v < vertices_ply.size();v+=3){
		_vertex3f vert;
		vert.x = 15*vertices_ply[v];
		vert.y = 15*vertices_ply[v+1];
		vert.z = 15*vertices_ply[v+2];

		vertices.push_back(vert);
		 color_par.push_back(_vertex3f(0,0,1));
		 color_impar.push_back(_vertex3f(1,0,0));
	}
	for(int c=0; c < caras_ply.size();c+=3){
		_vertex3i car;
		car._0 = caras_ply[c];
		car._1 = caras_ply[c+1];
		car._2 = caras_ply[c+2];

		caras.push_back(car);
		if(c%2==0) caras_par.push_back(car);
		else	   caras_impar.push_back(car);
	}
	principio_caras = &caras[0];
		principio_vertices = &vertices[0];
		carasp = &caras_par[0];
		carasi = &caras_impar[0];
		colorp = &color_par[0];
		colori = &color_impar[0];
	num_triangulos = caras.size();

};