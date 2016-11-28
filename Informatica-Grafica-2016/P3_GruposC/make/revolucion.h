#ifndef _REVOLUCION
#define _REVOLUCION

#include "objeto3D.h"

class Revolucion : public Objeto3D{
public:
	Revolucion(vector<_vertex3f> vert_perfil,int pasos,bool tapas, float angulo);
	void RotarPerfil(vector<_vertex3f> vert_perfil,int pasos, bool tapas, float angulo);
	float gradosRadianes(float valor);
	_vertex3f rotateX(_vertex3f p, float alpha);
	_vertex3f rotateY(_vertex3f p, float alpha);
	_vertex3f rotateZ(_vertex3f p, float alpha);
};

#endif