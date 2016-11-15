/*	Elimina comentarios de un programa escrito en lenguaje C.
	Autores: Cabaleiro, Julian - Cabrera, Ivana - Martinez, Guido - 
		- Merlis, Nicolas - Montivero, Javier 
	15/11/2016
*/

#include<stdio.h>
#define ESPACIO ' '

int main(void){
	int c;

	init://Estado inicial y principal, pone en la salida todo lo que lee, salvo cuando entra en un comentario.
		switch(c = getchar()){
			case '/':
				goto comment;
			case '\"':
				putchar(c);
				goto literalCadena;
			case '\'':
				putchar(c);
				goto literalCaracter;
			case EOF:
				goto END;
			default:
				putchar(c);
				goto init;
		}
		
	comment://Detecta si se trata de un comentario de una o muchas lineas
		switch(c = getchar()){
			case '/':
				putchar(ESPACIO);
				goto singleLineComment;
			case '*':
				putchar(ESPACIO);
				goto multiLineComment;
			default:
				putchar('/');
				putchar(c);
				goto init;
		}
		
	singleLineComment://Lee hasta llegar hasta el final de la linea
		switch(c = getchar()){
			case '\n':
				putchar(c);
				goto init;
			default:
				goto singleLineComment;
		}
		
	multiLineComment://Lee hasta que un '*' indica que quizas termine el comentario
		switch(getchar()){
			case '*':
				goto pOutMLComment;
			default:
				goto multiLineComment;
		}
		
	pOutMLComment: //Estado de posible salida de comentario
        switch(getchar()){
            case '/': //Fin comentario
                goto init;
            case '*': //Caso especial /***/
                 goto pOutMLComment;
            default:
                goto multiLineComment;
        }
        
	literalCadena://Se encarga de que las cadenas literales que contengan comentarios no sean eliminadas
		switch(c = getchar()){
			case '\"':
				putchar(c);
				goto init;
			default:
				putchar(c);
				goto literalCadena;
		}
		
	literalCaracter://Se encarga de que los caracteres literales que contienen comentarios no sean eliminados
		switch(c = getchar()){
			case '\'':
				putchar(c);
				goto init;
			default:
				putchar(c);
				goto literalCaracter;
		}
	END:;
}
