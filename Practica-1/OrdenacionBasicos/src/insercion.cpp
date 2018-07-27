#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <sys/time.h>
#include <stdio.h>

using namespace std;
using namespace std::chrono;

/*
 @brief Ordena un vector por el método de la inserción.
 Cambia el orden de los elementos de V de forma que los dispone
 en sentido creciente de menor a mayor.
 @param V: vector con size elementos.
 @param size: número de elementos. (size > 0 ).
*/
void insercion(int * V, int size){
  int swap,j,i;
  for (i = 0 + 1; i < size; i++) {
    j = i;
    while ((V[j] < V[j-1]) && (j > 0)) {
      swap = V[j];
      V[j] = V[j-1];
      V[j-1] = swap;
      j--;
    };
  };
}

void syntax(){
  cerr << "Syntax:" << endl;
  cerr << " Size: Vector size (>0)" << endl;
  cerr << " Vmax: Max value (>0)" << endl;
  cerr << "Generates vector with random values between [0,Vmax[" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){
  if (argc != 3)
    syntax();

  int size = atoi(argv[1]);
  int vmax = atoi(argv[2]);
  int * V = new int[size];

  if (size <=0 || vmax<=0)
    syntax();

  srandom(time(0));

  for (int i = 0; i < size; i++)
    //V[i] = random() % vmax; //Average Case Scenario
    //V[i] = i; //Best Case Scenario
    V[i] = size - i; //Worst Case Scenario

  high_resolution_clock::time_point start,end;
  duration<double> tiempo_transcurrido;

  start = high_resolution_clock::now();
  insercion(V, size);
  end = high_resolution_clock::now();

  tiempo_transcurrido = duration_cast<duration<double> >(end - start);
  cout << size << "\t" <<tiempo_transcurrido.count() << endl;

  delete [] V;

  return 0;
}
