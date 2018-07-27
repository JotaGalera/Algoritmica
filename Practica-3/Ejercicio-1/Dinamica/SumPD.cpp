#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

int Max (int n1, int n2) {
    if (n1 >= n2) return n1;
    else return n2;
}
int Min (int n1, int n2){
    if(n1 <= n2) return n1;
    else return n2;
}

int SumToNumber(vector<int> & S, int M){
    vector<int> R;
    R.push_back(0);
    for (int i=0; i<=S.size(); i++){
        R.push_back(S[i]);
    }

    //rellenar matriz
    vector < vector <int> > matriz(S.size()+1);

    for (int i=0; i<=S.size(); i++) {
        matriz.at(i).resize(M+1);
        matriz.at(i).at(0) = 0;
    }

    for (int j=0; j <= M; j++)
        matriz.at(0).at(j) = 0;

    for (unsigned i=0; i<matriz.size(); i++) {
        cout << R[i] << '|' << "\t ";
        for (unsigned j=0; j<matriz[i].size(); j++)
            cout << matriz.at(i).at(j) << '\t';
        cout << endl;
    }

    cout << "-------------------------------------------------------------------------\n";
    for (int i = 0; i < S.size(); i++){
        cout << S[i] << "-";
    }
    cout << endl;
    int suma = M;
    int mp =0;
    cout << "--------------------------ALG---------------------------------------------\n"; 
    for (int i=1; i<=S.size(); i++) {
        for (int j=1; j<=M; j++) {
            if (S[i-1] > j){
              //matriz.at(i).at(j)= std::numeric_limits<int>::min();  
              cout << "Comparacion " << S[i-1] << "-" << j << endl;                
              matriz.at(i).at(j)= matriz.at(i-1).at(j);
            }
            else {
                if (S[i-1] < j){
                    cout << "Max de " << matriz.at(i-1).at(j) << "-" << j << endl;       
                    matriz.at(i).at(j) = Max(matriz.at(i-1).at(j), S[i-1]+matriz.at(i-1).at(j-S[i-1]));     
                }
                else{      
                    matriz.at(i).at(j) = S[i-1] ;
                }              
            }
        }
    }

    cout << "-------------------------------------------------------------------------\n";
    for (unsigned i=0; i<matriz.size(); i++) {
        cout << R[i] << '|' << "\t ";
        for (unsigned j=0; j<matriz[i].size(); j++)
            cout << matriz.at(i).at(j) << '\t';
        cout << endl;
    }

    cout << "----------------------------SOL------------------------------------------\n";
    vector<unsigned> sol(matriz.size());
    unsigned i = 0;
    unsigned j = matriz[0].size() -1 ;

    for (int i=matriz.size()-1; i>0; i--) {
        cout << matriz.at(i).at(j) << '\t' << matriz.at(i).at(j) << endl;
        if (matriz.at(i).at(j) == matriz.at(i-1).at(j)){
            sol.at(i-1)= S[i];
            cout << "Equal" << endl;
        }
        else{
            int n = M;
            for (int i=matriz.size()-1; i>0; i--) {
                if (matriz.at(i).at(j) == matriz.at(n).at(j)){
                    sol.at(i-1) = S[i];
                    n--;
                }   
            }         
                // si 8 != del de arriba 7 entonces recorremos esa fila hasta que ese 7 sea distinto
                // Recorrer hasta el n-1 que sea diferente ejm;   0 2 3 4 5 6 [7] 7 y comprpbamos lo mismo si el 
                // de arriba es diferente si es asi entonces 

        }
    }
}



int main(int argc, char const *argv[]) {

    if (argc < 2) {
        cerr << "ERROR: Se necesita fichero de datos" << endl;
        exit(1);
    }

    ifstream inFile;
    int value;
    int M = atoi(argv[2]);

    inFile.open(argv[1]);
    vector<int> S;

    while (inFile >> value){
        S.push_back(value);
    }
    cout << "Size: " << S.size() << endl;

    for (int i = 0; i < S.size(); i++){
        cout << S[i] << "-";
    }
    cout << endl;

    inFile.close();
   
    //vector<int> suma = ;
    //cout << "Suma a " << M << ", Suma = ";
    //for (int i = 0; i < suma.size(); i++){
    if (M == 0){
        cout << "Suma a " << M << ", Suma = " << 0 << endl;
    }
    else {
        SumToNumber(S,M);
    }

    //vector<int> suma = ;
    /*cout << "Suma a " << M << ", Suma = ";
    for (int i = 0; i < suma.size(); i++){
         cout << suma[i] << "+";
    }*/


    return 0;

}
