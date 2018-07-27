#include "abb.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void ListarAbb(ABB<int> &ab_bus){
  ABB<int>::nodo n;
 //cout<<endl<<"Elementos ordenados: ";
 //cout>>"Error en la entrada de parametros";
 for (n=ab_bus.begin();n!=ab_bus.end();++n){
	  // cout<<*n<<" ";
 }
}

void sintaxis(){
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]){

    // Lectura de parámetros
    if (argc != 3){
      sintaxis();
    }
    int size = atoi(argv[1]);    // Tamaño del vector
    int vmax = atoi(argv[2]);    // Valor máximo
    if (size <=0 || vmax <=0)
      sintaxis();

		//Caso promedio //
    // Generación del vector aleatorio
    int *v = new int[size];       // Reserva de memoria
    srand(time(0));                      // Inicialización del generador de números pseudoaleatorios
    for (int i = 0; i < size; i++){      // Recorrer vector
		//caso promedio y mejor caso coinciden
		  v[i] = rand() % vmax;    // Generar aleatorio [0,vmax]
		//peor caso, en el cual nos dan un vector ordenado tanto de mayor a menor como de menor a mayor.
	 	//	v[i] = size - i;
		}


    clock_t tini;    // Anotamos el tiempo de inicio
    tini=clock();
    //Declaración del abb
    ABB<int>ab_bus;
    //Rellenamos el abb
    for (int i=0;i<size;i++){
	     ab_bus.Insertar(v[i]);
     }
    //Usamos el metodo listar
    ListarAbb(ab_bus);

    clock_t tfin;    // Anotamos el tiempo de finalización
    tfin = clock();

    // Mostramos resultados
    cout << size << "\t" << (tfin - tini) / (double) CLOCKS_PER_SEC << endl;

}
