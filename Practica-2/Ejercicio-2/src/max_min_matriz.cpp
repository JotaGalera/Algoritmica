
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

/////VERSIÓN CON FUNCIÓN AUXILIAR/////////

pair<int ,int> Max_Min_Matriz(int ** M,int inicioi,int inicioj,int n){

  pair<int,int> valor,valorAux,valorAux2;

  if(inicioi == n){
    valor.first = M[inicioi][inicioj];
    valor.second = M[inicioi][inicioj];
  }
  else{

    int mitad = n/2;

    //recursividad
    valor = Max_Min_Matriz(M,inicioi,inicioj,mitad);
    valorAux = Max_Min_Matriz(M,inicioi,inicioj+mitad,mitad);


    if(valorAux.first < valor.first) valor.first = valorAux.first;
    if(valorAux.second > valor.second) valor.second = valorAux.second;
    //recursividad
    valorAux2 = Max_Min_Matriz(M,inicioi+mitad,inicioj,mitad);
    valorAux = Max_Min_Matriz(M,inicioi+mitad,inicioj+mitad,mitad);
    if(valorAux.first < valor.first) valor.first = valorAux.first;
    if(valorAux.second > valor.second) valor.second = valorAux.second;
    if(valorAux2.first < valor.first) valor.first = valorAux2.first;
    if(valorAux2.second > valor.second) valor.second = valorAux2.second;
  }
  return valor;
}

int main(int argc, char* argv[]){

	int size = atoi(argv[1]);
	int** matriz;
  matriz = new int* [size];
  for(int i= 0; i < size ; i++)
    matriz[i] = new int[size];

	pair<int,int> resultado;

	srand(time(0));

	for(int i = 0; i < size ; i++){ //i filas , j columnas

    for(int j= 0; j< size ; j++){
		    matriz[i][j]= (rand() % size);
		    cout <<matriz[i][j]<<" ";
    }
    cout<<endl;
	}

	resultado = Max_Min_Matriz(matriz,0,0 ,size-1);
	cout << " minimo: " << resultado.first <<" maximo: "<< resultado.second << endl;

  return 0;
}

