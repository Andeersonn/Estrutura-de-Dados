# include <stdio.h>
# include <stdlib.h>


struct nodoLCDL{
	int ind;
	int qtd;
	struct nodoLCDL *prox, *ant;
};

typedef struct nodoLCDL nodoTP;
typedef nodoTP *nodoPTR;


int adicionarInicio(nodoPTR lista, int indice, int valor){
	nodoPTR novo;
	
	novo = (nodoPTR)malloc(sizeof(nodoTP));
	if(novo == NULL)return 0;
	
	novo->ind = indice;
	novo->qtd = valor;
	
	novo->prox = novo;
	novo->ant = lista;
	
	lista->prox = novo;
	(novo->prox)->ant = novo;
	
	return 1;
}


//FUNCAO ADICIONAR ORDENADO
int adicionarOrdenado(nodoPTR lista, int indice, int valor){
	nodoPTR novo, aux;
	
	novo = (nodoPTR)malloc(sizeof(nodoTP));
	if(novo == NULL)return 0;
	novo->ind = indice;
	novo->qtd = valor;
	
	lista->ind = indice+1;
	aux = lista->prox;
	while(aux->ind <= indice){
		aux = aux->prox;
	}
	
	novo->prox = aux;
	novo->ant = aux->ant;
	aux->ant->prox = novo;
	aux->ant = novo;
	
	return 1;
	
}

void imprimir(nodoPTR lista){
	nodoPTR aux;
	aux = lista->prox;
	while(aux != lista){
		printf("\nind: %d   qtd:  %d  \n",aux->ind, aux->qtd);
		aux = aux->prox;
	}
}


//BUSCAR EM ORDEM INVERTIDA
int buscarElementoInvertido(nodoPTR lista, int indice){
	nodoPTR aux;
	
	lista->ind = indice;
	aux = lista->ant;
	while(aux->ind != indice){
		aux = aux->ant;
	}
	if(aux == lista){
		printf("\nO indice procurado nao existe na lista.\n");
		return 0;
	}else{
		printf("\nO indice %d possui %d unidades\n", aux->ind, aux->qtd);
		return 1;
	}
}



int main(){

nodoPTR lista = NULL;
lista = (nodoPTR)malloc(sizeof(nodoTP));
lista->prox = lista;
lista->ant= lista;

adicionarOrdenado(lista, 1,10);
adicionarOrdenado(lista, 2,20);
adicionarOrdenado(lista, 3,30);
adicionarOrdenado(lista, 3,50);
imprimir(lista);
buscarElementoInvertido(lista, 3);	
	
}
