#include<stdio.h>
#include<stdlib.h>
#include<time.h> // Necess�ria para a fun��o rand();

int* uniao(int *v1, int n1, int *v2, int n2){ // Fun��o que une os vetores v1 e v2;
	int i, j=0;
	int *v3 = (int *) calloc(n1+n2, sizeof(int));
	
	if(v3 == NULL){
		printf("Erro ao alocar: mem�ria insuficiente!"); // Testa se a aloa��o funcionou;
		return NULL;
	}
	
	for(i=0; i<(n1+n2); i++){
		if(i<n1){
			v3[i] = v1[i];
		}else{
			v3[i] = v2[i-n1];
		}
	}
	return v3;
}

int main(){
	srand((unsigned) time(NULL)); // Necess�rio para o funcionamento da fun��o rand();
	
	int i, *v1, *v2, *v3, n1 = rand()%10, n2 = rand()%10; // Declara as vari�veis e define valores aleat�rios para n1 e n2;
	
	v1 = (int *) calloc(n1, sizeof(int)); // Aloca mem�ria para os vetores v1 e v2;
	v2 = (int *) calloc(n2, sizeof(int)); // ^ ^ ^ ^
	
	for(i=0; i<n1; i++){
		v1[i] = rand()%9;
	}
	for(i=0; i<n2; i++){
		v2[i] = rand()%9;
	}
	
	v3 = uniao(v1, n1, v2, n2); // Chama a fun��o de uni�o;
	
	// Imprime na tela os valores dos vetores (meio longo, mas � quest�o de legibilidade);
	// -----------------------------------------------------------------------------------
	
	printf("Elementos em v1: %d;\nElementos em v2: %d;\nElementos em v3: %d;\n\n", n1, n2, n1+n2);
	
	
	printf("Vetor 1:\n");
	for(i=0; i<n1; i++){
		printf("[%d]\t", i);
	}
	printf("\n");
	for(i=0; i<n1; i++){
		printf(" %d \t", v1[i]);
	}
	printf("\n\n");
	
	printf("Vetor 2:\n");
	for(i=0; i<n2; i++){
		printf("[%d]\t", i);
	}
	printf("\n");
	for(i=0; i<n2; i++){
		printf(" %d \t", v2[i]);
	}
	printf("\n\n");
	
	printf("Vetor 3:\n");
	for(i=0; i<n1+n2; i++){
		printf("[%d]\t", i);
	}
	printf("\n");
	for(i=0; i<n1+n2; i++){
		printf(" %d \t", v3[i]);
	}
	printf("\n\n");
	
	// -----------------------------------------------------------------------------------
	
	free(v1);
	free(v2);
	free(v3);
	
	return 0;
}
