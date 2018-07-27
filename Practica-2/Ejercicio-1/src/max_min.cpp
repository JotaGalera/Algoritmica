
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;

/////VERSIÓN CON FUNCIÓN AUXILIAR/////////

pair<int,int> Max_Min2(const vector<int> v, int ini, int fin){
	pair<int,int> max_min;
	
	if(ini == fin){ //CASO BASE
		max_min.first = v[ini];
		max_min.second = v[ini];
		
	}
	else{
		pair<int,int> a,b;

		int mitad= (ini+fin)/2;
		a=Max_Min2(v,ini,mitad);  	//DIVISION DEL PROBLEMA 
		b=Max_Min2(v,mitad+1,fin);  //RECURSIVIDAD
		
		max_min.first=(a.first < b.first)? a.first : b.first;     //MEZCLA DEL PROBLEMA
		max_min.second=(a.second > b.second)? a.second : b.second;//
	}
	
	return max_min;
}


pair<int,int> Maximo_Min(const vector<int>v, int n){
		
	int ini=0;
	int fin=n-1;
	pair<int,int> valor;
	valor= Max_Min2(v,ini,fin);
	
	return valor;
}

int main(int argc, char* argv[]){

	int size = atoi(argv[1]);
	vector<int> v;
	pair<int,int> resultado;
	srand(time(0));
	
	for(int i = 0; i < size ; i++){
		v.push_back((rand() % size)+1);
		cout <<"Elemento del vector" <<i<<": "<<v[i]<<endl; 	
	}
	
	resultado = Maximo_Min(v, size);
	cout << " minimo: " << resultado.first <<" maximo: "<< resultado.second << endl;

}
