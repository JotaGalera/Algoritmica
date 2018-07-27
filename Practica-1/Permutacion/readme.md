# Permutaciones

## Descripción del ejercicio

En este caso se nos plantea encontra un algoritmo para poder comprobar
si una permutación generada resulta estar orenada de menor a mayor.

## Algoritmo de ordenación
~~~~
void CheckSorted(bool &sorted, const string &c){
  for (int i = 0; i < c.size() && !sorted; i++) {
     if (c[i] < c[i+1])
      sorted = true;
    else sorted = false;
  }
  if(sorted == true)
    cout<<"\n Permutacion con vector ordenado \n";
~~~~

Presentamos como solución a este un algoritmo que presenta una eficiencia
en:

1. Mejor caso: En el que la primera permutacion ya está ordenada: de O(n)
2. Peor caso: En el que que habría que obtendriamos O(n!)
