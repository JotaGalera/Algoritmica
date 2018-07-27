#include "apo.h"
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

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

		APO<int>ap_int;
		int size = atoi(argv[1]);

		int * V = new int[size];
		for (int i = 0; i < size; i++) {
			V[i]= size - i;
		}

		high_resolution_clock::time_point start,end;
		duration<double> tiempo_transcurrido;

		start = high_resolution_clock::now();
		for (int i = 0; i < size; i++)
			ap_int.insertar(V[i]);
    for (int i = 0; i < size; i++)
			ap_int.borrar_minimo();
		end = high_resolution_clock::now();

		tiempo_transcurrido = duration_cast<duration<double> >(end - start);
		cout << size << "\t" <<tiempo_transcurrido.count() << endl;

		delete [] V;
}
