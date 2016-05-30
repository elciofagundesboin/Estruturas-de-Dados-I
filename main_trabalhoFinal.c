#include "trabalhoFinal.h"
#include "functions_trabalhoFinal.c"

int main(){
	
	int op, i, size;
	TpContato *dList = NULL; ///PONTEIRO PARA LISTA
	TpContato *dListCPY = NULL; //PONTEIRO PARA CÓPIA DE LISTA
	TpContato  sList[SIZE];	//VETOR PARA CONTATOS
	TpContato  sListCPY[SIZE]; //VETOR PARA CÓPIA
	clock_t t_init, t_point, t_end, t_result; //VARIÁVEIS DE TEMPO
	
	//MENU PRINCIPAL
	do{
		printf("--------------------------------------------");
		printf("\n\t\t\t\tTRABALHO NP2\n");
		printf("\n\tESCOLHA UMA OPCAO\n\n");
		printf("\t1 - CRIA LISTA\n");
		printf("\t2 - CRIA VETOR\n");
		printf("\t3 - GNOME SORT\n");
		printf("\t4 - MERGE SORT\n");
		printf("\t5 - SAIR\n");
		printf("\n\t6 - TEST GNOME \n");
		printf("\t7 - TEST MERGE\n");
		printf("\n\tOPCAO: ");
		scanf("%d", &op);
		
		switch(op){

			case 1: //CRIA LISTA DE CONTATOS ALEATÓRIOS CONFORME TAMANHO INFORMADO
				printf("\n\tINFORME O TAMANHO DA LISTA: ");
				scanf("%d", &size);

				for(i=0; i<size; i++){
					dList = creat_dList(dList);
				}

				printf("\nLISTA:\n");
				view_dList(dList);
			break;
			
			case 2://CRIA VETOR DE CONTATOS ALEATÓRIOS
				creat_sList(sList);
				printf("\nVETOR:\n");
				view_sList(sList);
			break;
			
			case 3: //ORDENA LISTA E VETOR POR GNOME SORT E CALCULA TEMPO DE EXECUÇÃO
				dListCPY = copy_dList(dList, dListCPY);	//FAZ A CÓPIA DA LISTA
				copy_sList(sList, sListCPY);	//FAZ A CÓPIA DO VETOR
				
				t_init = clock();
//IMPLEMENTAR	dListCPY = gnomeDinamic(dListCPY);	//ORDENA A CÓPIA DA LISTA
				t_point = clock();				
//IMPLEMENTAR	gnomeStatic(sListCPY);	//ORDENA A CÓPIA DO VETOR
				t_end = clock();
				
				printf("\nGNOME SORT LISTA:\n");
				view_dList(dListCPY);
				t_result = ((t_point - t_init)*1000)/CLOCKS_PER_SEC;	//TEMPO DE EXECUÇÃO EM SEGUNDOS
				printf("TEMPO GNOME EM LISTA: %ld SEGUNDOS\n",  t_result);

				printf("\nGNOME SORT VETOR:\n");
				view_sList(sListCPY);
				t_result = ((t_end - t_point)*1000)/CLOCKS_PER_SEC;	//TEMPO DE EXECUÇÃO EM SEGUNDOS
				printf("TEMPO GNOME EM VETOR: %ld SEGUNDOS\n",  t_result);
			break;
			
			case 4:	// ORDENA LISTA E VETOR POR MERGE SORT E CALCULA TEMPO DE EXECUÇÃO
				dListCPY = copy_dList(dList, dListCPY); //FAZ A CÓPIA DA LISTA
				copy_sList(sList, sListCPY);	//FAZ A CÓPIA DO VETOR
				
				t_init = clock();
//IMPLEMENTAR	dListCPY = mergeDinamic(dListCPY); //ORDENA A CÓPIA DA LISTA
				t_point = clock();
//------------------------------------------------------------------------------------------------------------------------------
				mergeStatic(sListCPY, 0, 9); //ORDENA A CÓPIA DO VETOR
//------------------------------------------------------------------------------------------------------------------------------
				t_end = clock();

				printf("\nMERGE SORT LISTA:\n");
				view_dList(dListCPY); 
				t_result = ((t_point - t_init)*1000)/CLOCKS_PER_SEC; //TEMPO DE EXECUÇÃO EM SEGUNDOS
				printf("TEMPO MERGE EM LISTA: %ld SEGUNDOS\n",  t_result);

				printf("\nMERGE SORT VETOR:\n");
				view_sList(sListCPY);
				t_result = ((t_end - t_point)*1000)/CLOCKS_PER_SEC;	//TEMPO DE EXECUÇÃO EM SEGUNDOS
				printf("TEMPO MERGE EM VETOR: %ld SEGUNDOS\n",  t_result);
			break;
		
			case 5: // FINALIZA PROGRAMA
				exit(1);
			break;

			case 6: //CASE TEST GNOME 
			
			break;
			
			case 7:	//CASE TEST MERGE
				
			break;
			
			default:
				printf("\n\tOPCAO INVALIDA");
			break;
		}
		
	}while(1);	//LAÇO INFINITO

	return 0;
	
}
