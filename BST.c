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

no* buscaNo(no **raiz, int elemento){
	if(*raiz == NULL || (*raiz)->valor == elemento){
		return *raiz;
	}else{
		if(elemento<(*raiz)->valor){
			buscaNo(&(*raiz)->esq, elemento);	
		}else{
			return buscaNo(&(*raiz)->dir, elemento);	
		}	
	}
}

no* minimo(no **raiz){
	no *aux = (no*)malloc(sizeof(no));
	aux=*raiz;
	while(aux->esq != NULL){
		aux = aux->esq;
	}
	return aux;
}

no* maximo(no **raiz){
	no *aux = (no*)malloc(sizeof(no));
	aux=*raiz;
	while(aux->dir != NULL){
		aux = aux->dir;
	}
	return aux;
}

int main(){
	no *raiz = NULL;
	
	inserirNo(&raiz,10);
	inserirNo(&raiz,10);
	inserirNo(&raiz,55);
	
	return 0;	
}
