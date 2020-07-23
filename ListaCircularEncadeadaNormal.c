#include <stdio.h>
#include <stdlib.h>


//define a estrutura do Nodo
typedef struct nodoLC{
	int ind;
	int qtd;
	struct nodoLC *prox;
};

typedef struct nodoLC  nodoTP;
typedef nodoTP *nodoPTR;

//Adcionar Inicio
int adicionarInicio(nodoPTR lista, int indice, int valor){
	nodoPTR novo;
	novo = (nodoPTR)malloc(sizeof(nodoTP));
	if(novo==NULL) return 0;
	
	novo->ind = indice;
	novo->qtd = valor;
	
	novo->prox = lista->prox;
	lista->prox = novo;
	
	return 1;
}
//imprimir
void imprimir(nodoPTR lista){
	nodoPTR aux;

	aux = lista->prox;
	while(aux!=lista){
		printf("\n ind: %d    qtd: %d \n", aux->ind, aux->qtd);
		aux = aux->prox;
	}
}

//Adcionar Ordenado
int adicionarOrdenado(nodoPTR lista, int indice, int valor){
	nodoPTR novo,aux, aux2;
	
	novo = (nodoPTR)malloc(sizeof(nodoTP));
	if(novo==NULL)return 0;
	
	novo->ind = indice;
	novo->qtd = valor;
	aux = lista;
	aux2 = aux->prox;
	
	while(aux2 != lista && aux2->ind <= indice){
		aux = aux2;
		aux2 = aux->prox;
	}
	aux->prox = novo;
	novo->prox = aux2;

	return 1;
}

//BUSCAR ELEMENTO
int buscarElemento(nodoPTR lista, int indice){
	nodoPTR aux;
	
	lista->ind = indice;
	aux = lista->prox;
	while(aux->ind != indice){
		aux = aux->prox;
	}
	if(aux == lista){
		printf("\n o indice procurado nao existe na lista.\n");
		return 0;
	}else{
		printf("\nO indice %d possui %d  unidades\n", aux->ind, aux->qtd);
		return 1;
	}
}

//REMOVER
int remover(nodoPTR lista, int indice){
	nodoPTR aux, aux2;
	
	aux = lista;
	while(aux->prox != lista && aux->prox->ind != indice){
		aux = aux->prox;
	}
	if(aux->prox == lista) return 0;
	else{
		aux2 = aux->prox;
		aux->prox = aux2->prox;
		free(aux2);
		return 1;
	}
}

//DESTRUIR 
void destroiLista(nodoPTR *lista){
	int valor;
	nodoPTR atual = *lista;
	
	while(atual->prox != atual){
		valor = atual->prox->ind;
		remover(atual, valor);
	}
	free(atual);
	printf("\nLista destruida!\n");
}

//FUNCAO PRINCIPAL
int main(){

nodoPTR lista = NULL;
lista = (nodoPTR)malloc(sizeof(nodoTP));
lista->prox = lista;

//adicionar Elemento
adicionarOrdenado(lista, 1,10);
adicionarOrdenado(lista, 2,20);
adicionarOrdenado(lista, 3,30);
adicionarOrdenado(lista, 4,40);
adicionarOrdenado(lista, 5,50);

//IMPRIMIR ELEMENTO
imprimir(lista);

//REMOVER ELENTO
remover(lista, 2);

//BUSCAR ELEMENTO
buscarElemento(lista,3);
imprimir(lista);

//DESTRUIR ELEMENTO
destroiLista(&lista);
imprimir(lista);



return 0;	
}
