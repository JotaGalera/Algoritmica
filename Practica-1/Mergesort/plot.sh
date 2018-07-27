#!/bin/bash

# Script de bash para crear una imagen .png con GNU-PLOT

#Variables:
OUTPUT=./data/grafica_tiempo_worst_case_mergesort.png
TITULO="Algoritmo Mergesort Worst Case No Insertion"
XLABEL="Longitud del Vector"
YLABEL="Tiempo (segundos)"
LEYENDA="Algoritmo Mergesort O(n*Log(n))"
FICHERO_DATOS="./data/tiempo_worst_case_mergesort.dat"
COLOR=blue

gnuplot<<FIN
# Terminal para png:
set terminal pngcairo enhanced font 'Verdana,10'
set border linewidth 1.5

# Estilo de línea y color:
set style line 1 lc rgb '$COLOR' lt 1 lw 2 pt 7 pi 0 ps 0.5
set pointintervalbox 0

# Nombre de la imagen resultante:
set output '$OUTPUT'

# Título y ejes:
set title "$TITULO" enhanced font 'Verdana,14'
set xlabel "$XLABEL"
set ylabel "$YLABEL"

set autoscale

plot "$FICHERO_DATOS" title '$LEYENDA' with linespoints ls 1
FIN
