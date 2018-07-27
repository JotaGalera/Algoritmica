#!/bin/bash
# https://www.ibiblio.org/pub/linux/docs/LuCaS/Presentaciones/200304curso-glisa/gnuplot/curso-glisa-gnuplot-html/x590.html
# Script de bash para crear una imagen .png con GNU-PLOT

#Variables:
OUTPUT=./data/grafica_tiempo_total_seleccion.png
TITULO="Algoritmo Seleccion Total Case"
XLABEL="Longitud del Vector"
YLABEL="Tiempo (segundos)"
LEYENDA="Algoritmo Seleccion worst O(n^2)"
FICHERO_DATOS="./data/seleccion/tiempo_average_case_seleccion.dat"
COLOR=blue

FICHERO_DATOS2="./data/seleccion/tiempo_best_case_seleccion.dat"
COLOR=green

FICHERO_DATOS3="./data/seleccion/tiempo_worst_case_seleccion.dat"
COLOR=red

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

plot "$FICHERO_DATOS","$FICHERO_DATOS2","$FICHERO_DATOS3" title '$LEYENDA' with linespoints ls 1

FIN
