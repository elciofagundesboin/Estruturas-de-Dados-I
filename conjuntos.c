#include <stdio.h>
#include <stdlib.h>

//ESTRUTURA DOS ELEMENTOS DOS CONJUNTOS
typedef struct _node{
	int info;
	struct _node *next;
	struct _node *prev;
}node;

//ESTRUTURA DOS INDICES DOS CONJUNTOS
typedef struct _index{
	int id;
	node *group;
	struct _index *next;
	struct _index *prev;
}index;

//CONTROLE DE FLUXO
void pause(){
	printf("\n\tPRESSIONE QUALQUER TECLA...");
	getchar();
	getchar();
	//printf("\n\t");
	//system("pause");
}

//MOSTRA GRUPOS NA TELA
void view_groups(index *id){
	
	index *aux_id = id;
	node *aux_group;
	
	if (!aux_id){
		printf("\n\tNAO EXISTE CONJUNTOS ALOCADOS\n\t");
	}
	
	printf("\n");
	while(aux_id){		
		printf("\tCONJUNTO %d: {", aux_id->id);
		
		if(aux_id->group){
			aux_group = aux_id->group;
			while(aux_group){
				printf("%d", aux_group->info);
				if(aux_group->next){
					printf(", ");
				}else{
					printf("}");
				}
				aux_group = aux_group->next;
			}
			
		}else{
			printf(" VAZIO }");
		}
		
		printf("\n");
		aux_id = aux_id->next;
	}
	printf("\n\t");
	pause();
	
}

//REMOVE UM GRUPO INTEIRO
index *delete_group(index *id, int ref){
	
	index *aux_id = id; 
	index *previous = aux_id->prev;
	
	//LAÇO PARA ENCONTRAR O VALOR A DELETAR
	while(aux_id && aux_id->id != ref){
		previous = aux_id;
		aux_id = aux_id->next;
		if(!aux_id->next && aux_id->id != ref){
			printf("\n\tCONJUNTO INEXITENTE\n\t");
			pause();
			return id;
		}
	}
	
	//REMOÇÃO CASO SEJA SO UM GRUPO
	if(!aux_id->next && !aux_id->prev){
		free(aux_id->group);
		free(aux_id);
		return NULL;
	}
	
	//REMOÇÃO CASO SEJA O ULTIMO
	if(!aux_id->next && aux_id->prev){
		previous->next = NULL;
		free(aux_id->group);
		free(aux_id);
		return id;
	}
	
	//REMOÇÃO CASO SEJA O PRIMEIRO
	if(aux_id->next && !aux_id->prev){
		free(aux_id->group);
		aux_id = aux_id->next;
		free(aux_id->prev);
		aux_id->prev = NULL;
		aux_id->id--;
		previous = aux_id;
	}else{//REMOÇÃO NO MEIO DA LISTA
		free(aux_id->group);
		aux_id = aux_id->next;
		previous->next = aux_id;
		free(aux_id->prev);
		aux_id->prev = previous;
	}
	
	//LAÇO DE DECREMENTO DO ID;
	while(previous->next){
		previous = previous->next;
		previous->id--;
	}

	return id;
	
}

//ADICIONA UM NOVO GRUPO
index *add_gr(index *id){
	
	index *new_id = (index *)malloc(sizeof(index));
	if(!new_id){
		printf("\nERRO DE ALOCACAO\n");
		return id;
	}
	
	if(!id){
		
		new_id->id = 1;
		new_id->next = NULL;
		new_id->prev = NULL;
		new_id->group = NULL;
		return new_id;
	
	}else{
			
		index *aux_id = id;
			
		while(aux_id->next){
			aux_id = aux_id->next;
		}
			
		aux_id->next = new_id;
		new_id->id = aux_id->id;
		new_id->id++;
		new_id->next = NULL;
		new_id->prev = aux_id;
		new_id->group = NULL;
		
		return id;
		
	}

}

//ADICIONA ELEMENTOS EM UM GRUPO
index *add_info(index *id, int ref, int info){
	
	index *aux_id = id;
	node *aux_group;
	
	node *new = (node *)malloc(sizeof(node));
	if(!new){
		printf("\nERRO DE ALOCACAO");
		pause();
		return id;
	}
	
	new->info = info;
	new->next = NULL;
	
	while(aux_id->next && aux_id->id != ref){
		aux_id = aux_id->next;
		if(!aux_id->next && aux_id->id != ref ){
			printf("\n\tCONJUNTO NAO ENCONTRADO");
			pause();
			return id;
		}
	}
	
	if(!aux_id->group){
		aux_id->group = new;
		new->prev = aux_id->group;
		return id;
	}else{
		aux_group = aux_id->group;
		
		while(aux_group->next){
			aux_group = aux_group->next;
		}
		
		aux_group->next = new;
		new->prev = aux_group;
		
		return id;

	}
	
}

