#include <stdio.h>
#include <stdlib.h>

// Tipo do Nodo:
typedef struct _node{
     int info;
     struct _node *next;
     struct _node *prev;
}node;

typedef struct _tipoLista{
	struct tipoLista *ant;
    struct tipoLista *prox;
	struct node *init;
	int numConjunto;
}tipoLista;

// Inicializa
tipoLista* inicializa(){
	return NULL;
}
// Insere:
tipoLista* adicionaConjunto(tipoLista *lista){
	tipoLista* aux;
	aux = (tipoLista*)malloc(sizeof(tipoLista));
	aux->init = NULL;
	aux->ant = lista->prox;
	aux->prox = NULL;
	
	return aux;
}

// Verifica a quantidade de conjuntos existentes:

//	no = (node*)malloc(sizeof(node)); 

//	tpLista->init = no;

// FUNÇÃO PRINCIPAL:
int main(){
	tipoLista* lista = NULL;
	node* no = NULL;
	int escolhaMenu, i;
	
	lista = inicializa();
	
	do{
		printf("Escolha uma opção:\n");
		
		printf("1 - Adicionar conjunto.\n");
		printf("2 - Excluir conjunto.\n");
		printf("3 - Alterar conjunto (inserir ou remover elementos em um conjunto).\n");
		printf("4 - Exibir Intersecção.\n");
		printf("5 - Exibir União.\n");
		printf("6 - Exibir Diferença.\n");
		printf("0 - Sair\n");
		scanf("%d", &escolhaMenu);
		
		switch(escolhaMenu){
			case 0:
			break;
			case 1:
				// adiciona conjunto:
				lista = adicionaConjunto(lista);
			break;
			case 2:
				printf("Informe o conjunto desejado:\n");
				printf("Conjuntos disponiveis: %d. -", i);
				scanf("%d", &escolhaMenu);
			default:
				printf("Opcao invalida!\n\n");
		}
	}while(escolhaMenu!=0);
	return 0;
}