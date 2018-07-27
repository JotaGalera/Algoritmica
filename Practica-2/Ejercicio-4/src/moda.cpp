#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sys/time.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * La ecuacion de recurrencia:
 *
 *  		   |   O (1)          si n =1  (ini == fin)
 *  T(n)=> |
 * 			   |   T(n/2) + O(n)  en otro caso
*/

//############################MODA NOT SORTED #########################
int Frecuencia(std::vector<int> &v, int p, int ini, int fin){
	int i, suma;
	if (ini > fin) return 0;
	suma = 0;
	for (i = ini; i<= fin; i++)
		if(v[i] == p)
			suma++;

	return suma;
}

//La complejidad de la función Frecuencia es O(n), lo que hace que la
//complejidad del algoritmo que lo llama para calcular la moda sea de orden O(n²)
int moda (std::vector<int> & v, int ini, int fin ){
	int i, frec, maxFrec, moda;

	if (ini == fin) return v[ini]; //CASO BASE
		moda = v[ini];
		maxFrec = Frecuencia(v, v[ini], ini, fin);
		for (i = ini + 1; i<=fin; i++) {
			frec = Frecuencia (v, v[i], i, fin);
			if (frec > maxFrec) {
				maxFrec = frec;
				moda = v[i];
			}
		}
		return moda;
}

//############################MODA SORTED #############################

//este caso es si el vector esta ordenado y recorre una sola vez O(n)
//Sin embargo, como se ordena primero entonces la complejidad del
//algoritmo es de orden O(nlogn)
int moda2 (std::vector<int> & v, int ini, int fin ){
	int i, moda, n;

	i = ini + 1;
	n = 1;
	moda = v[ini];

	while (i <= fin) {
		if (v[i-n] == v[i] ) {
			n++;
			moda = v[i];
		}
		i++;
	}
	return moda;
}
 void syntax(){
	 cerr << "Syntax:" << endl;
	 cerr << " Size: Vector size (>0)" << endl;
	 cerr << " Vmax: Max value (>0)" << endl;
	 cerr << "Generates vector with random values between [0,Vmax[" << endl;
	 exit(EXIT_FAILURE);
 }

//Seria para la moda 3 con conjunto heter y homog pero no se ha implementado
int Pivote(std::vector<int> &v, int primero, int ultimo){
	int intercambio;
	int pos_pivote = primero; //0
	int valor_pivote = v[primero];

	for (int i = 0; i < ultimo; i++)
		cout << "-" <<  v[i];
	for(int i = primero+1 ; i <= ultimo ; i++){
		if(v[i] < valor_pivote){
			pos_pivote++;
			intercambio= v[i];
			v[i]= v[pos_pivote];
			v[pos_pivote]= intercambio;
		}
	}

	intercambio = v[primero];
	v[primero] = v[pos_pivote];
	v[pos_pivote] = intercambio;

	return pos_pivote;
}

int main(int argc, char * argv[]){
	 if (argc != 3)
		 syntax();

	 int size = atoi(argv[1]);
	 int vmax = atoi(argv[2]);
	 //int * V = new int[size];
	 std::vector<int> V;
	 if (size <=0 || vmax<=0)
		 syntax();

	for (int i = 0; i < size; i++)
		 V.push_back(random() % vmax);

	cout << "---- Vector Not Sorted---" << endl;
	for (int i = 0; i < size; i++)
		cout << "-" <<  V[i];
	cout << "\nMODE =>" <<  moda(V, 0, size);

	std::sort (V.begin(), V.end());
	cout << "\n\n---- Vector Sorted---" << endl;
	for (int i = 0; i < size; i++)
		cout << "-" <<  V[i];

	cout << "\nMODE =>" <<  moda2(V, 0, size);

	return 0;
}
