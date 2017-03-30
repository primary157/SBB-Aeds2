#include "SBBTrab.h"
#ifdef COM_ARQUIVO
#include "SBBComArquivo.h"
#endif
int main(){
    float nota; //Variavel temporaria para segurar o valor obtido pelas funções menorNotaProva1 e maiorNotaTP
#ifdef COM_ARQUIVO
	TNode* Arvore = leArquivo();
#else
    TNode* Arvore;
    Aluno temp_chave;
    inicializaAluno(&temp_chave,7);
    temp_chave.a_matricula = 2658;
    temp_chave.a_nome = "Victor"; temp_chave.a_nome_sz = 6; temp_chave.a_notas[0] = 28.0; temp_chave.a_notas[1] = 19.0; temp_chave.a_notas[2] = 20.0;
    inicializaNo(temp_chave, &Arvore);
    temp_chave.a_matricula = 2671;
    temp_chave.a_nome = "Fillipe"; temp_chave.a_nome_sz = 7; temp_chave.a_notas[0] = 25.0; temp_chave.a_notas[1] = 15.0; temp_chave.a_notas[2] = 21.5;
    insereNo(temp_chave, &Arvore);
    temp_chave.a_matricula = 2635;
    temp_chave.a_nome = "Gabriel"; temp_chave.a_nome_sz = 7; temp_chave.a_notas[0] = 2.0; temp_chave.a_notas[1] = 11.5; temp_chave.a_notas[2] = 22.0;
    insereNo(temp_chave, &Arvore);
#endif
#ifndef SEM_TRAB_FUNC
	menorNotaProva1(Arvore,&nota);
	printf("passou da leitura\n");
	printaArvoreOrdem(Arvore);
	printf("Num de alunos: %u\n",contaNos(Arvore));
	printf("menor nota P1: %.2f\n",nota);
	maiorNotaTP(Arvore,&nota);
	printf("maior nota TP: %.2f\n",nota);
	printaArvoreOrdemComMediaProva2(Arvore);
	printf("\n");
	printaArvoreOrdemComMediaGeral(Arvore);
#endif
#ifndef COM_ARQUIVO
    temp_chave.a_matricula = 2671;
    temp_chave.a_nome = "Fillipe"; temp_chave.a_nome_sz = 7; temp_chave.a_notas[0] = 25.0; temp_chave.a_notas[1] = 15.0; temp_chave.a_notas[2] = 21.5;
    printf("\n");
    retiraNo(temp_chave,&Arvore);
	printaArvoreOrdem(Arvore);
#endif

    
	

	return 0;
}
