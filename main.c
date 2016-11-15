#include<stdio.h>
#define ESPACIO ' '
int main(void){
	int c;

	init:
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
		
	comment:
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
		
	singleLineComment:
		switch(c = getchar()){
			case '\n':
				putchar(c);
				goto init;
			default:
				goto singleLineComment;
		}
		
	multiLineComment:
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
            case '*': //Caso especial "/***/"
                 goto pOutMLComment;
            default:
                goto multiLineComment;
        }
        
	literalCadena:
		switch(c = getchar()){
			case '\"':
				putchar(c);
				goto init;
			default:
				putchar(c);
				goto literalCadena;
		}
		
	literalCaracter:
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
