#include <stdio.h>//imprimir
#include <stdlib.h>//alocacao de memoria


struct nodo{
int info;
struct nodo * next;//recursividade
};

void imprimeListaLigada(struct nodo *p){
	int i=0;
	if(p){
		do{
			printf("Nodo %d %d \n",i, p->info);
			p=p->next;
			i++;
		}while(p);
	}
}




int main(){
	struct nodo *nodo1= NULL;
	struct nodo *nodo2 = NULL;
	struct nodo *nodo3 = NULL;
	struct nodo *nodo4 = NULL;
	
	//ALOCANDO MEMORIA PRO NODOS
	nodo1 = (struct nodo*) malloc(sizeof(struct nodo*));
	nodo2 = (struct nodo*) malloc(sizeof(struct nodo*));
	nodo3 = (struct nodo*) malloc(sizeof(struct nodo*));
	nodo4 = (struct nodo*) malloc(sizeof(struct nodo*));
	
	//atribuindo valores para os nodos no seu atributo "info"
	nodo1->info = 6;
	nodo2->info = 10;
	nodo3->info=18;
	nodo4->info = 23;
	
	//ligar os nós
	
	nodo1->next = nodo2;
	nodo2->next = nodo3;
	nodo3->next = nodo4;
	nodo4->next = NULL;
	
	imprimeListaLigada(nodo1);
	


	
return 0;	
}
