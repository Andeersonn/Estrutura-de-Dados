#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//PILHA

typedef struct{ //criação da estrutura da pilha, um tipo abstrato de dado.
	int topo; // criação do topo; indica tamamho e ultimo elemento.
	int *dados; //esta variável é criada como ponteiro (é opcional a criação como ponteiro ou não)
	int capacidade; // variavel da capacidade máxima da pilha
}estrutura_Pilha; //linha que da nome ao tipo. 


void criaPilha(estrutura_Pilha *p, int c){ //criação da função que cria a pilha
	p->capacidade = c; // a capacidade, ou seja, a quantidade máxima de elementos recebe C (enviado por parâmetro)
	p->dados = malloc(p->capacidade*sizeof(estrutura_Pilha)); // dados recebe a função malloc (alocação de memória), que aloca em dados a capacidade da pilha. 
	if(!p){ //verificação de p, se ele não existe
		printf("Não existe memoria suficiente"); //printa na tela uma mensagem para o usuario.
		return; //retorna
	}
	p->topo = 0; //topo recebe 0, indicando que não existe elementos.
}
 
void empilha(estrutura_Pilha *p, int A){ //criação da função de adiciona elementos. 
	
	if(p->topo == p->capacidade){ //verifica se o topo (responsável por indicar a quantidade de elementos existentes na pilha) é igual a capacidade da pilha (quantidade maxima de elementos)
		printf("Pilha cheia \n"); //imprime pilha cheia
	}
	else{
		p->dados[p->topo] = A; //se não estiver cheia, dados irá receber o valor passado por parâmetro.
		p->topo = p->topo + 1;	// incrimento +1 em topo para indicar que possuo mais 1 elemento/mais 1 posição.
	}
}


int desempilha(estrutura_Pilha *p){ //criação da função que remove elementos
	if(p->topo == 0){ //se topo for 0, significa que não possui elementos.
		printf("Pilha vazia \n"); //imprime pilha vazia
	}
	else{
		p->topo = p->topo - 1; //retiro 1 do valor de topo, indicando -1 elemento/-1 posição.
		return p->dados[p->topo]; //retorno dados
	}
}

int imprimeTamanhoP(estrutura_Pilha *p){ //criação da função que imprime o tamanho da pilha
	printf("Tamanho: %d \n", p->topo); //topo indica o tamnho porque indica a posição atual de um vetor. Ou seja, se topo possui 2 posições ocupadas,o tamanho será esse.
	
}

int imprimeTopoP(estrutura_Pilha *p){ //criação da função que imprime o elemento que está no topo.
	if(p->topo != 0){ //topo precisa ser diferente de 0 para possuir elementos.
		printf("Topo: %d \n", p->dados[p->topo-1]);	//impfime o dado que está no topo.
	}
	else{
		printf("Topo: %d \n", p->topo);	 //se topo estiver vazio, vai retornar 0
	}
	free(p); //libera a memória.
}



//FILA



typedef struct // declarcao da struct de tipo definido
	{	
		int capacidade;// ccapcidade maxima da fila
		int *dados; // criar um ponteiro dados
		int primeiro; // primiero valor da fila
		int ultimo; // ultimo valor da fila
		int quantidade;// quantidade de elementos da fila
	}estrutura_Fila; //nome da estrutura  
	
	void criarFila(estrutura_Fila *f, int c)// funcao criar fila 
		{
			f->capacidade =c;// c que recebe parametro do main e atribuido a variavel capacidade
			f->dados = malloc(f->capacidade * sizeof(estrutura_Fila));// alocacao de memoria 
			f->primeiro = 0;// primeiro e inicalizado com 0
			f->ultimo = -1;// ultimo recebe -1
			f->quantidade =0;//quantdiade recebe 0
			
		}
		
		void inserirFinal(estrutura_Fila *f, int v){ // insere valor final na fila
	if(f->ultimo == f->capacidade-1)// condicao se ultimo é  igual a capacidade -1 
	f->ultimo = -1; // utlimo recebe -1
	f->ultimo++;// utimo e tribuido mais 1
	f->dados[f->ultimo]=v;// dados recebe valores como parametro 
	f->quantidade++;// quantidade recebe mais um sendo mais um elemento na fila
}


