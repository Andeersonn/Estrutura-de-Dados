#include <stdio.h>
#include <stdlib.h>

struct nodoLCDL{
	int indice;
	int quant;
	struct nodoLCDL *prox;
};

typedef struct nodoLCDL nodoTP; //lista
typedef struct nodoLCDL *nodoPTR; //outro 

//remoção das linhas de código referenciando o campo ant
int adicionaInicio(nodoPTR lista, int ind, int val){
	
	nodoPTR novo;
	novo = (nodoPTR)malloc(sizeof(nodoTP)); //aloca memória para um novo nodo
	if(novo == NULL) //se não funcionar ele retorna 0 e sai
		return 0;
		
	novo->indice = ind; //o novo novo recebe um indice
	novo->quant = val; // recebe um valor 
	novo->prox = lista->prox; //o campo proximo pega o prox da lista	
	lista->prox = novo; // o prox da lista recebe o novo nodo	
	return 1; 
	
}

//sem alterações
int buscarElemento(nodoPTR lista, int ind){
	nodoPTR aux;
	lista->indice = ind; //recebo o indice
	aux = lista->prox; //aux recebe o prox da lista
	while(aux->indice != ind){ //enquanto for diferente do que procuro
		aux = aux->prox; //minha aux anda para o prox
	}
	if(aux == lista){ //se for igual a lista, não existe
		printf("\n O indice procurado nao existe na lista");
		return 0;
	}	
	else{ //se não for, ele achou
		printf("\n O indice %d possui %d", aux->indice, aux->quant);
		return 1;
	}
}

//alterado
//add outra variavel auxiliar e nova lógica

int remover(nodoPTR lista, int ind){
	nodoPTR aux, aux2;
	aux = lista;
	while(aux->prox != lista && aux->prox->indice != ind){ //enquanto a aux no campo prox for diferente da lista, assim como seu campo prox no atributo indice for diferente de ind
			aux = aux->prox; //movimento a auxiliar
	}
		if(aux->prox == lista)
			return 0;
			
		else{	
			aux2 = aux->prox;
			aux->prox = aux2->prox;
			free(aux2);
			return 1;
    	}
}
	

//sem alterações
void destroiLista(nodoPTR *lista){
	int valor;
	nodoPTR atual = *lista;
	
	while(atual->prox != atual){
		valor = atual->prox->indice; //pego o valor do nodo atual prox no indice;
		remover(atual, valor); //chamo a função remover para ir removendo cada valor encontrado;
	}
	free(atual); //libero memória;
	printf("\n Lista destruida!");
}

//sem alterações
void imprimir(nodoPTR lista){
	nodoPTR aux;
	if(lista == NULL){
		printf("Vazia");
	}
	aux = lista->prox; //a aux recebe o valor do prox nodo
	
	while(aux != lista){
		printf("\n ind: %d    qtd: %d", aux->indice, aux->quant); //imprimo os dois valores
		aux = aux->prox; //aux recebe prox para chegar até nulo
	}
}


//add mais uma variavel
int adicionaOrdenado(nodoPTR lista, int ind, int val){
	nodoPTR novo, aux, aux2;
	
	novo = (nodoPTR)malloc(sizeof(nodoTP)); //aloca memória para um novo nodo	
	novo->indice = ind; //o novo novo recebe um indice
	novo->quant = val; // recebe um valor 
	aux = lista; //aux recebe o conteudo da lista
	aux2 = aux->prox; //aux 2 recebe este conteudo no campo prox
	while(aux2 != lista && aux2->indice<= ind){ //organizando os indices
		aux = aux2; 
		aux2 = aux->prox;
	}
	//ligações
	aux->prox = novo; 	
	novo->prox = aux2; 	
	return 1; 
}


int main(){
	nodoPTR lista;
	lista = (nodoPTR)malloc(sizeof(nodoTP)); //inicializando a lista
	lista->prox = lista;
	adicionaOrdenado(lista, 1, 10);
	adicionaOrdenado(lista, 2, 20);
	adicionaOrdenado(lista, 3, 30);
	adicionaOrdenado(lista, 4, 40);
	imprimir(lista);
	remover(lista, 2);
	buscarElemento(lista, 4);
	imprimir(lista);
	adicionaOrdenado(lista, 2, 50);
	imprimir(lista);	
	destroiLista(&lista);
	return 0;
}
