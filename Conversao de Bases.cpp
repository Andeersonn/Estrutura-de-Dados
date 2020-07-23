//Criar um pequeno código em linguagem C que:
// peque um valor qualquer escrito pelo usuário na base13;

//transforme este valor para a base 10, base 2, base 8 e base 16;

//apresente os resultados de forma estruturada.

//base 13 vai de 0 à C

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int converteDecimal(char valor_13[60], int tam,int posicaoB10){
	int i, numero, soma=0;
		for(i=0; i < tam; i++){
			switch(valor_13[i]){
				case '0': 
	numero=0;
	break;
	case '1': 
	numero=1;
	break;
	case '2': 
	numero=2;
	break;
	case '3':
	 numero=3;
	 break;
	case '4':
	 numero=4;
	 break;
	case '5': 
	numero=5;
	break;
	case '6': 
	numero=6;
	break;
	case '7':
	 numero=7;
	 break;
	case '8': 
	numero=8;
	break;
	case '9': 
	numero=9;
	break;
	case 'A': 
	numero=10;
	break;
	case 'a': 
	numero=10;
	break;
	case 'B': 
	numero=11;
	break;
	case 'b': 
	numero=11;
	break;
	case 'C': 
	numero=12;
	break;
	case 'c': 
	numero=12;
	break;
	}
	posicaoB10 = posicaoB10 - 1;
	soma = soma+(numero * pow(13,posicaoB10));
	}
		return soma;
	}
	
int main(){
	char valor_b13[60],numero2[5],valor[100]="",auxiliar[100],binario[100];
	int base = 0, i, numero, quociente, resto,len, soma=0;
	int posicao,posicao2;
	int p,p2;
	
	printf("Digite a base para qual quer converter: \n");
	scanf("%d",&base);
	printf("Digite o valor: \n");
	fflush(stdin);
	gets(valor_b13); 
	posicao = strlen(valor_b13);
	p = posicao;
	if(base == 10){
	printf("O valor em decimal e: %d",converteDecimal(valor_b13,p,posicao));
}

	if(base == 2){
		soma = converteDecimal(valor_b13,p,posicao);
		
		quociente = soma;
		while(quociente >=2){
			resto = quociente % 2;
			itoa(resto,binario,2);
			strcat(valor,binario);
			quociente = quociente/2;
		}
		itoa(quociente,binario,2);
		strcat(valor,binario);
		//invertendo string
			len = strlen(valor)-1;
			for(i=0;valor[i]!='\0';i++){
				auxiliar[len] = valor[i];
				len--;
			}
			auxiliar[i] = '\0';
			strcpy(valor,auxiliar);
			printf("O valor em binario e: %s",valor);
		
	}
	
	if(base == 8){
	soma = converteDecimal(valor_b13,p,posicao);
	quociente = soma;
		while(quociente >=8){
			resto = quociente % 8;
			itoa(resto,binario,8);
			strcat(valor,binario);
			quociente = quociente/8;
		}
		itoa(quociente,binario,8);
		strcat(valor,binario);
		//invertendo string
			len = strlen(valor)-1;
			for(i=0;valor[i]!='\0';i++){
				auxiliar[len] = valor[i];
				len--;
			}
			auxiliar[i] = '\0';
			strcpy(valor,auxiliar);
			printf("O valor em octal e: %s",valor);

	}
	}
	
