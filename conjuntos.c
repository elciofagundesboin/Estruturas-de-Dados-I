#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int info;
	struct _node *next;
	struct _node *prev;
}node;

typedef struct _index{
	int id;
	node *group;
	struct _index *next;
	struct _index *prev;
}index;

void pause(){
	printf("\n\tPRESSIONE QUALQUER TECLA...");
	getchar();
	getchar();
}

void view_groups(index *id){
	
	index *aux_id = id;
	node *aux_group;
	
	if (!aux_id){
		printf("\n\tNAO EXISTE CONJUNTOS ALOCADOS\n\t");
	}
	
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


index *delete_group(index *id, int ref){
	
	index *aux_id = id; 
	index *previous = NULL;
	node *aux_group = aux_id->group; 

	while(aux_id->next || aux_id->id != ref){
		previous = aux_id;
		aux_id = aux_id->next;
		if(!aux_id->next && aux_id->id != ref){
			printf("\n\tCONJUNTO INEXITENTE\n\t");
			pause();
			return id;
		}
	}
	
	if(!aux_id->next && !aux_id->prev){
		free(aux_group);
		free(aux_id);
		return NULL;
	}else{
		previous->next = aux_id->next;
		aux_id->next = previous;
		free(aux_group);
		free(aux_id);
	}
	
	while(previous->next){
		previous = previous->next;
		previous->id--;
	}
	
	return id;
	
}


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

index *del_info(index *id, int ref, int info){
	
	index *aux_id = id; 
	node *previous;
	node *aux_group;

	while(aux_id->next || aux_id->id != ref){
		aux_id = aux_id->next;
	}
	printf("%d\n", info);
	printf("Chegou Aqui!!!    ");
	printf("%d\n", aux_id->id);
	aux_group = aux_id->group;
	printf("Info: %d\n", aux_group->info);

	while(aux_group->next || aux_group->info != info){
		previous = aux_id->group;
		aux_group = aux_group->next;
		printf("%d\n", aux_group->info);
		printf("Aqui Tambem!\n");
		if(!aux_group->next && aux_group->info != info){
			printf("\n\tVALOR NAO ENCONTRADO\n\t");
			pause();
			return id;
		}

	}
	
	if(!aux_group->next && !aux_group->prev){
		aux_id->group = NULL;
		free(aux_group);
	}else{
		previous->next = aux_group->next;
		//aux_group = aux_group->next;
		//aux_group->prev = previous;
		aux_group->next = previous;
		free(aux_group);
	}
	
	return id;

	/*
	index *aux_id = id;
	node *aux_group;
	node *previous_group = NULL;

	
	while(aux_id->next || aux_id->id != ref){
		aux_id = aux_id->next;
	}

	aux_group = aux_id->group;

	while(aux_group->next || aux_group->info != info){
		previous_group = aux_group;
		aux_group = aux_group->next;
	}
	
	//previous_group->next = aux_group->next;
	//aux_group->next = previous_group;
	aux_group->info = 0;

	pause();
	
	//free(aux_group);
	
	return id;
	*/
}

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
		printf("\t0 - FECHAR");
		printf("\t\t\tCONJUNTOS ALOCADOS: %d\n", qtd_groups(id));
		printf("\n\tOPCAO: ");
		//printf("\t5 - INTERSECCAO\n");
		//printf("\t6 - UNIAO\n");
		//printf("\t7 - DIFERENCA\n\n\t");
		scanf("%d", &op);
		printf("\n");
		
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
						printf("Excluir: %d\n", info);
						id = del_info(id, ref, info);
						
					}
				}
				
				
			break;
		
			case 5:
				view_groups(id);
			break;
			
			case 6:
				
			break;
			
			case 7:
				
			break;
			
			default:
				printf("\n\tOPCAO INVALIDA");
				pause();
			break;
		}
		
	}while(op);

	return 0;
	
}
