#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

void Ordenacion(vector<int> &v){
  sort(v.rbegin(),v.rend());

}

int Seleccion(vector<int> v){

  return v.at(0);
}

void Quitar(vector<int> &v){
  v.erase(v.begin());
}

bool Factible(int a, vector<int> &sub,int m){
  int suma=0;
  for(int i = 0; i< sub.size(); i++)
    suma += sub[i];
  if( (suma+a) <= m )
    return true;
  else
    return false;
}

void Incluir(int a, vector<int> &aux){
  aux.push_back(a);
}

bool Solucion(vector <int> v,int a){
  int suma = 0;
  for (int i=0 ; i<v.size(); i++)
    suma += v[i];
  if( suma < a)
    return false;
  else if( suma == a)
    return true;
  else if( suma > a)
    return true;
}

void Greedy(vector <int> S, vector <int> &aux, int m){
  int numaux=0;

  while(!S.empty() && !Solucion(aux,m)){
    numaux = Seleccion(S);
    Quitar(S);
    if( Factible(numaux,aux,m) )
      Incluir(numaux,aux);
  }

}

int main(int argc, char *argv[]){

  if(argc < 2){
    cerr << "Error: Se necesita fichero de datos"<<endl;
    exit(-1);
  }
  //Params:
  ifstream inFile;
  int value;
  int M = atoi(argv[2]);
  vector<int> S;
  vector<int> subcon;

  //Lectura de fichero
  inFile.open(argv[1]);

  while(inFile >> value){
    S.push_back(value);
  }

  cout << "Size: " << S.size() <<endl;

  for(int i=0 ; i< S.size() ; i++){
    cout<<S[i]<<"-";
  }
  cout<<endl;
  //Ordenacion del vector
  Ordenacion(S);

  for(int i=0 ; i< S.size() ; i++){
    cout<<S[i]<<"-";
  }

  //Greedy
  Greedy(S,subcon,M);

  //Vector solucion y suma:
  int auxsum = 0;
  cout<<"Subconjunto elegido:"<<endl;
  for (int i= 0; i< subcon.size(); i++){
    cout<<subcon[i]<<"-";
    auxsum += subcon[i];
  }
  cout<<endl;
  cout<<"La suma que obtenemos es:"<<auxsum<<endl;
  inFile.close();
  return 0;

}
