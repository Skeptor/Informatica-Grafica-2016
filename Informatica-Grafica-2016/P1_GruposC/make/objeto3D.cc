//Clase genérica Objeto 3D

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
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

		
			/*for(int i=0; i < caras.size(); i++){
				if(mode ==CHESS && i%2 == 0)
					glColor3f(0,0,1);
				else
					glColor3f(1,0,0);*/

				/*vertice1 = caras[i]._0;
				vertice2 = caras[i]._1;
				vertice3 = caras[i]._2;

				glVertex3f(vertices[vertice1].x, vertices[vertice1].y, vertices[vertice1].z);
				glVertex3f(vertices[vertice2].x, vertices[vertice2].y, vertices[vertice2].z);
				glVertex3f(vertices[vertice3].x, vertices[vertice3].y, vertices[vertice3].z);
			}*/


	};


	