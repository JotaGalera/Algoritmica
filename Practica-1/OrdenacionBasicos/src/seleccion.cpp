#include <iostream>
#include <algorithm> //std::swap
#include <chrono>
#include <cstdlib>	//numeros pseudoaleatorios
using namespace std;
using namespace std::chrono;

void seleccion(int *a,int n){
	for (int i=0; i<n-1; i++){
		int pmin= i;
  	for(int j=i+1; j<n ; j++){
    	if(a[pmin]>a[j])
      	pmin=j;
  	}
  std::swap(a[i],a[pmin]);
	}
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "  VMAX: Valor máximo (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios en [0,VMAX[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
    // Lectura de parámetros
    if (argc != 3)
      sintaxis();
    int size = atoi(argv[1]);     // Tamaño del vector
    int vmax = atoi(argv[2]);    // Valor máximo
    if (size <=0 || vmax <=0)
      sintaxis();

		//Caso promedio //
    // Generación del vector aleatorio
    int *v = new int[size];       // Reserva de memoria
    srand(time(0));            // Inicialización del generador de números pseudoaleatorios
    for (int i = 0; i < size; i++){  // Recorrer vector
		//caso promedio
		//  v[i] = rand() % vmax;    // Generar aleatorio [0,vmax[
		//mejor caso
		//	v[i] = i;
		//peor caso
	 		v[i] = size - i;
		}

    clock_t tini;    // Anotamos el tiempo de inicio
    tini=clock();

    seleccion(v, size);

    clock_t tfin;    // Anotamos el tiempo de finalización
    tfin = clock();

    // Mostramos resultados
    cout << size << "\t" << (tfin - tini) / (double) CLOCKS_PER_SEC << endl;

    delete [] v;     // Liberamos memoria dinámica
}
