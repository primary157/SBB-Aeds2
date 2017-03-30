#ifndef BSTTRAB_H_INCLUDED
#define BSTTRAB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "SBB.h"
//Funções especificas implementação
void menorNotaProva1(TNode* no, float *nota);
void _menorNotaProva1(TNode* no, float *nota);
void maiorNotaTP(TNode* no, float *nota);
void _maiorNotaTP(TNode* no, float *nota);
//Printando na tela
void printaArvoreOrdemComMediaProva2(TNode* no);
void printaArvoreOrdemComMediaGeral(TNode* no);
#endif
