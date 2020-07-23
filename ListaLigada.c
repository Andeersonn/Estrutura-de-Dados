#include <stdio.h>
#include <stdlib.h>


typedef struct nodo{
	int info;
	struct nodo *prox;
}Nodo;

//inicializacao
Nodo *iniciaLista(void){ 
	return NULL;
}

//imprimir

void imprimir(Nodo* lista) {
  while (lista != NULL) {
    printf("%d , ", lista->info);
    lista = lista->prox;
	  
  }
}
//inserir
void inserir(Nodo** lista, int v) {
  Nodo *n, *aux;
  n = (Nodo*) malloc(sizeof(Nodo));
  n->info = v;
  n->prox = NULL;  
  if (*lista == NULL) 
    *lista = n;
  else {
    aux = *lista;
    while (aux->prox != NULL)
      aux = aux->prox;
    aux->prox = n;
  }
}

void removerelemento(Nodo *elem, int v){
Nodo *aux1;
Nodo *aux2;
aux1 = elem;
aux2 = elem->prox;

while(aux2!= NULL && aux2->info != v){
	aux1 = aux2;
	aux2 = aux2->prox;
}
aux1->prox = aux2->prox;
}

void insereEntre(int v, Nodo *p, int pos)
{
   Nodo *nova, *aux1, *aux2;
   nova = malloc(sizeof (Nodo));
   nova->info = v;
   aux1 = p;
   aux2 = aux1->prox;
while (aux2 != NULL && aux1->info != pos)
 {
 aux1 = aux2;
 aux2 = aux1->prox;
 }
 aux1->prox = nova;
 nova->prox = aux2;
   
}




void inverter(Nodo **p0)
   {
       Nodo *pa, *p, *pd;
       if (*p0 != NULL)
       {
           pa = NULL;
           p = *p0;
           pd = p->prox;
           do
           {
               p->prox = pa;
               pa = p;
               p = pd;
               if (pd != NULL) pd = pd->prox;
           }
           while (p != NULL);
           *p0 = pa;
       }
}
  
  
  
main(){
	
	int	i=1;
	printf("=====Lista Ligada Linear=====:\n\n");
	Nodo *elem = NULL;
	
	printf("=====Elementos ordenados=====: \n\n");
	iniciaLista();
	
	while(i<10){
		inserir(&elem,i);
		i++;
	}
	imprimir(elem);

	printf("\n\n");
	
	removerelemento(elem,8);
	printf("=====Remover elemento 8=====: \n\n");
	imprimir(elem);
	printf("\n\n");
	
	printf("=====Adicoinar Elemento 8 entre 4 e 5=====: \n\n");
	insereEntre(8,elem,4);
	imprimir(elem);
		printf("\n\n");
		
	printf("=====Imprimir Elementos em ordem Decrescente=====: \n\n");
	inverter(&elem);
	imprimir(elem);
	printf("\n\n");

	
}
