#include <stdio.h>
#include <stdlib.h>

typedef struct{ //criação do tipo abstrato de dado
	int ultimo; //criação da variavel ultimo
	int *dados; //criação da variavel como um ponteiro
	int capacidade; //variavel que indica a capacidade maxima da lista
}estrutura_Lista; //nome do tipo definido


void criaLista(estrutura_Lista *l, int c){ //criação da função que cria lista
	l->capacidade = c; //capacidade da pilha recebe um valor passado por parametro
	l->dados = malloc(l->capacidade*sizeof(estrutura_Lista)); //dados recebe a alocação de memória da capacidade da lista
	l->ultimo = 0; //ultimo inicia com 0
}

void insereFinal(estrutura_Lista *l, int A){ //criação da função que insere um valor no final da lista
	l->dados[l->ultimo]=A; //dados recebe o valor do elemento passado por parametro
	l->ultimo+=1; //incremente +1 na variável, indicando a existencia de um elemento. 
}


void retiraPos(estrutura_Lista *Lista, int p){ //criação da função que retira um elemento da posição escolhida 
	int Aux; //criação de uma variavel auxiliar
	Lista->dados--; //decremento da quantidade de dados.
	for(Aux = p; Aux < Lista->ultimo; Aux++) //for para reorganizar os dados em posições
		Lista->dados[Aux] = Lista->dados[Aux+1]; //dados na posição de auxiliar que recebe p, irá receber o dado da próxima posição e assim reorganizar.
}


int consultaLista(estrutura_Lista *Lista, int p){ //função para consultar um elemento da lista
	
	if(p > Lista->capacidade || p <= 0){ //verifica se existe a posição
		printf("Posicao invalida \n"); //printa que a posição é invalida
	}
	else{
		printf("Valor do elemento: %d \n",Lista->dados[p-1]); //se a posição não for invalida, printa o valor do elemento.
	}
}


int imprimeLista(estrutura_Lista *l){ //criação da variavel para imprimir lista
	int i; //criação de uma variavel para utilizar no for
	for(i=0;i<=l->ultimo-1; i++){ //utlização do for para imprimir cada valor na posição i
		printf("%d\t", l->dados[i]); //imprime o valor do dado na posição i
	}
	printf("\n"); // espaçamento
}


int imprimeTamanho(estrutura_Lista *l){ //criação de uma função que imprime o tamanho da lista
	printf("Tamanho: %d \n", l->ultimo); //print do tamanho da lista, sendo a variavel ultimo a responsável por indicar a quantidade de elementos existente.
}

int main(){
	estrutura_Lista lista1; //cria a variavel do tipo estrutura_Lista
	criaLista(&lista1, 20); //chamada da função passando a variavel e a capacidade da lista
	insereFinal(&lista1, 10);//chamada da função passando a variavel e o valor que deseja inserir no final 
	insereFinal(&lista1, 20); //chamada da função passando a variavel e o valor para inserir no final
	insereFinal(&lista1, 30); //chamada da função passando a variavel e o valor para o final
	imprimeTamanho(&lista1); //chamada da função para imprimir tamanho, passando apenas a variavel
	consultaLista(&lista1, 3); //chamada da função para consultar, passando a variavel e o valor da posição
	imprimeLista(&lista1); //chamada da função para imprimir a lista, passndo apenas a variavel
	retiraPos(&lista1, 2); //chamada da função para retirar um elemento, passando a variavel e a posição desejada
	imprimeLista(&lista1); //chamada novamente da função para imprimir a lista
return 0; 
}
