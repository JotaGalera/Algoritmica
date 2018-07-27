#!/bin/bash

###############################################################
# Algoritmica, Practica 1
# Medir el tiempo del algoritmo de un algoritmo de ordenación.
###############################################################

# Script de bash que obtiene los datos para el algoritmo de burbuja

# Variables:
PROGRAMA=$1
SALIDA=./data/tiempo_best_case_$1.dat
MENSAJE_INICIO="Se inicia la ejecución del algoritmo $1:"
MENSAJE_FINAL="Fin de la ejecución. Se ha creado un fichero con los resultados."

# Se genera el ejecutable con el algoritmo de ordenación:
g++ -std=c++11 ./src/$PROGRAMA.cpp -o ./bin/$PROGRAMA
echo "$MENSAJE_INICIO"

# Variables:
INICIO=1000
FIN=30000
INCREMENTO=1000

i=$INICIO
echo > $SALIDA
while [ $i -le $FIN ]
do
    echo Vector size = $i
    echo "`./bin/$PROGRAMA $i 10000`" >> $SALIDA
    i=$((i+$INCREMENTO))
done

rm -fr ./bin/$PROGRAMA

echo "$MENSAJE_FINAL"