//APAGA ELEMENTOS EM UM GRUPO
index *del_info(index *id, int ref, int valor){
	
	index *aux_id = id;
	node *aux_group = NULL;
	node *previous = NULL;
	//ENCONTRA O GRUPO SELECIONANDO
	while(aux_id && aux_id->id != ref){
		aux_id = aux_id->next;
	}

	aux_group = aux_id->group;
	
	//VERIFICA SE HÁ ELEMENTOS NO GRUPO
	if(!aux_group){
		printf("\n\tGRUPO VAZIO!\n\t");
		pause();
		return id;
	}

	//ENCONTRA O VALOR SELECIONADO
	while(aux_group && aux_group->info != valor){

		if(!aux_group->next && aux_group->info != valor){
			printf("\n\tVALOR NAO ENCONTRADO\n\t");
			pause();
			return id;
		}

		aux_group = aux_group->next;
		previous = aux_group->prev;
	}
	
	//REMOVE SE EXISTIR SÓ UM ELEMENTOS
	if(!aux_group->prev && !aux_group->next){
		aux_id->group = NULL;
		free(aux_group);
		return id;
	}
	
	//REMOVE NO FIM
	if(aux_group->prev && !aux_group->next){
		previous->next = NULL;
		free(aux_group);
		return id;
	}
	//REMOVE NO INICIO
	if(!aux_group->prev && aux_group->next){
		previous->next = aux_group->next;
		free(aux_group);
		previous->prev = NULL;
		return id;
	}
	
	//REMOVE NO MEIO
	if(aux_group->prev && aux_group->next){
		previous->next = aux_group->next;
		aux_group = aux_group->next;
		free(aux_group->prev);
		aux_group->prev = previous;
		return id;
	}
}

//RETORNA A QUANTIDADE DE GRUPOS ALOCADOS
int qtd_groups(index *id){
	
	index *aux_id = id;
	
	if(!aux_id){
		return 0;
	}else{
		while(aux_id->next){
			aux_id = aux_id->next;
		}
		return aux_id->id;
	}
	
}

//RETORNA 1 CASO SEJA POSSIVEL AÇÃO EM UM CONJUNTO
int search_elem(index *id, int ref){
	
	index *aux_id = id;
	
	while(aux_id->next && aux_id->id != ref){
		aux_id = aux_id->next;
	}
	
	if(ref > aux_id->id || ref <= 0){
		printf("\n\tCONJUNTO INEXISTENTE");	
		pause();
		return 0;
	}
	
	if(!aux_id->next && aux_id->id != ref){
		printf("\n\tCONJUNTO NAO ENCONTRADO");	
		pause();
		return 0;
	}
	
	return 1;
}

//RETORNA UMA LISTA DUPLA COM VALORES INFORMADOS
node *creat_List(node *result_group, int info){
	
	node *aux_result = result_group;

	node *new = (node *)malloc(sizeof(node));
	if(!new){
		printf("\nERRO DE ALOCACAO");
		pause();
		return new;
	}
	
	new->info = info;
	new->next = NULL;
		
	if(!result_group){
		new->prev = NULL;
		return new;
	}
	
	while(aux_result->next){
		aux_result = aux_result->next;
	}
	
	aux_result->next = new;
	new->prev = aux_result;

	return result_group;
	
}

//CRIA A UNIAO DE TODOS CONJUNTOS
void union_group(index *id){
	
	index *aux_id = id;
	node *union_gr = NULL;	
	node *aux_group = NULL;
	
	while(aux_id){
		aux_group = aux_id->group;
		
		while(aux_group){
			union_gr = creat_List(union_gr, aux_group->info);
			aux_group = aux_group->next;
		}
		
		aux_id = aux_id->next;
	}

	aux_group = union_gr;

	node *info_free;
	node *aux_prev;

	do{
		info_free = aux_group->next;
		aux_prev = info_free->prev;
		
		do{

			if(aux_group->info != info_free->info){
				aux_prev = info_free;
				info_free = info_free->next;
			}else{
				aux_prev->next = info_free->next;
				if(aux_prev->next){
					free(info_free);
					info_free = aux_prev->next;
					info_free->prev = aux_prev->next;
				}else{
					aux_prev->next = NULL;
					free(info_free);
					info_free = NULL;
				}
			}
	
		}while(info_free);
		
		aux_group = aux_group->next;
		
	}while(aux_group->next);
	
	aux_group = union_gr;
	printf("\n\tUNIAO: {");
	do{
		printf("%d", aux_group->info);
		if(!aux_group->next){
			printf("}\n");
		}else{
			printf(", ");
		}
		aux_group = aux_group->next;
	}while(aux_group);
	pause();
	
	
}

