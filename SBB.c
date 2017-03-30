#include "SBB.h"
unsigned int contaNos(TNode* no){
	if(no->dir != NULL && no->esq != NULL) return (1 + contaNos(no->dir) + contaNos(no->esq));
	else{
		if(no->esq != NULL) return (1 + contaNos(no->esq)); //So tem na esquerda
		if(no->dir != NULL) return (1 + contaNos(no->dir)); //So tem na direita
		return 1; //Nó folha
	}
}
void printaArvoreOrdem(TNode* no){
	if(no == NULL) return;
	printaArvoreOrdem(no->esq);
	printaNo(no);
	printaArvoreOrdem(no->dir);
}
void printaNo(TNode* no){
	printf("Matricula: %u\tNome: %s\tNota Prova1: %.2f,\tProva2: %.2f,\tTP: %.2f\n",
			no->chave.a_matricula,
			no->chave.a_nome,
			no->chave.a_notas[0],
			no->chave.a_notas[1],
			no->chave.a_notas[2]
			);
}
void inicializaAluno(Aluno* chave, unsigned int sz){
	chave->a_nome = (char*)malloc(sz*sizeof(char));
	chave->a_nome_sz = sz;
	chave->a_matricula = 0;
	chave->a_notas[0] = 0.0;
	chave->a_notas[1] = 0.0;
	chave->a_notas[2] = 0.0;
}
void inicializaNo(Aluno chave, TNode** n){
	(*n) = (TNode*)malloc(sizeof(TNode));
	inicializaAluno(&(*n)->chave,chave.a_nome_sz);
	(*n)->chave.a_matricula = chave.a_matricula;
	(*n)->chave.a_nome = chave.a_nome;
	(*n)->chave.a_notas[0] = chave.a_notas[0];
	(*n)->chave.a_notas[1] = chave.a_notas[1];
	(*n)->chave.a_notas[2] = chave.a_notas[2];
	(*n)->i_esq = Vertical;
	(*n)->i_esq = Horizontal;
	(*n)->dir = NULL;
	(*n)->esq = NULL;
}
TNode* encontrarNo(unsigned int matricula, TNode* no){
	if(no == NULL) return NULL;
	if(matricula > no->chave.a_matricula) return encontrarNo(matricula, no->dir);
	if(matricula < no->chave.a_matricula) return encontrarNo(matricula, no->esq);
	else return no;
}
void EE(TNode** no){
	TNode *no1;
	no1 = (*no)->esq;
	(*no)->esq = no1->dir;
	no1->dir = (*no);
	no1->i_esq = Vertical;
	(*no)->i_esq = Vertical;
	(*no) = no1;
}
void DE(TNode** no){
	TNode *no1, *no2;
	no1 = (*no)->dir;
	no2 = no1->esq;
	no1->i_esq = Vertical;
	(*no)->i_dir = Vertical;
	no1->esq = no2->dir;
	no2->dir = no1;
	(*no)->dir = no2->esq;
	no2->esq = (*no);
	(*no) = no2;

}
void ED(TNode** no){
	TNode *no1, *no2;
	no1 = (*no)->esq;
	no2 = no1->dir;
	no1->i_dir = Vertical;
	(*no)->i_esq = Vertical;
	no1->dir = no2->esq;
	no2->esq = no1;
	(*no)->esq = no2->dir;
	no2->dir = (*no);
	(*no) = no2;
}
void DD(TNode** no){
	TNode *no1;
	no1 = (*no)->dir;
	(*no)->dir = no1->esq;
	no1->esq = (*no);
	no1->i_dir = Vertical;
	(*no)->i_dir = Vertical;
	(*no) = no1;

}
void insereNo(Aluno chave, TNode** no){
	Boolean fim; TInclinacao i_no;
	_insereNo(chave, no, &i_no, &fim);
}
void _insereNo(Aluno chave, TNode** no, TInclinacao *i_no, Boolean *fim){
	if((*no) == NULL){
		(*no) = (TNode*)malloc(sizeof(TNode));
		(*i_no) = Horizontal;
		(*no)->chave = chave;
		(*no)->esq = NULL;
		(*no)->dir = NULL;
		(*fim) = False;
		return;
	}
	if(chave.a_matricula < (*no)->chave.a_matricula){
		_insereNo(chave, &(*no)->esq, &(*no)->i_esq, fim);
		if((*fim)) return;
		if((*no)->i_esq != Horizontal){
			(*fim) = True;
			return;
		}
		if((*no)->esq->i_esq == Horizontal){
			EE(no);
			(*i_no) = Horizontal;
			return;
		}
		if((*no)->esq->i_dir == Horizontal){
			ED(no);
			(*i_no) = Horizontal;
		}
		return;
	}
	if(chave.a_matricula == (*no)->chave.a_matricula){
		printf("Erro: Chave ja esta na arvore\n");
		(*fim) = True;
		return;
	}
	_insereNo(chave, &(*no)->dir, &(*no)->i_dir, fim);
	if((*fim)) return;
	if((*no)->i_dir != Horizontal){
		(*fim) = True;
		return;
	}
	if((*no)->dir->i_dir == Horizontal){
		DD(no);
		(*i_no) = Horizontal;
		return;
	}
	if((*no)->dir->i_esq == Horizontal){
		DE(no);
		(*i_no) = Horizontal;
	}
}
void retiraNo(Aluno chave, TNode** no){
    Boolean fim;
    _retiraNo(chave, no, &fim);

}
void _retiraNo(Aluno chave, TNode** no, Boolean *fim){
    TNode *aux;
    if(*no == NULL){
        printf("Chave não está na árvore\n");
        *fim = True;
        return;
    }
    if(chave.a_matricula < (*no)->chave.a_matricula){
        _retiraNo(chave,&(*no)->esq,fim);
        if(!*fim) esqCurto(no,fim); 
        return;
    }
    if(chave.a_matricula > (*no)->chave.a_matricula){
        _retiraNo(chave,&(*no)->dir,fim);
        if(!*fim) dirCurto(no,fim); 
        return;
    }
    *fim = False; aux = *no;
    if(aux->dir == NULL){
        *no = aux->esq; free(aux);
        if(*no != NULL) *fim = True;
        return;
    }
    if(aux->esq == NULL){
        *no = aux->dir;
        free(aux);
        if(*no != NULL) *fim = True;
        return;
    }
    antecessor(aux,&aux->esq,fim);
    if(!*fim) esqCurto(no,fim); //Encontrou Chave
}
void antecessor(TNode* q, TNode** r, Boolean* fim){
    if((*r)->dir != NULL){
        antecessor(q,&(*r)->dir,fim);
        if(!*fim) dirCurto(r,fim);
        return;
    }
    q->chave = (*r)->chave;
    q = (*r);
    (*r) = (*r)->esq;
    free (q);
    if((*r) != NULL) *fim = True;
}
void dirCurto(TNode** no, Boolean* fim){
    
}
void esqCurto(TNode** no, Boolean* fim){
    TNode *no1;
    if((*no)->i_esq == Horizontal){
        (*no)->i_esq = Vertical;
        *fim = True;
        return;
    }
    if((*no)->i_dir == Horizontal){
        no1 = (*no)->dir;
        (*no)->dir = no1->esq;
        no1->esq = (*no);
        (*no) = no1;
        if((*no)->esq->dir->i_esq == Horizontal){
            DE(&(*no)->esq); (*no)->i_esq = Horizontal;
        }
        else if((*no)->esq->dir->i_dir == Horizontal){
            DD(&(*no)->esq;
            (*no)->i_esq = Horizontal;
        }
        *fim = True;
        return;
    }
    (*no)->i_dir = Horizontal;
    if((*no)->dir->i_esq == Horizontal){ DE(no); *fim = True; return;}
    if((*no)->dir->i_dir == Horizontal){ DD(no); *fim = True;}
}
