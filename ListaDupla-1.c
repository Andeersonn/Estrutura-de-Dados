#include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct noListaDL{
	char aluno[10];
	float nota1;
	float nota2;
	float quiz;
	float media;
	struct noListaDL *ant, *prox;
};

typedef struct noListaDL NOLISTADL;
typedef NOLISTADL *NOLISTAPTR;

void inserir(NOLISTAPTR *inic, char aluno[], float nota1, float nota2, float quiz){
NOLISTAPTR novo;
novo = (NOLISTAPTR)malloc(sizeof(NOLISTADL));

if(novo == NULL)
	return;
	if(*inic == NULL){
	strcpy(novo->aluno, aluno);
		novo->nota1 = nota1;
		novo->nota2 = nota2;
		novo->quiz = quiz;
		novo->prox = novo->ant = NULL;
		*inic = novo;
	}else{
	strcpy(novo->aluno, aluno);
		novo->nota1 = nota1;
		novo->nota2 = nota2;
		novo->quiz = quiz;
		novo->ant = NULL;
		novo->prox = *inic;
		(*inic)->ant = novo;
		*inic = novo;
	}
	novo->media = (novo->nota1+novo->nota2+novo->quiz)/3;
		printf("\n=============== ALUNO ===================\n");
	printf("\nInserido o ALUNO: %s \n",aluno);
	printf("nota 1: %.2f \n",nota1);
	printf("nota 2: %.2f \n",nota2);  
	printf("quiz: %.2f \n ",quiz);
	printf("A Media do Aluno foi: %.2f \n",novo->media);
	printf("\n==========================================\n");
	
}

int main(){
	NOLISTAPTR lista = NULL;

	inserir(&lista,"Anderson", 10, 9, 6);
	inserir(&lista,"Bells", 5, 3, 2);
	
	
	
	
	
	return 0;
	
}
