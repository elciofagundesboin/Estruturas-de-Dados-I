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


void view_groups(index *id){
	
	index *aux_id = id;
	node *aux_group;
	
	while(aux_id){
		
		printf("\tCONJUNTO %d: {", aux_id->id);
		
		if(aux_id->group){
			aux_id->group = aux_group;
			while(aux_group->next){
				printf("%d, ", aux_group->info);
				aux_group = aux_group->next;
			}
			
		}else{
			
			printf(" VAZIO ");
			
		}
		printf("}\n");
		aux_id = aux_id->next;
	}
	printf("\n\t");
	getchar();
	
}


index *delete_group(index *id, int ref){//LACO INFINITO
	
	index *previous = NULL;
	index *aux_id = id;
	
	if (!aux_id){
		
		printf("\n\tNAO EXISTE CONJUNTOS ALOCADOS\n\t");
		getchar();
		return id;
		
	}
	
	while(aux_id && aux_id->id != ref){
		previous = aux_id;
		aux_id = aux_id->next;
	}
	
	if (!previous){

		printf("0 AUX: %d\n", aux_id->id);
		//printf("AUX : %d\n", previous->id);

		previous = aux_id->next;
		printf("1 AUX: %d\n", aux_id->id);
		printf("2 AUX : %d\n", previous->id);
		previous->prev = NULL;
		printf("3 AUX: %d\n", aux_id->id);
		printf("4 AUX : %d\n", previous->id);
		free(aux_id);
		printf("5 AUX: %d\n", aux_id->id);
		printf("6 AUX : %d\n", previous->id);
		
		while(previous->next){
			previous = previous->next;
			previous->id--;
		}
		printf("7 AUX: %d\n", aux_id->id);
		printf("8 AUX : %d\n", previous->id);
		
		getchar();
		return id;
		
	}else{
		
		previous->next = aux_id->next;
		printf("9 AUX: %d\n", aux_id->id);
		printf("10 PREV : %d\n", previous->id);
		aux_id->prev = previous;
		printf("11 AUX: %d\n", aux_id->id);
		printf("12 PREV : %d\n", previous->id);
		
		getchar();
		
	}
	
	free(aux_id);
	
	while(previous->next){
		previous = previous->next;
		printf("AUX: %d\n", aux_id->id);
		printf("PREV : %d\n", previous->id);
		previous->id--;
		printf("AUX: %d\n", aux_id->id);
		printf("PREV : %d\n", previous->id);
		getchar();
	}
	return id;
	
}


index *add_gr(index *id){
	
	index *new_id = (index *)malloc(sizeof(index));
	if(!new_id){
		printf("\nERRO DE ALOCACAO\n");
		exit(1);
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
		printf("\nERRO DE ALOCACAO\n");
		exit(1);
	}
	
	new->info = info;
	new->next = NULL;
	
	while(aux_id->id != ref && aux_id->next){
		aux_id = aux_id->next;
	}
	
	if(!aux_id->group){
		
		aux_id->group = new;
		new->prev = aux_id->group;
		printf("VALORES ALOCADOS\n\t");
		getchar();
		return id;
		
	}else{
		
		aux_id->group = aux_group;
		
		while(aux_group->next){
			aux_group = aux_group->next;
		}
		
		printf("VALORES ALOCADOS\n\t");
		getchar();
		
		aux_group->next = new;
		new->prev = aux_group;
		
		return aux_id;

	}
	
}


int main(){

	int op, ref, info, num, i;
	index *id;
	id = NULL;
	
	do{
		system("clear");
		printf("\n\tTRABALHO NP1 - CONJUNTOS EM ALOCACAO DINAMICA\n\n");
		printf("\n\tESCOLHA UMA OPCAO\n\n");
		printf("\t0 - FECHAR\n");
		printf("\t1 - INSERIR CONJUNTO\n");
		printf("\t2 - REMOVER CONJUNTO\n");
		printf("\t3 - INSERIR ELEMENTOS NO CONJUNTO\n");
		printf("\t4 - REMOVER ELEMENTOS NO CONJUNTO\n");
		printf("\t5 - VISUALIZAR CONJUNTOS\n");
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
				printf("\n\tQUAL CONJUNTO REMOVER?  ");
				scanf("%d", &ref);
				id = delete_group(id, ref);
				
			break;
			
			case 3:		
				printf("\n\tSELECIONE O CONJUNTO: ");
				scanf("%d", &ref);
				printf("\tQUANTIDADE DE VALORES A INSERIR: ");
				scanf("%d", &num);
				for(i=0; i<num; i++){
		
					scanf("%d", &info);		
					id = add_info(id, ref, info);
					
				}
				
			break;
			
			case 4:
				
			break;
		
			case 5:
				view_groups(id);
				getchar();
			break;
			
			case 6:
				
			break;
			
			case 7:
				
			break;
		}
		
	}while(op);

	return 0;
	
}
