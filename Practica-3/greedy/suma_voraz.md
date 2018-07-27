# Problema Suma Voraz

El problema que abordamos nos sitúa en la siguiente situación:

Teniendo como datos del problema: Un conjunto de datos(números)"S" que decidiremos si coger o no para llegar a la suma "M".
Por tanto partimos de dos datos: "S" y "M".

La solución consiste en devolver el subconjunto de "S" que sume una cifra "M",
o si, no pudiesen sumar esa cifra la más cercana a ella.

## Respecto a la solución:

#### Candidatos a seleccionar:

Respecto a los elementos candidatos hablamos de todo "S", en este caso son Números.

#### Candidatos seleccionados:

Los candidatos a seleccionar son números.

#### Función de Selección:

Serán los elementos más grandes de nuestro subconjunto "S".

#### Función Factibilidad:

Si el número al sumar el valor de los elegidos, o siendo el primero, supera o no
el valor M, si no lo supera lo añadimos y lo quitamos del conjunto "S", si lo supera no se añade pero se quita del conjuto "S".

#### Función de Solución:

Comprueba si la suma del subconjunto de números llega a "M" o si quedan números aún para seguir comprobando.