int removerComeco(estrutura_Fila *f){// funcao removo o comeco da fila
	int temp = f->dados[f->primeiro++];// declaracao e atrbuicao a variavel que recebe os dodos 
	if(f->primeiro == f->capacidade)// condicional se o primeiro for igual capacidade
	f->primeiro = 0;// primeiro recebe 0
	f->quantidade--;// quantidade e retirado -1
	return temp;// retornar o valor de temp
}


int mostrarFila(estrutura_Fila *f){// funcao mostrar fila 
	int cont, i;//contador
	for(cont=0,i=f->primeiro; cont < f->quantidade; cont++){//condicioanal se cont e memor que quantidade
		printf("%d\t", f->dados[i++]);// imprimir a tela variavel dados na posicao i
		if(i == f->capacidade)// comparacao se i eigual capacidade
		i = 0;//i = zerado
	}
	printf("\n");// pular linha
}



//LISTA


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


void retiraPos(estrutura_Lista* Lista, int p){ //criação da função que retira um elemento da posição escolhida 
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

//IMPRIMIR
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

//LISTA LIGADA


typedef struct nodo{
	int info;
	struct nodo *prox;
}Nodo;


//inicializacao
Nodo *iniciaLista(void){ 
	return NULL;
}

//imprimir

void imprimirL(Nodo* lista) {
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

//remover
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
  


//LISTA DUPALMENTE LIGADA


struct noListaDL{
	int valor;
	struct noListaDL *ant, *prox;
};

typedef struct noListaDL NOLISTADL;
typedef NOLISTADL *NOLISTAPTR;


//VEREFICAR SE A LISTA ESTA VAZIA
int vereficarVaziaL(NOLISTAPTR lista){
	return lista == NULL;
}

//FUNCAO INSERIR
void insereInicioL(NOLISTAPTR *inic, int valor){
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
void imprimirOrdemDiretaL(NOLISTAPTR lista){
	if(vereficarVaziaL(lista))
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
void imprimirOrdemInversaL(NOLISTAPTR lista){
	if(vereficarVaziaL(lista))
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

void insereFinalL(NOLISTAPTR *inic, int valor){
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
int removerL(NOLISTAPTR *inic, int valor){
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


//LISTA CIRCULAR

//define a estrutura do Nodo
struct nodoLC{
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

//CIRCULAR DUPLAMENTE ENCADEADA
struct nodoLCDL1{
	int indice;
	int quant;
	struct nodoLCDL1 *prox, *ant;
};
typedef struct nodoLCDL1 nodoTP1;
typedef nodoTP1 *nodoPTR1; 

int adicionaInicio1(nodoPTR1 lista, int ind, int val){
	
	nodoPTR1 novo;
	novo = (nodoPTR1)malloc(sizeof(nodoTP1)); //aloca memória para um novo nodo
	if(novo == NULL) //se não funcionar ele retorna 0 e sai
		return 0;
	
	novo->indice = ind; //o novo novo recebe um indice
	novo->quant = val; // recebe um valor 
	novo->prox = lista->prox; //o campo proximo pega o prox da lista
	novo->ant = lista; // o anterior recebe a lista 
	
	lista->prox = novo; // o prox da lista recebe o novo nodo
	(novo->prox)->ant = novo; // novo no atributo ant, no atributo prox recebe novo
	
	return 1; 
}

int adicionaOrdenado1(nodoPTR1 lista, int ind, int val){
	nodoPTR1 novo, aux;
	
	novo = (nodoPTR1)malloc(sizeof(nodoTP1));
	if(novo == NULL)
		return 0;
	
	novo->indice = ind; //atribuo indice
	novo->quant = val; //atribuo valor
	 
	 //localizando a posição onde devo inserir o nodo
	lista->indice = ind+1;
	//aux recebe o atributo prox da lista
	aux = lista->prox;
	while(aux->indice <= ind){ //enquanto o indice for menor do que o passado pelo usuario
		aux = aux->prox;
	}
	
	//ligações são as partes mais importantes.
	novo->prox = aux; //onde localizei
	novo->ant = aux->ant; //passo o ant para novo
	//pego aux como referencia, volto para o ant e a partir dai pego o prox
	aux->ant->prox = novo;//aux no seu campo anterior, no atributo prox recebe novo; O nodo ant tem um atributo proximo;
	aux->ant = novo; //ant de aux recebe o novo nodo

}


int buscarElemento1(nodoPTR1 lista, int ind){
	nodoPTR1 aux;
	
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

int remover1(nodoPTR1 lista, int ind){
	nodoPTR1 aux;
	
	lista->indice = ind; //recebo o indice
	aux = lista->prox; //recebo a lista no atributo prox
	
	while(aux->indice != ind){ //enquanto diferente
		aux = aux->prox; //vai se movimentando
	}
	
	if(aux == lista) //se for igual a lista, ele sai da função, pois não localizou
		return 0;
		
	else{
		aux->prox->ant = aux->ant; //aux no seu prox no atributo ant recebe aux ant;
		aux->ant->prox = aux->prox; // aux no seu ant no atributo prox recebe aux prox;
		free(aux); //libero a memória
		return 1;
	}
}
void imprimir1(nodoPTR1 lista){
	nodoPTR1 aux;
	aux = lista->prox; //a aux recebe o valor do prox nodo
	
	while(aux != lista){
		printf("\n ind: %d    qtd: %d", aux->indice, aux->quant); //imprimo os dois valores
		aux = aux->prox; //aux recebe prox para chegar até nulo
	}
}

void destroiLista1(nodoPTR1 *lista){
	int valor;
	nodoPTR1 atual = *lista;
	
	while(atual->prox != atual){
		valor = atual->prox->indice; //pego o valor do nodo atual prox no indice;
		remover1(atual, valor); //chamo a função remover para ir removendo cada valor encontrado;
	}
	free(atual); //libero memória;
	printf("\n Lista destruida!");
}




int  main(){
    setlocale(LC_ALL, "Portuguese");
    
   
   //PILHA
	estrutura_Pilha pilha1;
   //FILA
	estrutura_Fila fila1;	
	
    //LISTA SIMPLES
estrutura_Lista lista1; 

//LISTA DUPLA
NOLISTAPTR listax = NULL;

    //LISTA ENCADEADA
	Nodo *elem = NULL;
	iniciaLista();
	
	
	
	//LISTA CIRCULAR
nodoPTR lista = NULL;
lista = (nodoPTR)malloc(sizeof(nodoTP));
lista->prox = lista;
	
    //LISTA CIRCULAR DUPLAMENTE ENCADEADA
    nodoPTR1 listaC = NULL;
	listaC = (nodoPTR1)malloc(sizeof(nodoTP1)); 
	listaC->prox = listaC; 
	listaC->ant = listaC; 
    
    
    
    int op, ops;
    
    do{
        printf("----------------ESTRUTURAS DE DADOS --------------------");
        printf("\n Escolha uma opção");
        printf("\n 1 - Estrutura Pilha");
        printf("\n 2 - Estrutura Fila");
        printf("\n 3 - Estrutura Lista");
        printf("\n 4 - Estrutura Lista Encadeada");
        printf("\n 5 - Estrutura Lista Duplamente Encadeada");
        printf("\n 6 - Estrutura Lista Circular Encadeada");
        printf("\n 7 - Estrutura Lista Circular Duplamente Encadeada");
        printf("\n 8 - Sair \n");
        scanf("%d", &op);
        printf("\n");
        
        switch(op){
            case 1:
                do{
                     printf("----------------ESTRUTURAS DE DADOS PILHA --------------------");
                    printf("\n Escolha uma opção");
                    printf("\n 1 - Criar pilha: ");
                    printf("\n 2 - Empilhar: ");
                    printf("\n 3 - Desempilhar: ");
                    printf("\n 4 - Imprimir tamanho: ");
                    printf("\n 5 - Imprimir topo: ");
                    printf("\n 6 - Sair \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                            criaPilha(&pilha1, 17);
                            break;
                        case 2:
                            empilha(&pilha1, 68);
                            empilha(&pilha1, 72);
                            break;
                        
                        case 3:
                            desempilha(&pilha1);
                            break;
                        case 4:
                            imprimeTamanhoP(&pilha1);
                            break;
                        case 5:
                            imprimeTopoP(&pilha1);
                            break;
                        
                        case 6: 
                            printf("Encerrando aplicação...\n");
                            break;
                            
                        default:
                            printf("Opção inválida \n");
                            break;
                    }
                }while(ops != 6);
                break;
            
            case 2:
                    do{
                     printf("----------------ESTRUTURAS DE DADOS FILA -------------------- \n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Criar fila: ");
                    printf("\n 2 - Inserir no final: ");
                    printf("\n 3 - Remover do inicio: ");
                    printf("\n 4 - Mostrar fila:  ");
                    printf("\n 5 - Sair: \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                            criarFila(&fila1, 20);
                            break;
                        case 2:
                            inserirFinal(&fila1, 18); 
	                        inserirFinal(&fila1, 17); 
	                        inserirFinal(&fila1, 22); 
                            break;
                        
                        case 3:
                            removerComeco(&fila1);
                            break;
                        
                        case 4:
                            mostrarFila(&fila1);
                            break;
                            
                        case 5:
                        printf("Encerrando aplicação...\n");
                            break;
                            
                        default:
                            printf("Opção inválida \n");
                            break;
                    }
                }while(ops != 5);
                break;
                  
                case 3:
			do{
                printf("----------------ESTRUTURAS DE DADOS LISTA -------------------- \n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Criar lista: ");
                    printf("\n 2 - Inserir no Final: ");
                    printf("\n 3 - Imprimir Tamanho:");
                    printf("\n 4 - Consultar Lista: ");
                    printf("\n 5 - Imprimir Lista: ");
                    printf("\n 6 - Retirar Posicao: ");
                    printf("\n 7 - Sair: \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                        criaLista(&lista1, 10);
                        criaLista(&lista1, 20);
                        criaLista(&lista1, 30);
                        break;
                        
                        case 2:
                        insereFinal(&lista1, 40);
	                    insereFinal(&lista1, 50);
	                    break;
                        
                        case 3:
                            imprimeTamanho(&lista1);
                        break;
                        
                        case 4:
                            consultaLista(&lista1, 3);
                            break;
                        
                        case 5:
                        	imprimeLista(&lista1);
                        	break;
                        
                        case 6: 
                            retiraPos(&lista1, 2);
                            break;
                        
                        case 7:
                            printf("Encerrando aplicação...\n");
                            break;    
                            
                        default:
                            printf("Opção inválida");
                            break;
                    }
                }while(ops != 7);
                break;
           
                        
                      
                case 4:
            do{
                     printf("\n---------------ESTRUTURAS DE DADOS LISTA ENCADEADA -------------------- \n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Iserir Elemento na Lista Encadeada: ");
                    printf("\n 2 - Imprimir Elementos: ");
                    printf("\n 3 - Remover Elemento: ");
                    printf("\n 4 - Inserir Elemento entre 10 e 20: ");
                    printf("\n 5 - Imprimir Inverso: ");
                    printf("\n 6 - Sair: \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                            inserir(&elem, 10);
                            inserir(&elem, 20);
                            inserir(&elem, 30);
                            break;
                            
                        case 2:
                            imprimirL(elem);
                            break;
                        
                        case 3:
                            removerelemento(elem,20);
                            break;
                        
                        case 4:
                        	insereEntre(10,elem,20);
                        	break;
                        
                        case 5:
                        	inverter(&elem);
                        	imprimirL(elem);
                        	break;
                        
                        case 6:
                            printf("Encerrando aplicação...\n");
                            break;
                            
                        default:
                            printf("Opção inválida");
                            break;
                    }
            }while(ops != 6);
            break;
            
            case 5:
            do{
                    printf( "\n--------------ESTRUTURAS DE DADOS LISTA DUPLAMENTE ENCADEADA ------------------ \n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Inserir no Inicio: ");
                    printf("\n 2 - Imprimir em Ordem Direta:");
                    printf("\n 3 - Inserir no Final: ");
                    printf("\n 4 - Remover Elemento: ");
                    printf("\n 5 - Imprimir em ordem Inversa: ");
                    printf("\n 6 - Vereficar se esta Vazia: ");
                    printf("\n 7 - Sair: \n ");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                        //inserir inicio
                        	insereInicioL(&listax, 1);
                        	insereInicioL(&listax, 2);
                        	insereInicioL(&listax, 3);
                        	break;
                        
                        case 2:
                            imprimirOrdemDiretaL(listax);
                            break;
                        
                        case 3:
                                                	
                        	//INSERIR FINAL
                        	insereFinalL(&listax, 4);
                        	insereFinalL(&listax, 5);
                        	break;
                        
                        case 4:
                        	removerL(&listax, 3);
                        	break;
                        
                        case 5:
                        	imprimirOrdemInversaL(listax);
                        	break;
                        
                        case 6:
                        	//VERIFICAR SE ESTA VAZIA
                            	vereficarVaziaL(listax);
                            	break;
                        
                        case 7:
                            printf("Encerrando aplicação...\n");
                            break;
                        default:
                            printf("Opção inválida");
                            break;
                    }
                }while(ops != 7);
            
            break;
            case 6:
            do{
                    printf("\n----------------ESTRUTURAS DE DADOS LISTA CIRCULAR --------------------\n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Inserir no inicio: ");
                    printf("\n 2 - Inserir de forma ordenada: ");
                    printf("\n 3 - Buscar um elemento: ");
                    printf("\n 4 - Remover um elemento: ");
                    printf("\n 5 - Imprimir lista: ");
                    printf("\n 6 - Destruir lista: ");
                    printf("\n 7 - Sair: \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                            adicionarInicio(lista, 1, 10);
                            adicionarInicio(lista, 2, 20);
                            adicionarInicio(lista, 5, 30);
                            adicionarInicio(lista, 5, 40);
                            break;
                        case 2:
                            adicionarOrdenado(lista, 3, 50);
                            break;
                        case 3:
                            buscarElemento(lista, 5);
                            break;
                        case 4:
                            remover(lista, 2);
                            break;
                        case 5:
                        	imprimir(lista);
                        	break;
                        case 6: 
                            destroiLista(&lista);
                            break;
                        case 7:
                            printf("Encerrando aplicação...\n");
                            break;
                        default:
                            printf("Opção inválida \n");
                            break;
                    }
            }while(ops != 7);
                break;
                
            case 7:
            do{
                    printf("\n----------------ESTRUTURAS DE DADOS LISTA CIRCULAR DUPLAMENTE ENCADEADA-------------------\n");
                    printf("Escolha uma opção");
                    printf("\n 1 - Inserir no inicio: ");
                    printf("\n 2 - Inserir de forma ordenada: ");
                    printf("\n 3 - Buscar um elemento: ");
                    printf("\n 4 - Remover um elemento: ");
                    printf("\n 5 - Imprimir lista: ");
                    printf("\n 6 - Destruir lista: ");
                    printf("\n 7 - Sair: \n");
                    scanf("%d", &ops);
                    printf("\n");
                    
                    switch(ops){
                        case 1:
                            adicionaInicio1(listaC, 1, 10);
                            adicionaInicio1(listaC, 2, 20);
                            adicionaInicio1(listaC, 5, 30);
                            adicionaInicio1(listaC, 5, 40);
                            break;
                        case 2:
                            adicionaOrdenado1(listaC, 3, 50);
                            break;
                        case 3:
                            buscarElemento1(listaC, 5);
                            break;
                        case 4:
                            remover1(listaC, 2);
                            break;
                        case 5:
                        	imprimir1(listaC);
                        	break;
            
                         case 6: 
                            destroiLista1(&listaC);
                            break;
                        case 7:
                            printf("Encerrando aplicação...\n");
                            break;
                            
                        default:
                            printf("Opção inválida \n");
                            break;
                    }
            }while(ops != 7);
                break;
            case 8:
                printf("Encerrando aplicação...");
                break;
                
            default:
            printf("Opção inválida");
            break;
            
            
        }
    }while(op != 8);
    return 0;
}
