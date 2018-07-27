//Estudiaremos el caso de emparejamiento de alumnos utilizando un algoritmo voráz

#include <stdlib.h>
#include <iostream>
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


//Algoritmo Voraz
//@param m matriz que contiene los alumnos y las calificaciones
//@param s vector de pair enteros, en él almacenaremos los emparejamientos
void algoritmo( vector<vector<int> > m, vector<pair<int,int> > &s, int n_p){
  set <int>indice;
  int indiceprueba = 0;
  pair<int,int> pareja;
  for(int i = 0 ; i < n_p ; i++){
    if(indice.count(i)==0){
      int menor = std::numeric_limits<int>::max();
        for ( int j = 0; j < n_p ; j++){
          if((menor > m[i][j]) and (indice.count(j)==0)){
            menor = m[i][j];
            indiceprueba = j;
          }
        }
        cout<<"pareja"<<i<<"pareja"<<indiceprueba<<endl;
        indice.insert(indiceprueba);
        pareja.first = i;
        pareja.second = indiceprueba;
        s.push_back(pareja);
    }
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

    for(int i = 0 ; i < n_alumnos ; i++){
        for ( int j = 0; j < n_cuestiones ; j++)
            cout << matriz_stl[i][j] << ' ';
        cout<< endl;
    }
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

    //Mostramos la matriz de discrepancia

    //LLamaremos a nuestro algoritmo Voraz para que nos encuentre las
    //parejas de nuestra matriz, para almacenar las parejas utilizaremos
    //un vector de pair que contendrán las parejas seleccionadas
    vector <pair<int,int> > solucion;
    algoritmo(matriz_discrepancia_stl, solucion, n_alumnos);
        for ( int j = 0; j < solucion.size() ; j++)
            cout << solucion[j].first << ' ' << solucion[j].second<< endl;


}