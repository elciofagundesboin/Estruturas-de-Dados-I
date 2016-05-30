//FUNÇÃO PARA DEBUG
void pause(){
	printf("\nPRESIONE QULQUER TECLA...\n");
	getchar();
}

//FUNÇÃO PARA MOSTRAR LISTA DINAMICA
void view_dList(TpContato *dList) {
     
    TpContato *auxList = dList; //PONTEIRO AUXILIAR PARA A LISTA

    printf("\n");

    while(auxList){	//ENQUANTO EXITIR ELEMENTOS
    	printf("NOME: %s\n", auxList->nome);
    	printf("FONE: %s\n", auxList->fone);
    	printf("--------------------\n");
    	auxList = auxList->next;	//PONTEIRO AUXILIAR APONTA PARA O PRÓXIMO NODO
    }
}

//FUNÇÃO PARA MOSTRAR LISTA ESTÁTICA (VETOR)
void view_sList(TpContato sList[]){

	int i;

	printf("\n");

	for(i=0; i<SIZE; i++){ 
		printf("NOME: %s\n", sList[i].nome);
		printf("FONE: %s\n", sList[i].fone);
		printf("--------------------\n");
	}
}

//FUNÇÃO PARA ALOCAR ELEMENTOS DINÂMICOS DUPLAMENTE LIGADOS
TpContato *creat_dList(TpContato *dList){
	
	char auxName[8] = {(rand()%9)+48, (rand()%9)+48, (rand()%9)+48};	//DEFINE 3 NUMEROS RANDÔMICOS PARA COMPLEMENTAR O NOME
	char auxPhone[8] = {(rand()%9)+48, (rand()%9)+48, (rand()%9)+48, (rand()%9)+48,	//DEFINE 8 NÚERMOS RANSÔMICOS PARA O FONE.
						(rand()%9)+48, (rand()%9)+48, (rand()%9)+48, (rand()%9)+48};	// O VALOR 48 REFERE-SE AO CHAR '0' DA TABELA ASCII

	TpContato *auxList = dList;	//PONTERIO AUXILIAR DA LISTA

	TpContato *new = (TpContato *)malloc(sizeof(TpContato));	//ALOCAÇÃO DE UM NOVO NODO
	if(!new){
		printf("\nERRO DE ALOCACAO");
		exit(1);
	}

	strcpy(new->nome, "FULANO ");	//COPIA A STRING "FULANO " PARA A LISTA 
	strcat(new->nome, auxName);	//CONCATENA "FULANO " + "3 NUMEROS ALEATÓRIOS"
	strcpy(new->fone, auxPhone);	//COPIA A STRING DO NUMERO DE TELEFONE
	new->next = NULL; //NODO NOVO SEMPRE COMEÇA APONTANDO PARA NULL
		
	if(!dList){//SE FOR O PRIMEIRO ELEMNTO A SER ALOCADO
		new->prev = NULL;
		return new; //RETORNA O PRIMERO ELEMENTO
	}
	
	while(auxList->next){ //LAÇO PARA APONTAR PARA O ÚLTIMO ELEMENTO DA LISTA
		auxList= auxList->next;
	}
	
	//APONTERIAMENTO
	auxList->next = new; 
	new->prev = auxList;

	return dList;	//RETORNA A LISTA ATUALIZADA	
}

//FUNÇÃO PARA CRIAR LISTA ESTATICA (VETOR)
TpContato *creat_sList(TpContato sList[]){

	int i;	// VARIÁVEL AUXILIAR

	for(i=0; i<SIZE; i++){

		char auxName[8] = {(rand()%9)+48, (rand()%9)+48, (rand()%9)+48}; //DEFINE 3 NUMEROS RANDÔMICOS PARA COMPLEMENTAR O NOME
		char auxPhone[8] = {(rand()%9)+48, (rand()%9)+48, (rand()%9)+48, (rand()%9)+48,	//DEFINE 8 NÚERMOS RANSÔMICOS PARA O FONE.
							(rand()%9)+48, (rand()%9)+48, (rand()%9)+48, (rand()%9)+48};	// O VALOR 48 REFERE-SE AO CHAR '0' DA TABELA ASCII

		strcpy(sList[i].nome, "FULANO "); //COPIA A STRING "FULANO " PARA A LISTA 
		strcat(sList[i].nome, auxName);	//CONCATENA "FULANO " + "3 NUMEROS ALEATÓRIOS"
		strcpy(sList[i].fone, auxPhone); //COPIA A STRING DO NUMERO DE TELEFONE
		sList[i].next = NULL; //NO CASO DE VETOR DEIXA PARA TODOS AS POSIÇÕES DOS PONTEIROS EM NULL
		sList[i].prev = NULL;
	}

	return sList; //RETORNA O VETOR
}

