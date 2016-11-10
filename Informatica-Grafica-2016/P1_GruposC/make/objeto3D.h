#ifndef _Objeto3D
#define _Objeto3D

#include "vertex.h"
#include <vector>

class Objeto3D{

public:
	vector<_vertex3f> vertices;
	vector<_vertex3i> caras;
	_vertex3i *principio_caras;
	vector<_vertex3i> caras_par;
	vector<_vertex3i> caras_impar;
	_vertex3i *carasp;
	_vertex3i *carasi;
	_vertex3f *principio_vertices;
	vector<_vertex3f> color_par;
	vector<_vertex3f> color_impar;
	_vertex3f *colorp;
	_vertex3f *colori;

	int num_triangulos;

public:
	Objeto3D();
	enum DrawMode{ POINTS, LINES, SOLID, CHESS};	
	void draw(DrawMode mode);
};

#endif