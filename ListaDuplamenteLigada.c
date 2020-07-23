# include<stdio.h>
# include<stdlib.h>

struct noListaDL{
	int valor;
	struct noListaDL *ant, *prox;
};

typedef struct noListaDL NOLISTADL;
typedef NOLISTADL *NOLISTAPTR;


//VEREFICAR SE A LISTA ESTA VAZIA
int vereficarVazia(NOLISTAPTR lista){
	return lista == NULL;
}

//FUNCAO INSERIR
void insereInicio(NOLISTAPTR *inic, int valor){
	NOLISTAPTR novo;
	novo = (NOLISTAPTR)malloc(sizeof(NOLISTADL));
	if(novo == NULL)
	return;
	if(*inic == NULL){
		novo->valor = valor;
		novo->prox = novo->ant = NULL;
		*inic = novo;
	}
	else{
		novo->valor = valor;
		novo->ant = NULL;
		novo->prox = *inic;
		(*inic)->ant = novo;
		*inic = novo;
	}
	printf("\nInserido o valor [ %d ] no comeco da lista\n ", valor);
}

//IMPRIMIR EM ORDEM DIRETA
void imprimirOrdemDireta(NOLISTAPTR lista){
	if(vereficarVazia(lista))
		printf("\n\nA lista esta VAZIA.\n");
	else{
		printf("\nA lista em ordem Direta:\n");
		while(lista != NULL){
			printf("[ %d ]", lista->valor);
			lista = lista->prox;
		}
	}
}


//IMPIRMIR EM ORDEM INVERSA
void imprimirOrdemInversa(NOLISTAPTR lista){
	if(vereficarVazia(lista))
		printf("\nA lista esta vazia.\n");
	else{
		while(lista->prox != NULL)
			lista = lista->prox;
			
			printf("\nA lista em ordem INVERSA:\n");
			while(lista != NULL){
				printf("[ %d ]", lista->valor);
				lista = lista->ant;
			}
	}
}


//INSERIR NO FINAL

	void insereFinal(NOLISTAPTR *inic, int valor){
	NOLISTAPTR novo, atual;
	novo = malloc(sizeof(NOLISTADL));
	
	if(novo == NULL)
	return;
	if(*inic == NULL){
		novo->valor = valor;
		novo->prox = novo->ant = NULL;
		*inic = novo;
	}
	else{
		atual = *inic;
		while(atual->prox != NULL)
		atual = atual->prox;
		
		novo->valor = valor;
		novo->ant = atual;
		novo->prox = NULL;
		atual->prox = novo;
	}
	printf("\nInsere o valor [ %d ] no final da lista\n", valor);
	
}


//REMOVER ELEMENTO DA LISTA
int remover(NOLISTAPTR *inic, int valor){
	NOLISTAPTR temp, atual;
	if(*inic == NULL)
	return 0;
	atual = *inic;
	
	if((*inic)->valor == valor)
		*inic = (*inic)->prox;
	
	while(atual != NULL && atual->valor != valor)
		atual = atual->prox;
	if(atual == NULL)
	return 0;
	else{
		temp = atual;
		
		if(atual->ant != NULL)
			atual->ant->prox = atual->prox;
			
		if(atual->prox != NULL)
			atual->prox->ant = atual->ant;
			
			free(temp);	
		
	}
	printf("\n\nRemovido o valor: [ %d ]\n", valor);
	return 1;
}

//REMOVENDO NO
int removerNo(NOLISTAPTR *inic){
	NOLISTAPTR temp;
	int c;
	temp = *inic;
	c = (*inic)->valor;
	*inic = (*inic)->prox;
	free(temp);
	return c;
}




int main(){
	//DECLARAR FUNCAO
	NOLISTAPTR lista = NULL;
	
	//IMPRIMIR EM ORDEM DIRETA
	imprimirOrdemDireta(lista);
	
	//inserir inicio
	insereInicio(&lista, 1);
	insereInicio(&lista, 2);
	insereInicio(&lista, 3);
	imprimirOrdemDireta(lista);
	
	//INSERIR FINAL
	insereFinal(&lista, 4);
	insereFinal(&lista, 5);
	imprimirOrdemDireta(lista);
	
	//REMOVER
	remover(&lista, 3);

	//IMPRIMIR EM ORDEM INVERSA
	imprimirOrdemInversa(lista);
	
	//VERIFICAR SE ESTA VAZIA
	vereficarVazia(lista);
		
	//REMOVER NO
	removerNo(&lista);
	
	return 0;
		
}
