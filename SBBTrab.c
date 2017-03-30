#include "SBBTrab.h"
void menorNotaProva1(TNode* no, float *nota){
	*nota = no->chave.a_notas[0];
	_menorNotaProva1(no,nota);
}
void _menorNotaProva1(TNode* no, float *nota){
	if(no == NULL) return;
	_menorNotaProva1(no->esq, nota); _menorNotaProva1(no->dir, nota);
	if(no->chave.a_notas[0] < *nota){
		*nota = no->chave.a_notas[0];
	}
}
void _maiorNotaTP(TNode* no, float *nota){
	if(no == NULL) return;
	_maiorNotaTP(no->esq, nota); _maiorNotaTP(no->dir, nota);
	if(no->chave.a_notas[2] > *nota){
		*nota = no->chave.a_notas[2];
	}
}
void maiorNotaTP(TNode* no, float *nota){
	*nota = no->chave.a_notas[2];
	_maiorNotaTP(no,nota);
}
void printaArvoreOrdemComMediaProva2(TNode* no){
	if(no == NULL) return;
	printaArvoreOrdemComMediaProva2(no->esq);
	if(no->chave.a_notas[1] >= 21.0) printaNo(no);
	printaArvoreOrdemComMediaProva2(no->dir);
}
void printaArvoreOrdemComMediaGeral(TNode* no){
	if(no == NULL) return;
	printaArvoreOrdemComMediaGeral(no->esq);
	if((no->chave.a_notas[0] + no->chave.a_notas[1] + no->chave.a_notas[2]) >= 60.0) printaNo(no);

	printaArvoreOrdemComMediaGeral(no->dir);
}
