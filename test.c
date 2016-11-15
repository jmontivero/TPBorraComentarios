#include<stdio.h>
//Este es un comentario de una linea
void test(){ 
	/*Este es un
		comentario en
		muchas lineas
	*/
	char *a = "//Este String no es un comentario, aunque parece uno. No se eliminará";
	
	printf("Este es un archivo .c de prueba para el eliminador de comentarios.");
}/*Este comentario se encarga de probar que los comentarios en multiples lineas
	contemplen el fin del archivo*/
