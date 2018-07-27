#include "imagen.h"
#include <fstream>



int formas(const Imagen & im, const Imagen & forma, int iniF, int finF, int iniC, int finC){
	int cont = 0;

	if (finF - iniF == forma.fils() && finC - iniC == forma.cols()) {
		if (EstaForma(im, iniF, iniC, forma)) cont = 1;
	}
	else{
		int cont1, cont2, cont3, cont4;
		int mitadF = (iniF + finF) / 2;
		int mitadC = (iniC + finC) / 2;

		cont1 = formas(im, forma, iniF, mitadF, iniC, mitadC);
		cont2 = formas(im, forma, iniF, mitadF, mitadC + 1, finC);
		cont3 = formas(im, forma, mitadF + 1, finF, iniC, mitadC);
		cont4 = formas(im, forma, mitadF + 1, finF, mitadC + 1, finC);

		cont = cont1 + cont2 + cont3 + cont4;
		for (int i = 0; i < count; i++) {
			for (int i = mitadF - forma.fils() - 1; i <= mtiadF + 1; i ++){
				Imagen.copia(img)
				copia.PutImagen(i, j, forma);
				if(im == copia) cont++;
			}
		}
	}
	return cont;

}

int main(int argc, char * argv[]){
  if (argc!=3){
      cout<<"Los parametros son: ";
     cout<<"1.-Dime el nombre de una imagen"<<endl;
     cout<<"2.-Dime el nombre de una forma"<<endl;
     return 0;
  }

  Imagen I,forma;
  I.LeerImagen(argv[1]);
  forma.LeerImagen(argv[2]);

  cout "Forma => " << formas(I, forma, )
  //Vuestro codigo para implementar la funcion que busca la forma en I



}
