#include <stdio.h>
#include <stdlib.h>

typedef struct{ //cria��o do tipo abstrato de dado
	int ultimo; //cria��o da variavel ultimo
	int *dados; //cria��o da variavel como um ponteiro
	int capacidade; //variavel que indica a capacidade maxima da lista
}estrutura_Lista; //nome do tipo definido


void criaLista(estrutura_Lista *l, int c){ //cria��o da fun��o que cria lista
	l->capacidade = c; //capacidade da pilha recebe um valor passado por parametro
	l->dados = malloc(l->capacidade*sizeof(estrutura_Lista)); //dados recebe a aloca��o de mem�ria da capacidade da lista
	l->ultimo = 0; //ultimo inicia com 0
}

void insereFinal(estrutura_Lista *l, int A){ //cria��o da fun��o que insere um valor no final da lista
	l->dados[l->ultimo]=A; //dados recebe o valor do elemento passado por parametro
	l->ultimo+=1; //incremente +1 na vari�vel, indicando a existencia de um elemento. 
}


void retiraPos(estrutura_Lista *Lista, int p){ //cria��o da fun��o que retira um elemento da posi��o escolhida 
	int Aux; //cria��o de uma variavel auxiliar
	Lista->dados--; //decremento da quantidade de dados.
	for(Aux = p; Aux < Lista->ultimo; Aux++) //for para reorganizar os dados em posi��es
		Lista->dados[Aux] = Lista->dados[Aux+1]; //dados na posi��o de auxiliar que recebe p, ir� receber o dado da pr�xima posi��o e assim reorganizar.
}


int consultaLista(estrutura_Lista *Lista, int p){ //fun��o para consultar um elemento da lista
	
	if(p > Lista->capacidade || p <= 0){ //verifica se existe a posi��o
		printf("Posicao invalida \n"); //printa que a posi��o � invalida
	}
	else{
		printf("Valor do elemento: %d \n",Lista->dados[p-1]); //se a posi��o n�o for invalida, printa o valor do elemento.
	}
}


int imprimeLista(estrutura_Lista *l){ //cria��o da variavel para imprimir lista
	int i; //cria��o de uma variavel para utilizar no for
	for(i=0;i<=l->ultimo-1; i++){ //utliza��o do for para imprimir cada valor na posi��o i
		printf("%d\t", l->dados[i]); //imprime o valor do dado na posi��o i
	}
	printf("\n"); // espa�amento
}


int imprimeTamanho(estrutura_Lista *l){ //cria��o de uma fun��o que imprime o tamanho da lista
	printf("Tamanho: %d \n", l->ultimo); //print do tamanho da lista, sendo a variavel ultimo a respons�vel por indicar a quantidade de elementos existente.
}

int main(){
	estrutura_Lista lista1; //cria a variavel do tipo estrutura_Lista
	criaLista(&lista1, 20); //chamada da fun��o passando a variavel e a capacidade da lista
	insereFinal(&lista1, 10);//chamada da fun��o passando a variavel e o valor que deseja inserir no final 
	insereFinal(&lista1, 20); //chamada da fun��o passando a variavel e o valor para inserir no final
	insereFinal(&lista1, 30); //chamada da fun��o passando a variavel e o valor para o final
	imprimeTamanho(&lista1); //chamada da fun��o para imprimir tamanho, passando apenas a variavel
	consultaLista(&lista1, 3); //chamada da fun��o para consultar, passando a variavel e o valor da posi��o
	imprimeLista(&lista1); //chamada da fun��o para imprimir a lista, passndo apenas a variavel
	retiraPos(&lista1, 2); //chamada da fun��o para retirar um elemento, passando a variavel e a posi��o desejada
	imprimeLista(&lista1); //chamada novamente da fun��o para imprimir a lista
return 0; 
}
