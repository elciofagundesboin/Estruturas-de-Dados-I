#include<stdio.h>
#include<stdlib.h>

int main(){
	int *num, aux=1, i, j=0, cont=0;
	
	num = (int *) calloc(5, sizeof(int));
	
	do{
		for(i=0; i<5; i++){
			printf("Informe um numero: ");
			aux = scanf("%d", &num[i+(j*5)]);
			if(aux==0){
				i=5;
				break;
			}
			cont++;
		}
		j++;
		if(i==4){
			num = (int *) realloc(num, ((j+1)*5)*sizeof(int));
		}
	}while(aux==1);
	
	for(i=0; i<cont; i++){
		printf("Num[%d]= %d\n", i, num[i]);
	}
	
	system("pause");
	
	free(num);	
	
	
	return 0;
}
