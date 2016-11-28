//Clase genérica Objeto 3D

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "objeto3D.h"
#include "escena.h"
#include "vertex.h"


	Objeto3D::Objeto3D(){};
	void Objeto3D::draw(DrawMode mode){
		GLenum modo;
		switch(mode){
			case Objeto3D::POINTS:
				modo = GL_POINT;
				break;
			case Objeto3D::LINES:
				modo = GL_LINE;
				break;
			default:
				modo = GL_FILL;
				break;
		}

		glPointSize(3);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_COLOR_ARRAY);
		//glEnable(GL_CULL_FACE);
		glVertexPointer(3, GL_FLOAT, 0, principio_vertices);
		glPolygonMode(GL_FRONT_AND_BACK,modo);

		if(mode==CHESS){
			glColorPointer(3,GL_FLOAT,0,colorp);
			glDrawElements(GL_TRIANGLES,(3*num_triangulos)/2,GL_UNSIGNED_INT,carasp);
			glColorPointer(3,GL_FLOAT,0,colori);
			glDrawElements(GL_TRIANGLES,(3*num_triangulos)/2,GL_UNSIGNED_INT,carasi);
		}
		else{
			glColorPointer(3,GL_FLOAT,0,colorp);
			glDrawElements(GL_TRIANGLES,3*num_triangulos,GL_UNSIGNED_INT,principio_caras);	
		}
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);

		


	};

/**/