#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 10	//MUDAR PARA QUARENTA ANTES DA ENTREGA

//ESTRUTURA DOS DADOS SUGERIDA NO TRABALHO
typedef struct _contato{
	char nome[40];
	char fone[30];
	struct _contato *next;	//PONTEIRO PARA LIGAR A LISTA
	struct _contato *prev;	//PONTEIRO PARA LIGAR A LISTA
}TpContato;

//PROTÓTIPOS DAS FUNÇOES
void pause(void);
void view_dList(TpContato *dList); 
void view_sList(TpContato sList[]);
TpContato *creat_dList(TpContato *dList);
TpContato *creat_sList(TpContato sList[]);
TpContato *copy_dList(TpContato *dList, TpContato *dListCPY);
TpContato *copy_sList(TpContato sList[], TpContato sListCPY[]);

////////IMPLEMENTAR//////////
void *gnomeStatic();
void *gnomeDinamic();
TpContato *mergeStatic(TpContato *vetor, int posicaoInicio, int posicaoFim);
void *mergeDinamic();
