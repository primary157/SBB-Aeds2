#include "SBBTrab.h"
#include "SBBComArquivo.h"
int main()
{
	float nota; //Variavel temporaria para segurar o valor obtido pelas funções menorNotaProva1 e maiorNotaTP
	TNode* Arvore = leArquivo();
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

	

	return 0;
}
