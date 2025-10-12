// Thais Gomes Brandão 
// Matrícula:  2024102657


#include "pilhaOperandos.h"

typedef struct celula Celula;

struct celula{
    double operando;
    Celula* prox;
};

struct pilhaOperandos{
    Celula* prim;
    Celula* ult;
};

PilhaOperandos* criaPilhaOperandos(){
    PilhaOperandos* pilha = malloc(sizeof(struct pilhaOperandos));
    pilha->prim = NULL;
    pilha->ult = NULL;
    return pilha;
}


double retornaNumero(char* op){
    return atof(op); // Converte string para double de forma eficiente
}

static Celula* criaCelula(double num){
    Celula* nova = malloc(sizeof(struct celula));
    
    nova->operando = num;
    nova->prox = NULL;
    
    return nova;
}

static PilhaOperandos* adicionaCelulaPilha(PilhaOperandos* pilha, Celula* nova){
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

void adicionaValorPilha(PilhaOperandos* pilhaOperandos, char* c, double n, int OPCAO){
    double num;
    if(OPCAO == CHAR) num = retornaNumero(c);
    else num = n;

    Celula* nova = criaCelula(num);
    pilhaOperandos = adicionaCelulaPilha(pilhaOperandos, nova);
}

static Celula* retornaCelulaPilha(PilhaOperandos* pilha){
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

void imprimePilha(PilhaOperandos* pilha){
    Celula* aux;
    for(aux = pilha->prim; aux; aux = aux->prox){
        printf("%.2f\n", aux->operando);
    }
}

double retornaValor(PilhaOperandos* pilha){
    Celula* aux = retornaCelulaPilha(pilha);
    if(aux){
        double num = aux->operando;

        aux->prox = NULL;
        free(aux);
        return num;
    }
    else return 1;
}

void liberaPilhaOperandos(PilhaOperandos* pilha){
    Celula* atual = pilha->prim;
    Celula* seguinte;

    while(atual){
        seguinte = atual->prox;
        free(atual);
        atual = seguinte;
    }
    free(pilha);
}

