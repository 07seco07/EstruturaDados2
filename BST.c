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

void imprimirPreOrder(no **raiz){
	no *aux = *raiz;
	if(aux != NULL){
		printf("%d ", aux->valor);
		if(aux->esq != NULL) imprimirPreOrder(&(aux)->esq);
		if(aux->dir != NULL) imprimirPreOrder(&(aux)->dir);
	}else{
		printf("Arvore Vazia!\n");
	}
}

void imprimirInOrder(no **raiz){
	no *aux = *raiz;
	if(aux != NULL){
		if(aux->esq != NULL) imprimirInOrder(&(aux)->esq);
		printf("%d ", aux->valor);
		if(aux->dir != NULL) imprimirInOrder(&(aux)->dir);
	}else{
		printf("Arvore Vazia!\n");
	}
}

void imprimiPosOrder(no **raiz){
	no *aux = *raiz;
	if(aux != NULL){
		if(aux->esq != NULL) imprimiPosOrder(&(aux)->esq);
		if(aux->dir != NULL) imprimiPosOrder(&(aux)->dir);
		printf("%d ", aux->valor);
	}else{
		printf("Arvore Vazia!\n");
	}
}



int main(){
	no *raiz = NULL;
	
	inserirNo(&raiz,10);
	inserirNo(&raiz,10);
	inserirNo(&raiz,55);
	
	return 0;	
}
