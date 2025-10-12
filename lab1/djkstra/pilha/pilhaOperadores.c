// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "pilhaOperadores.h"

typedef struct celula Celula;

struct celula{
    char operador;
    Celula* prox;
};

struct pilhaOperadores{
    Celula* prim;
    Celula* ult;
};

PilhaOperadores* criaPilhaOperadores(){
    PilhaOperadores* pilha = malloc(sizeof(struct pilhaOperadores));
    pilha->prim = NULL;
    pilha->ult = NULL;
    return pilha;
}

char retornaOperador(char* op){
    char operador = *op;
    return operador;
}

static Celula* criaCelula(char op){
    Celula* nova = malloc(sizeof(struct celula));
    
    char operador = op;
    nova->operador = operador;
    
    nova->prox = NULL;
    
    return nova;
}

static PilhaOperadores* adicionaCelulaPilha(PilhaOperadores* pilha, Celula* nova){
    if(pilha->prim == NULL){
        pilha->prim = nova;
        pilha->ult = nova;
    }
    else{
        nova->prox = pilha->prim;
        pilha->prim = nova;
    }
    return pilha;
}


void adicionaOperadorPilha(PilhaOperadores* pilhaOperadores, char* c){
    char op = retornaOperador(c);
    Celula* nova = criaCelula(op);
    pilhaOperadores = adicionaCelulaPilha(pilhaOperadores, nova);
}


static Celula* retornaCelulaPilha(PilhaOperadores* pilha){
    Celula* aux = NULL; 

    if(pilha->prim){
        if(pilha->prim->prox){
            aux = pilha->prim;
            pilha->prim = pilha->prim->prox;
        }
        else{
            aux = pilha->prim;
            pilha->prim = NULL;
            pilha->ult = NULL;
        }
    }

    return aux;
}

char retornaOperacao(PilhaOperadores* pilha){
    Celula* aux = retornaCelulaPilha(pilha);
    if(aux){
        char num = aux->operador;

        aux->prox = NULL;
        free(aux);
        return num;
    }
    else return '\0';
}


void imprimePilhaOperadores(PilhaOperadores* pilha){
    Celula* aux;
    for(aux = pilha->prim; aux; aux = aux->prox){
        printf("%c\n", aux->operador);
    }
}

void liberaPilhaOperadores(PilhaOperadores* pilha){
    Celula* atual = pilha->prim;
    Celula* seguinte;

    while(atual){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(pilha);
}