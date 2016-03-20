#include<stdio.h>
#include<stdlib.h>
#include<time.h> // Necessária para a função rand();

int* uniao(int *v1, int n1, int *v2, int n2){ // Função que une os vetores v1 e v2;
	int i, j=0;
	int *v3 = (int *) calloc(n1+n2, sizeof(int));
	
	if(v3 == NULL){
		printf("Erro ao alocar: memória insuficiente!"); // Testa se a aloação funcionou;
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
	srand((unsigned) time(NULL)); // Necessário para o funcionamento da função rand();
	
	int i, *v1, *v2, *v3, n1 = rand()%10, n2 = rand()%10; // Declara as variáveis e define valores aleatórios para n1 e n2;
	
	v1 = (int *) calloc(n1, sizeof(int)); // Aloca memória para os vetores v1 e v2;
	v2 = (int *) calloc(n2, sizeof(int)); // ^ ^ ^ ^
	
	for(i=0; i<n1; i++){
		v1[i] = rand()%9;
	}
	for(i=0; i<n2; i++){
		v2[i] = rand()%9;
	}
	
	v3 = uniao(v1, n1, v2, n2); // Chama a função de união;
	
	// Imprime na tela os valores dos vetores (meio longo, mas é questão de legibilidade);
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
