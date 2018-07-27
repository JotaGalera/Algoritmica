
#include <iostream>
#include <cstdlib>
#include <utility>
#include <vector>

using namespace std;


int Particion(int * &v, int primero, int ultimo, int elem_pivote){

	int intercambio;
	int aux_pos_pivote=primero;
	int pos_pivote=primero;
	int valor_pivote;

	for(int i = primero ; i < ultimo ; i++){
		if(v[i] == elem_pivote);
			aux_pos_pivote = i;
	}

  valor_pivote= v[aux_pos_pivote];

	//
	for(int i = primero ; i < ultimo ; i++){
		//PARA LOS QUE SON MENORES QUE EL PIVOTE
		if(v[i] <= valor_pivote){

			intercambio= v[i];
			v[i]= v[pos_pivote];
			v[pos_pivote]= intercambio;
			pos_pivote++;
		}


	}

	return pos_pivote;
}






void Ordenacion(int * &zapato, int * &pie, int primero, int ultimo, int pivote_pie_random){
	if(primero == ultimo){

	}
	else{
		int pos_pivote_pie= pivote_pie_random;

		int pos_pivote_zapato = Particion(zapato,primero,ultimo, pie[pivote_pie_random]);
		pos_pivote_pie = Particion(pie,primero,ultimo,zapato[pos_pivote_zapato] );


		if(pos_pivote_pie > 0){
			Ordenacion(zapato,pie,primero,pos_pivote_pie-1, pie[pos_pivote_pie]);
			Ordenacion(zapato,pie,pos_pivote_pie,ultimo, pie[pos_pivote_pie]);
		}else if(pos_pivote_pie <= 0){
			Ordenacion(zapato,pie,primero,pos_pivote_pie, pie[pos_pivote_pie]);
			Ordenacion(zapato,pie,pos_pivote_pie+1,ultimo, pie[pos_pivote_pie]);
		}

	}
}


//Función para devolver una posición libre del vector
int pos_libre(vector<bool> v,int size,int &posicion){
	bool lleno= true;
	int i;
	for(i = 0; i< size; i++){
		if(v[i] == false){
			lleno = false;
			cout<<"Posicion:"<<i<< "vacía"<<endl;
			posicion=i;
			break;
		}
	}
}


int main(int argc, char* argv[]){

	int size = atoi(argv[1]);
	int * tam_pie;
	int * zapatos;
	tam_pie = new int[size];
	zapatos = new int[size];
  int index = 0;

	srand(time(0));
	for(int i = 0; i < size ; i++){
	    tam_pie[i]= (rand()%size );
			cout<<"valores"<<tam_pie[i]<<endl;
  }
  const bool initial_value = false; // All elements will be set to this value
  vector<bool> free_pos(size, initial_value); //free positions vector

	for(int i=0;i<size;i++){
		index = (rand()%size);//vector de tam_pie
		if(!free_pos[index]){
			zapatos[index] = tam_pie[i];
			free_pos[index] = true;
		}else{
			pos_libre(free_pos,free_pos.size(),index);
			zapatos[index] = tam_pie[i];
			free_pos[index] =true;
			}
		}

cout << "pie: ";
  for (int i = 0; i < size; i++) {
    cout << tam_pie[i] << "-";
  }
	cout<<endl;
  cout << "shoes";
  for (int i = 0; i < size; i++) {
    cout << zapatos[i] << "-";
  }
cout<<endl;
	int pivote_pie_random = tam_pie[random()% size];
	Ordenacion(zapatos,tam_pie,0,size,pivote_pie_random);

cout << "pie ordenado: ";
  for (int i = 0; i < size; i++) {
    cout << tam_pie[i] << "-";
  }
  cout << "zapatos ordenado";
  for (int i = 0; i < size; i++) {
    cout << zapatos[i];
  }

  return 0;
}
