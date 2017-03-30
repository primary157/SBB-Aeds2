#include "SBBComArquivo.h"
TNode* leArquivo(){
	FILE* arquivo;
	if ((arquivo = fopen(NOME_ARQUIVO,"r")) == NULL){
		printf("Leitura falhou\n");
		return NULL;
	}
	TNode* arvore = NULL;
	Aluno tempChave;
	char temp_nome[40];

	while (!feof(arquivo)) {
		fscanf(arquivo,"%u - %s ; %f; %f; %f\n",
				&tempChave.a_matricula,
				temp_nome,
				&tempChave.a_notas[0],
				&tempChave.a_notas[1],
				&tempChave.a_notas[2]
				);
		for(tempChave.a_nome_sz = 0; temp_nome[tempChave.a_nome_sz] != '\0'; tempChave.a_nome_sz++){} 	//Capturando tamanho do nome
		tempChave.a_nome = (char*)malloc((tempChave.a_nome_sz+1)*sizeof(char));				//Alocando espaço para o nome
		tempChave.a_nome[tempChave.a_nome_sz] = '\0';							//Determinando fim da string
		for(tempChave.a_nome_sz = 0; temp_nome[tempChave.a_nome_sz] != '\0'; tempChave.a_nome_sz++){
			tempChave.a_nome[tempChave.a_nome_sz] = temp_nome[tempChave.a_nome_sz];			//copiando valor da string
		}
		insereNo(tempChave,&arvore); 									//criando No e inserindo à arvore
	}
	fclose(arquivo);
	return arvore;
}
