#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no *esq;
	struct no *dir;
	int valor;	
}no;

void inserirNo (no **raiz, int elemento){
	if(*raiz == NULL){
		no *aux = (no*)malloc(sizeof(no));
		aux->valor = elemento;
		aux->dir = NULL;
		aux->esq = NULL;
		*raiz = aux;
		return;
	}
	if(elemento < (*raiz)->valor){
		inserirNo(&(*raiz)->esq,elemento);
		return;
	}
	if(elemento > (*raiz)->valor){
		inserirNo(&(*raiz)->dir,elemento);
		return;
	}
	printf("Elemento %d já existe. \n",elemento);
}

int main(){
	no *raiz = NULL;
	
	inserirNo(&raiz,10);
	inserirNo(&raiz,10);
	inserirNo(&raiz,55);
	
	return 0;	
}
