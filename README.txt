Trabajo Practico para Sintaxis y Semantica de los Lenguajes - UTN
Profesor: Sola, Jose María
Curso K2051
Grupo 2: Montivero, Javier - Martinez, Guido - Cabrera, Ivana - Merlis, Nicolas - Cabaleiro, Julian

-CONSIGNA-
Desarrollar un programa en lenguaje C que elimine los comentarios de un programa escrito en C.
Implementarlo con una maquina de estados utilizando goto y etiquetas.

Se presenta en main.c el programa probado y funcionando correctamente. En borraComentarios.gv 
se encuentra el codigo .dot para generar el grafo que representa la maquina de estados implementada, 
cuya salida se encuentra en borraComentarios.png. El archivo test.c es un programa en C que se puede 
usar para probar la entrega.

--ACLARACIONES--
En el grafo de la maquina de estados se usa c para representar todos los caracteres que no se contemplan 
en las demas transiciones de cada estado. Se trata como una transicion por defecto.