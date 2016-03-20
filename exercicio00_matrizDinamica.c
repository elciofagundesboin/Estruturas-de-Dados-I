#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int i, j, linha, *coluna, **matriz;
	srand((unsigned) time(NULL));
	
	linha = rand()%10;
	// Aloca um vetor para as colunas:
	coluna = (int *) calloc(linha, sizeof(int));
	if(coluna == NULL){
		printf("Erro ao alocar: memória insuficiente!"); // Testa se a aloação funcionou;
		return 0;
	}
	// Aloca as colunas na matriz:
	matriz = (int **) calloc(linha, sizeof(int *));
	if(matriz == NULL){
		printf("Erro ao alocar: memória insuficiente!"); // Testa se a aloação funcionou;
		return 0;
	}
	
	//Aloca as colunas da matriz:
	for(i=0; i<linha; i++){
		coluna[i] = rand()%10;
		matriz[i] = (int *) calloc(coluna[i], sizeof(int));
		// Insere valores nas "celulas" da matriz:
		for(j=0; j<coluna[i]; j++){
			matriz[i][j] = rand()%9;
		}
	}
	
	// Mostra os valores contidos na matriz:
	for(i=0; i<linha; i++){
		printf("%p:\t", matriz[i]); // <- Mostra o endereço da linha;
		for(j=0; j<coluna[i]; j++){
			printf("%d  ", matriz[i][j]);
		}
		printf("\n");
	}
	free(matriz);
	free(coluna);
	
	return 0;
}
