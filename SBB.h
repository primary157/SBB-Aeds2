#ifndef SBB_H_INCLUDED
#define SBB_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef enum{
	Vertical, Horizontal
} TInclinacao;
typedef enum { True, False } Boolean;
typedef struct {
	unsigned int a_matricula;
	char* a_nome;
	unsigned int a_nome_sz;
	float a_notas[3]; //[0] prova 1, [1] prova 2, [2] TP
} Aluno;
typedef struct _tnode{
	struct _tnode *esq, *dir;
	TInclinacao i_esq, i_dir;
	Aluno chave;
} TNode;
//inicializador e destruidor
void inicializaNo(Aluno chave, TNode** n);
void inicializaAluno(Aluno* chave, unsigned int sz);
//Busca, Insere e conta
TNode* encontrarNo(unsigned int matricula, TNode* no);
void insereNo(Aluno chave, TNode** no);
void _insereNo(Aluno chave, TNode** no, TInclinacao *i_no , Boolean *fim);
unsigned int contaNos(TNode* no);
//Retira
void retiraNo(Aluno chave, TNode** no);
void _retiraNo(Aluno chave, TNode** no, Boolean *fim);

//Printando na tela
void printaArvoreOrdem(TNode* no);
void printaNo(TNode* no);
void antecessor(TNode* q, TNode** r, Boolean* fim);
//Procedimentos Auxiliares
void dirCurto(TNode** no, Boolean* Fim);
void esqCurto(TNode** no, Boolean* Fim);
void EE(TNode** no);
void DE(TNode** no);
void ED(TNode** no);
void DD(TNode** no);

#endif
