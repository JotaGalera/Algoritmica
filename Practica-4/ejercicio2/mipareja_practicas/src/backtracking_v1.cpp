#include <iostream>
#include "Apermutacion.h"
#include <string> 
#include <stdlib.h>
#include <vector>
#include <set>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;


//Matriz de discrepancias calculada como:
// Sumatoria(k=1,n_cuestiones)[M(i,k) - M(j,k)] Para todo i != j
// D(i,j)=infinito si i = j
void matrizDiscrepancia(vector<vector<int> > m, vector<vector<int> > &m_d, int n_p, int n_c){
    int valor = 0;
    for(int i = 0; i<n_p ; i++){
        for(int j = 0; j<n_p ; j++){
            for(int k = 0; k<n_c ; k++){
                valor += abs(m[i][k] - m[j][k]);
            }
            if(i==j){
              m_d[i][j]=std::numeric_limits<int>::max();
            }
            else {
              m_d[i][j] = valor;
            }
            valor = 0;
        }
    }
    cout<< endl;
    cout<< endl;
    for(int i = 0 ; i < n_p ; i++){
        for ( int j = 0; j < n_p ; j++)
            cout << m_d[i][j] << ' ';
        cout<< endl;
    }

}

int afinidad_sum(const Apermutacion & P,  const vector<vector<int> > & matriz_stl){
  int suma = 0;
  int i = 0;
  Apermutacion::const_iterator it;

  for (it = P.begin(); it != P.end(); ++it) {
      if (i != *it - 1)
          suma += matriz_stl[i][*it - 1];
      ++i;
  }
  return suma;  
}

 int backtracking(int n, Apermutacion &ab, const vector<vector<int> > &matriz_stl){
   Apermutacion P(n);
   //P.GeneraSiguienteAnchura();
   bool seguir =  true;
   int afinidad_actual = 0;
   int best_afinidad = numeric_limits<int>::max();
   int nodos_recorridos = 0;

   while(seguir){
    nodos_recorridos++;
    afinidad_actual = afinidad_sum(P, matriz_stl);
    
    if (P.GetLevel() == n-1) {
      if(afinidad_actual < best_afinidad){
        best_afinidad = afinidad_actual;
        ab = P;
        seguir = P.Backtracking();
      }else{
        seguir = P.GeneraSiguienteProfundidad();
      } 
    }else seguir = P.GeneraSiguienteProfundidad();
   }
   int total = P.NumeroSecuenciasPosibles();
   cout << "Total Recorridos " << nodos_recorridos << endl;
   cout << "Total en Porcentaje " << (nodos_recorridos/total) * 100;
   return best_afinidad;
 }

void solucion(const Apermutacion &P) {
    int i = 1;
    Apermutacion::const_iterator it;
    for (it = P.begin(); it != P.end(); ++it) {
        cout << "pareja: " << i << " => pareja: " << *it << endl;
        i++;
    }
}

int main(int argc, char *argv[]){

    if(argc < 2){
        cout << "Error: Se necesita fichero de datos"<<endl;
        exit(-1);
    }

    //Parametro archivo:
    //·La primera línea es un comentario.
    //·La segunda línea indica el nº de alumnos y el nº de cuestiones
    //·El resto de líneas son valores en el rango [0-10]
    ifstream inFile;
    string line;
    int n_alumnos=0;
    int n_cuestiones=0;
    int value=0;
    vector <int> datosProblema; //1º posicion nº de alumnos
                                 //2º posicion nº de cuestiones
    vector<vector<int> > matriz_stl;

    //Lectura de fichero
    inFile.open(argv[1], ios::in);
    getline(inFile,line);
    inFile >> n_alumnos;
    inFile >> n_cuestiones;
    cout<<"Nº de personas"<<n_alumnos<<endl;
    cout <<"Nº de cuestiones:"<<n_cuestiones<<endl;
    for (int i = 0; i < n_alumnos; i++){
      vector<int> fila;
        for (int j = 0; j < n_cuestiones; j++){
            inFile >> value;
            fila.push_back(value);
            cout<< fila[j] <<' ';
        }
        matriz_stl.push_back(fila);
        cout<<endl;
    }
    cout<<"final"<<endl;

    /*for(int i = 0 ; i < n_alumnos ; i++){
        for ( int j = 0; j < n_cuestiones ; j++)
            cout << matriz_stl[i][j] << ' ';
        cout<< endl;
    }*/
    //Cerramos el archivo, hemos terminado con él
    inFile.close();

   //Calcularemos la matriz de discrepancia
    vector<vector<int> > matriz_discrepancia_stl;
    for (int i = 0; i < n_alumnos; i++){
      vector<int> fila;
        for (int j = 0; j < n_alumnos; j++){
            fila.push_back(0);
        }
        matriz_discrepancia_stl.push_back(fila);
    }

    matrizDiscrepancia(matriz_stl , matriz_discrepancia_stl, n_alumnos, n_cuestiones);
    Apermutacion P(matriz_discrepancia_stl.size());

    int discrepancia_backtracking =  backtracking(matriz_discrepancia_stl.size(), P, matriz_discrepancia_stl );
    cout << "\nDiscrepancia con Backtraking: " << discrepancia_backtracking << endl << endl;
    solucion(P);

}