//FUNÇÃO PARA COPIAR LISTA DINÂMICA
TpContato *copy_dList(TpContato *dList, TpContato *dListCPY){

	TpContato *auxList = dList;	//PONTEIRO AUXILIAR DA LISTA
	TpContato *auxNew = NULL;	//PONTEIRO AUXILIAR PARA COPIAR A LISTA

	while(auxList){ //ENQUANTO EXISTIR ELEMENTOS

		TpContato *new = (TpContato *)malloc(sizeof(TpContato)); //ALOCAÇÃO DE NOVO ELEMENTO
		if(!new){
			printf("\nERRO DE ALOCACAO");
			exit(1);
		}

		strcpy(new->nome, auxList->nome); //COPIA A STRING NOME PARA A NOVA LISTA
		strcpy(new->fone, auxList->fone);	//COPIA A STRING FONE PARA A NOVA LISTA
		new->next = NULL;
		
		if(!auxList->prev){//SE FOR O PRIMEIRO ELEMENTO
			new->prev = NULL;
			auxNew = new;
			dListCPY = new;//dListCPY RECEBE O ENDEREÇO DO PRIMEIRO ELEMENTO
		}else{
			new->prev = auxNew; //NOVO NODO APONTA PARA O ANTERIOR
			auxNew->next = new; //NODO ANTERIOR APONTA PARA O PRÓXIMO
			auxNew = new; //PONTEIRO APONTA O O NODO SEGUINTE
		}

		auxList = auxList->next; //AUXILIAR DA LISTA PRINCIPAL APONTA PARA O ELEMENTO SEGUINTE

	}


	return dListCPY; //RETORNA O ÍNICIO DA NOVA LISTA
}

//FUNÇÃO PARA CFAZER A CÓPIA DE UM VETOR
TpContato *copy_sList(TpContato sList[], TpContato sListCPY[]){

	int i;

	for(i=0; i<SIZE; i++){//LAÇO DO TAMANHO DO VETOR

		strcpy(sListCPY[i].nome, sList[i].nome); //COPIA A STRING NOME PARA A NOVA LISTA
		strcpy(sListCPY[i].fone, sList[i].fone);	//COPIA A STRING FONE PARA A NOVA LISTA
		sListCPY[i].next = NULL;	//NO CASO DE VETOR OS PONTERIOS FICAM EM NULL
		sListCPY[i].prev = NULL;

	}

	return sListCPY; //RETORNA O NOVO VETOR
}


//////////////////////////////////////////////IMPLEMENTAR///////////////////////////
//FUNÇÃO DE ORDENAÇÃO GNOME SORT PARA VETOR
void *gnomeStatic(){

}

//FUNÇÃO DE ORDENAÇÃO GNOME SORT PARA LISTA
void *gnomeDinamic(){

}

//FUNÇÃO DE ORDENAÇÃO MERGE SORT PARA VETOR
TpContato *mergeStatic(TpContato *vetor, int posicaoInicio, int posicaoFim){
    int i, j, k, metadeTamanho;
    TpContato *vetorTemp;

    if(posicaoInicio == posicaoFim) return;

    //ORDENAÇÃO RECURSIVA DAS METADES DOS VETORES
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeStatic(vetor, posicaoInicio, metadeTamanho);
    mergeStatic(vetor, metadeTamanho + 1, posicaoFim);

    //ORGANIZAÇÃO NO VETOR TEMPORÁRIO
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = (TpContato *) malloc(sizeof(TpContato) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            } 
            else {
            	if(strcmp(vetor[i].nome, vetor[j].nome) < 0){
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                } 
                else { 
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // VALOR DO VETOR TEMPORÁRIO É PASSADO PARA O VETOR
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

//FUNÇÃO DE ORDENAÇÃO MERGE SORT PARA LISTA
TpContato *mergeDinamic(TpContato *lista, int posicaoInicio, int posicaoFim){
   int i, j, k, metadeTamanho;
    TpContato *listaTemp;

    if(posicaoInicio == posicaoFim) return;

    //ORDENAÇÃO RECURSIVA DAS METADES DOS VETORES
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;
    mergeStatic(lista, posicaoInicio, metadeTamanho);
    mergeStatic(lista, metadeTamanho + 1, posicaoFim);

    //ORGANIZAÇÃO NO VETOR TEMPORÁRIO
    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    listaTemp = (TpContato *) malloc(sizeof(TpContato) * (posicaoFim - posicaoInicio + 1));

    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) {
            listaTemp[k] = lista[j];
            j++;
            k++;
        } 
        else {
            if (j == posicaoFim + 1) {
                listaTemp[k] = lista[i];
                i++;
                k++;
            } 
            else {
            	if(strcmp(lista[i].nome, lista[j].nome) < 0){
                    listaTemp[k] = lista[i];
                    i++;
                    k++;
                } 
                else { 
                    listaTemp[k] = lista[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // VALOR DO VETOR TEMPORÁRIO É PASSADO PARA O VETOR
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        lista[i] = listaTemp[i - posicaoInicio];
    }
}