# Algoritmo Burbuja
 (Bubble Sort en inglés) es un sencillo algoritmo de ordenamiento. Funciona revisando cada elemento de la lista que va a ser ordenada con el siguiente, intercambiándolos de posición si están en el orden equivocado. Es necesario revisar varias veces toda la lista hasta que no se necesiten más intercambios, lo cual significa que la lista está ordenada. Este algoritmo obtiene su nombre de la forma con la que suben por la lista los elementos durante los intercambios, como si fueran pequeñas "burbujas". También es conocido como el método del intercambio directo. Dado que solo usa comparaciones para operar elementos, se lo considera un algoritmo de comparación, siendo uno de los más sencillo de implementar.

### Pasos a seguir para medir la eficiencia:
  1. Average: Generar vector de enteros aleatorio
  2. Best Case Scenario: Generar vector de enteros ordenado
  3. Worst Case Sceneario: Generar vector de enteros ordenados al reves
  4. Guardamos tiempos antes de ejecutar y despues de ejecutar el algortimo
  5. Calcular tiempo.


## Información
### Hardware usado (CPU, velocidad de reloj, memoria RAM, ...)
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/Mergesort/pic/lscpu.png)

### Compilador utilizado y opciones de compilación
    gcc -v    
    Using built-in specs.
    COLLECT_GCC=gcc
    COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
    Target: x86_64-linux-gnu
    gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.9)

### Compilación
    g++ -std=c++11 ./src/$PROGRAMA.cpp -o ./bin/$PROGRAMA

    Usamos el siguiente script:
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

<div style="page-break-after: always;"></div>
### Sistema operativo
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/Mergesort/pic/SO.png)

## Desarrollo completo del cálculo de la eficiencia teórica y gráfica.
### Calculo de  eficiencia O(n^2)
##### Average Case
Al algoritmo de la burbuja, para ordenar un vector de n términos, tiene que realizar siempre el mismo número de comparaciones:

c(n)=n^2 - n / 2

Esto es, el número de comparaciones c(n) no depende del orden de los términos, si no del número de términos:

Theta(c(n))= n^2

Por lo tanto la cota ajustada asintótica del número de comparaciones pertenece al orden de n cuadrado.

El número de intercambios i(n), que hay que realizar depende del orden de los términos y podemos diferenciar, el caso mejor, si el vector está previamente ordenado, y el caso peor, si el vector está ordenado en orden inverso:

Theta (i(n))=?

Por lo que no se puede determinar una cota ajustada asintótica del número de intercambios, dado que éste dependerá del orden del vector en cuestión.
##### Worst Case
Si pasamos al algoritmo un vector ordenado en orden inverso realizará un número de comparaciones:

c(n)= n^2 - n / 2

Como ya hemos dicho anteriormente, y tendrá que realizar un número igual de intercambios entre los términos del vector, dado que en cada comparación los términos estarán desordenados, y se realizará el intercambio.

i(n)= n^2 - n / 2

Por lo tanto en el caso más desfavorable tanto el número de comparaciones como el de intercambios coinciden:

O(c(n))=O(i(n)) = n^2

El número de comparaciones o de intercambios en el caso más desfavorable pertenece al orden de n cuadrado.

##### Best Case
En el caso óptimo, el más favorable, es la ordenación de un vector ya ordenado. En este caso el número de comparaciones será el mismo que en cualquier otro caso:

O(c(n)) = n^2
La cota inferior asintótica del número de comparaciones pertenece al orden de n cuadrado, como en los demás casos, pero en todas las comparaciones el orden es el correcto y por tanto no se realiza ningún intercambio:

i(n)=0

Por lo tanto el coste de intercambios no depende de n, y es constante: por eso el if de nuestra funcion para que llegue al swap.

Ω(i(n))=1
El ordenamiento de burbuja tiene una complejidad Ω(n²) igual que ordenamiento por selección.

<div style="page-break-after: always;"></div>
### Eficiencia Empirica
Hemos tomado  multiples medidas y sobre esto hemos realizado los ajustes y graficas.