//CRIA INTERSECÇÃO DE TODOS CONJUNTOS
void intersection_group(index *id){
	
	index *aux_id = id;
	node *union_gr = NULL;	
	node *aux_group = NULL;
	
	while(aux_id){
		
		aux_group = aux_id->group;
		while(aux_group){
			union_gr = creat_List(union_gr, aux_group->info);
			aux_group = aux_group->next;
		}
		
		aux_id = aux_id->next;
	}
	
	aux_group = union_gr;
	
	node *inter_gr = NULL;
	node *aux_inter = NULL;
	node *aux_next = aux_group->next;	
	int flag = 0;
	
	do{
		
		do{

			if(aux_group->info != aux_next->info){
				aux_next = aux_next->next;
			}else{
				if(!aux_inter){
					inter_gr = creat_List(inter_gr, aux_group->info);
					aux_inter = inter_gr;
				}else{
					flag = 0;
					aux_inter = inter_gr;
					while(aux_inter){
						if(aux_inter->info != aux_group->info){
							aux_inter = aux_inter->next;
						}else{
							flag = 1;
						}
					}
					if(!flag){
						inter_gr = creat_List(inter_gr, aux_group->info);	
					}
				}
				aux_next = aux_next->next;
			}
		}while(aux_next);
		
		aux_group = aux_group->next;
		aux_next = aux_group->next;
	}while(aux_group->next);
	
	aux_inter = inter_gr;
	printf("\n\tINTERSECCAO: {");
	do{
		printf("%d", aux_inter->info);
		if(!aux_inter->next){
			printf("}\n");
		}else{
			printf(", ");
		}
		aux_inter = aux_inter->next;
	}while(aux_inter);
	pause();
	
	
}

//MENU PRINCIPAL
int main(){

	int op, ref, info, num, i;
	index *id;
	id = NULL;
	
	do{
		system("clear");
		//system("cls");
		//fflush(stdin);
		printf("\n\tTRABALHO NP1 - CONJUNTOS EM ALOCACAO DINAMICA\n\n");
		printf("\n\tESCOLHA UMA OPCAO\n\n");
		printf("\t1 - INSERIR CONJUNTO\n");
		printf("\t2 - REMOVER CONJUNTO\n");
		printf("\t3 - INSERIR ELEMENTOS NO CONJUNTO\n");
		printf("\t4 - REMOVER ELEMENTOS NO CONJUNTO\n");
		printf("\t5 - VISUALIZAR CONJUNTOS\n");
		printf("\t6 - UNIAO\n");
		printf("\t7 - INTERSECCAO\n");
		//printf("\t8 - DIFERENCA\n\n\t");
		printf("\t0 - FECHAR");
		printf("\t\t\t\tCONJUNTOS ALOCADOS: %d\n", qtd_groups(id));
		printf("\n\tOPCAO: ");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				exit(1);
			break;
				
			case 1:
				id = add_gr(id);
			break;
			
			case 2:
			
				if(!id){
					printf("\n\tNENHUM CONJUNTO ALOCADO");
					pause();					
				}else{
					printf("\n\tSELECIONE O CONJUNTO: ");
					scanf("%d", &ref);
					if(search_elem(id, ref)){
						id = delete_group(id, ref);
					}
				}
				
			break;
			
			case 3:
			
				if(!id){
					printf("\n\tNENHUM CONJUNTO ALOCADO");
					pause();					
				}else{
					printf("\n\tSELECIONE O CONJUNTO: ");
					scanf("%d", &ref);
					if(search_elem(id, ref)){
						
						printf("\tQUANTIDADE DE VALORES A INSERIR: ");
						scanf("%d", &num);
						printf("\n");
						
						for(i=0; i<num; i++){
							printf("\tVALOR: ");
							scanf("%d", &info);		
							id = add_info(id, ref, info);
						}
						
					}
				}
				
			break;
			
			case 4:
				
				if(!id){
					printf("\n\tNENHUM CONJUNTO ALOCADO");
					pause();					
				}else{
					printf("\n\tSELECIONE O CONJUNTO: ");
					scanf("%d", &ref);
					if(search_elem(id, ref)){
						
						printf("\n\tVALOR: ");
						scanf("%d", &info);
						id = del_info(id, ref, info);
						
					}
				}
				
			break;
		
			case 5:
				view_groups(id);
			break;
			
			case 6:
				
				if(qtd_groups(id) >= 2){
					union_group(id);
				}else{
					printf("\n\tINSIRA NO MINIMO 2 CONJUNTOS");
					pause();
				}
				
			break;
			
			case 7:
			
				if(qtd_groups(id) >= 2){
					intersection_group(id);
				}else{
					printf("\n\tINSIRA NO MINIMO 2 CONJUNTOS");
					pause();
				}
				
			break;
			
			default:
				printf("\n\tOPCAO INVALIDA");
				pause();
			break;
		}
		
	}while(op);

	return 0;
	
}
