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

no removerNo(no **raiz, int elemento){
	no* x = *raiz;
	no *aux, *pai;
	int valor;
	if(x == NULL){
		printf("Valor nao encontrado! \n");
		return **raiz;
	}
	if(x->valor == elemento){
		if(x->esq != NULL){
			aux = x->esq;
		}
		if(aux->dir != NULL){
			while(aux->dir != NULL) aux = aux->dir;
			pai = x->esq;
			while(pai->dir != aux) pai=pai->dir;
			valor=aux->valor;
			free(aux);
			pai->dir=NULL;
			x->valor=valor;
			return *x; 
		}else{
			x->valor = aux->valor;
			x->esq = aux->esq;
			free(aux);
			return *x;
		}
		if(aux->esq != NULL){
		aux= aux->dir;
		if(aux->esq != NULL){
			while(aux->esq != NULL) aux = aux->esq;
			pai = x->dir;
			while(pai->esq != aux) pai=pai->esq;
			valor=aux->valor;
			free(aux);
			pai->esq=NULL;
			x->valor=valor;
			return *x;
		}else{
			x->valor = aux->valor;
			x->dir = aux->dir;
			free(aux);
			return *x;
		}		
		}
	}
	if(x->valor > elemento){
		*x->esq = removerNo( &(x)->esq, elemento);
	}
	if(x->valor > elemento){
		*x->dir = removerNo(&(x)->dir, elemento);
	}
	return **raiz;
}


int main(){
	no *raiz = (no*)malloc(sizeof(no));
	raiz = NULL;
	no *aux;
	int x=1,y;
	while(x!=0){
		printf("-------ARVORE DE BUSCA BINARIA---------------\n");
		printf("0 SAIR\n");
		printf("1 INSERIR\n");
		printf("2 DELETAR\n");
		printf("3 BUSCAR\n");
		printf("4 IMPRIMIR\n");	
		printf("5 MAIOR NO \n");
		printf("6 MENOR NO \n");	
		printf("---------------------------------------------\n");
		scanf("%d",&x);
		
		if(x==0){
			break;
		}
		if(x==1){
			printf("Informe o elemento para Insercao: \n");
			scanf("%d",&y);
			inserirNo(&raiz,y);
		}
		if(x==2){
			printf("Informe o elemento para Delecao: \n");
			scanf("%d",&y);
			removerNo(&raiz, y);
		}
		if(x==3){
			printf("Informe o elemento para Busca: \n");
			scanf("%d",&y);
			buscaNo(&raiz, y);
		}
		if(x==4){
			printf("-------INFORME FORMA DE IMPRESSAO------------\n");
			printf("0 SAIR\n");
			printf("1 PRE ORDER\n");
			printf("2 IN ORDER\n");
			printf("3 POS ORDER\n");	
			printf("---------------------------------------------\n");
			scanf("%d",&x);
			if(x==1){
				imprimirPreOrder(&raiz);	
			}
			if(x==2){
				imprimirInOrder(&raiz);
			}
			if(x==3){
				imprimiPosOrder(&raiz);
			}
		}
		if(x==5){
			aux=maximo(&raiz);
			printf("MAIOR NO : %d \n",aux->valor);
		}
		if(x==6){
			aux=minimo(&raiz);
			printf("MENOR NO : %d \n",aux->valor);
		}	
	}
	return 0;
}