#### Ejemplo de medidas Worst Case

N Elementos |  Tiempo
------------ |  -------------
1000  |0.0128259
2000	|0.0159879
3000	|0.0314597
4000	|0.0559006
5000	|0.0827111
6000	|0.117897
7000	|0.160575
8000	|0.209956
9000	|0.271175
10000	|0.329213
11000	|0.400247
12000	|0.47038
13000	|0.588833
14000	|0.650879
15000	|0.747161
16000	|0.856853
17000	|0.951987
18000	|1.07269
19000	|1.20147
20000	|1.31596
21000	|1.46145
22000	|1.61362
23000	|1.73663
24000	|1.89733
25000	|2.0626
26000	|2.24046
27000	|2.42087
28000	|2.56916
29000	|2.78776
30000	|2.96771

## Parámetros usados para el cálculo de la eficiencia empírica y gráfica.
Para el calculo de las gráficas hemos usado el script:

    #!/bin/bash

    #Variables:
    OUTPUT=./data/grafica_tiempo_average_case_burbuja.png
    TITULO="Algoritmo Burbuja Average Case"
    XLABEL="Longitud del Vector"
    YLABEL="Tiempo (segundos)"
    LEYENDA="Algoritmo Burbuja O(n^2)"
    FICHERO_DATOS="./data/tiempo_average_case_burbuja.dat"
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

<div style="page-break-after: always;"></div>
#### Average
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/burbuja/grafica_tiempo_average_case_burbuja.png)
<div style="page-break-after: always;"></div>
#### Worst Case
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/burbuja/grafica_tiempo_worst_case_burbuja.png)
<div style="page-break-after: always;"></div>
#### Best Case
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/burbuja/grafica_tiempo_best_case_burbuja.png)
<div style="page-break-after: always;"></div>
## Ajuste de la curva teórica a la empírica: mostrar resultados del ajuste y gráfica.
#### Grafica de comparacion con todos los casos
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/graficasTotales/grafica_tiempo_total_burbuja.png)
<div style="page-break-after: always;"></div>
#### Comparacion con los otros dos algoritmos
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/graficasTotales/grafica_tiempo_worst_total.png)
<div style="page-break-after: always;"></div>
#### Ajuste
![Thumbnail](/home/david/Dropbox/_UGR/ALG/Practica-1/Algoritmica/OrdenacionBasicos/data/burbuja/burbujaAjuste.png)

## Ajuste
    *******************************************************************************
    Mon Mar  5 19:06:34 2018


    FIT:    data read from "data/burbuja/tiempo_worst_case_burbuja.dat"
            format = z
            #datapoints = 30
            residuals are weighted equally (unit weight)

    function used for fitting: f(x)
      f(x)=a*x**2 + b*x + c
    fitted parameters initialized with current variable values

    iter      chisq       delta/lim  lambda   a             b             c            
       0 2.5033752448e+01   0.00e+00  2.72e-01    1.124277e-09  -1.514734e-08   1.744150e-03
       6 2.2883390484e-03  -3.42e-01  2.72e-07    3.285210e-09   4.390325e-07   1.197974e-03

    After 6 iterations the fit converged.
    final sum of squares of residuals : 0.00228834
    rel. change during last iteration : -3.41575e-06

    degrees of freedom    (FIT_NDF)                        : 27
    rms of residuals      (FIT_STDFIT) = sqrt(WSSR/ndf)    : 0.00920616
    variance of residuals (reduced chisquare) = WSSR/ndf   : 8.47533e-05

    Final set of parameters            Asymptotic Standard Error
    =======================            ==========================
    a               = 3.28521e-09      +/- 2.513e-11    (0.7648%)
    b               = 4.39033e-07      +/- 8.027e-07    (182.8%)
    c               = 0.00119797       +/- 0.005398     (450.6%)

    correlation matrix of the fit parameters:
                    a      b      c      
    a               1.000
    b              -0.970  1.000
    c               0.770 -0.882  1.000
