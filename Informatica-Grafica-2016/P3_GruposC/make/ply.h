#ifndef _PLY
#define _PLY
#include "objeto3D.h"

class FiguraPLY : public Objeto3D{
public:
	FiguraPLY();
	FiguraPLY(char * file);
};

#endif