# include <stdio.h>
# include <stdlib.h>


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



int main(){// funcao principal

	estrutura_Fila fila1;// delcarcao da funcao
	
	criarFila(&fila1, 20);// chamada da funcao criar fila recbendo capacidade 20
	inserirFinal(&fila1, 18);// inserir valor no final da fila 18 como parametro
	inserirFinal(&fila1, 17);// inserir valor no final da fila 17 como parametro
	inserirFinal(&fila1, 22);// inserir valor no final da fila 22  como parametro
	removerComeco(&fila1);// remove o comeco da fila 
	mostrarFila(&fila1);// mostra fila 
	
return 0;// retornar 0;

}
