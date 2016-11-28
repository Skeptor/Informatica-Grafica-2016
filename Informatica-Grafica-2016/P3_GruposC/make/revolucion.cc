#include "revolucion.h"
#include <iostream>


Revolucion::Revolucion(vector<_vertex3f> vert_perfil,int pasos, bool tapas, float angulo){
	RotarPerfil(vert_perfil,pasos,tapas, angulo);
}

float Revolucion::gradosRadianes(float valor){
		return valor * M_PI / 180.0;
	};

_vertex3f Revolucion::rotateX(_vertex3f p, float alpha){
    _vertex3f point;

    point.x = p.x;
    point.y = cos(alpha) * p.y - sin(alpha) * p.z;
    point.z = sin(alpha) * p.y + cos(alpha) * p.z;

    return point;
};

_vertex3f Revolucion::rotateY(_vertex3f p, float alpha){
    _vertex3f point;

    point.x = cos(alpha) * p.x + sin(alpha) * p.z;
    point.y = p.y;
    point.z = -sin(alpha) * p.x + cos(alpha) * p.z;

    return point;
};

_vertex3f Revolucion::rotateZ(_vertex3f p, float alpha){
    _vertex3f point;

    point.x = cos(alpha) * p.x - sin(alpha) * p.y;
    point.y = sin(alpha) * p.x + cos(alpha) * p.y;
    point.z = p.z;

    return point;
};


	/**/
	void Revolucion::RotarPerfil(vector<_vertex3f> vert_perfil, int pasos, bool tapas,float ang){
			
			double angulo;
			vector<_vertex3i> caras_rev;
   			vector<_vertex3f> vertices_rev(vert_perfil);
			ang = gradosRadianes(ang);
			angulo = ang /pasos;
			
			for(int paso = 0; paso < pasos; paso++){

				//Generamos los vertices rotados y los añadimos al vector de vértices
				vector<_vertex3f> sig_perfil(vert_perfil.size());
			   	for (unsigned int s = 0; s < vert_perfil.size(); s++)

			   		sig_perfil[s]= rotateY(vert_perfil[s], angulo);

            	vertices_rev.insert(vertices_rev.end(), sig_perfil.begin(), sig_perfil.end());
				
				//Generamos las caras con los nuevos vértices
				unsigned int perfilI, perfilF;
				perfilI = paso * vert_perfil.size();
				perfilF = perfilI + vert_perfil.size();
				
				for (unsigned int i = perfilI+1, k = perfilF+1; i < perfilF; i++, k++){
      			    caras_rev.push_back(_vertex3i(i-1, k-1, k));
            		caras_rev.push_back(_vertex3i(i-1, k,   i));
        		}

        		vert_perfil = sig_perfil;
			}
	if(tapas){
    	// Generamos la tapa de abajo
	    if (vertices_rev.front().x)	    {
	        _vertex3f puntoCentral(0.0, vertices_rev.front().y, 0.0);
	        vertices_rev.push_back(puntoCentral);

	        for (int paso = 0; paso < pasos; paso++){
	            int perfilactual = paso * vert_perfil.size();
	            int sig_perfil = perfilactual + vert_perfil.size();
 	           caras_rev.push_back(_vertex3i(vertices_rev.size()-1, sig_perfil, perfilactual));

	        }

	    }
	    else{
	    	// x == 0 para el 1er punto. Miramos si además el segundo punto tiene x == 0
            if ( vertices_rev[1].x ) {
               cout << "El modelo tiene un punto de cierre en la parte inferior" << endl;
            } else {
                cout << "El modelo tiene tapa abajo" << endl;
            }
	    }
	    // Generamos la tapa de arriba
	    if (vertices_rev[vert_perfil.size() - 1].x){

	        // Agregamos el punto central, aunque no es necesario porque solo pintamos las caras_rev
	        _vertex3f puntoCentral(0.0, vertices_rev[vert_perfil.size() - 1].y, 0.0);
 	       vertices_rev.push_back(puntoCentral);

 	       for (int paso = 0; paso < pasos; paso++){       
 	           int perfilactual = (paso+1) * vert_perfil.size() -1;
 	           int sig_perfil = perfilactual + vert_perfil.size();
 	           caras_rev.push_back(_vertex3i(vertices_rev.size()-1, perfilactual,sig_perfil));
 	            // Hay que ponerlos al revés que en la otra tapa para que calcule bien las normales
 	       }

   	 	}
   	 	else{
   	 		// x == 0 para el p 1punto. Miramos si además el segundo punto tiene x == 0
            if ( vertices_rev[vert_perfil.size() - 2].x ) {
               cout << "El modelo tiene es un punto de cierre en la parte superior" << endl;
            } else {
                cout << "El modelo tiene tapa arriba" << endl;
            }
   	 	}
   	}

   	 vertices = vertices_rev;

   	 for(int i=0;i<vertices.size();i++){
		 color_par.push_back(_vertex3f(0,0,1));
		 color_impar.push_back(_vertex3f(1,0,0));
	   }
		caras = caras_rev;
	 for(int c=0;c<caras.size();c++){	 	
		if(c%2==0) caras_par.push_back(caras[c]);
		else	   caras_impar.push_back(caras[c]);
	}
	 
	num_triangulos =caras.size();
	principio_caras = &caras[0];
	principio_vertices = &vertices[0];
	carasp = &caras_par[0];
	carasi = &caras_impar[0];
	colorp = &color_par[0];
	colori = &color_impar[0];
	};