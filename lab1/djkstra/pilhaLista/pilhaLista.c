#include "pilha.h"

typedef struct celula Celula;

struct celula{
    void* op;
    Celula* prox;
};

struct pilha{
    Celula* prim;
    Celula* ult;
};

Pilha* criaPilha(){
    Pilha* pilha = malloc(sizeof(struct pilha));
    pilha->prim = NULL;
    pilha->ult = NULL;
    return pilha;
}

Celula* criaCelula(void* op){
    Celula* nova = malloc(sizeof(struct celula));
    nova->op = &op;
    nova->prox = NULL;
    return nova;
}

void adicionaCelulaPilha(Pilha* pilha, Celula* nova){
    if(pilha->prim == NULL){
        pilha->prim = nova;
        pilha->ult = nova;
    }
    else{
        nova->prox = pilha->prim;
        pilha->prim = nova;
    }
}

void liberaCelula(Celula* cel){
    cel->prox = NULL;
    free(cel);
}

Celula* retornaCelulaPilha(Pilha* pilha){
    Celula* aux; 

    if(pilha->prim->prox){
        aux = pilha->prim;
        pilha->prim = pilha->prim->prox;
    }
    else{
        aux = pilha->prim;
        pilha->prim = NULL;
        pilha->ult = NULL;
    }

    return aux;
}

double* fazCastingOperandos(Celula* cel){
    double* op = (double*)cel->op;
    return op;
}

char* fazCastingOperadores(Celula* cel){
    char* op = (char*)cel->op;
    return op;
}

double* realizaOperacao(double* op1, double* op2, char* op){
    if(*(op) == '+'){
        *(op1) = *(op1) + *(op2);
    }
    else if(*(op) == '-'){
        *(op1) = *(op1) - *(op2);
    }
    else if(*(op) == '/'){
        *(op1) = *(op1) / *(op2);
    }
    else if(*(op) == '*'){
        *(op1) = *(op1) * *(op2);
    }
    return op1;
}

Pilha* lePilha(){
    Pilha* pilhaOperandos = malloc(sizeof(struct pilha));
    Pilha* pilhaOperadores = malloc(sizeof(struct pilha));

    int pAbre = 0, pFecha = 0;
    char* c;

    while(1){
        scanf("%c", &c);
        if(c == '(') pAbre++;
        else if(c == ')'){
            Celula* num1 = retornaCelulaPilha(pilhaOperandos);
            Celula* num2 = retornaCelulaPilha(pilhaOperandos);
            Celula* op = retornaCelulaPilha(pilhaOperadores);

            double* op1 = fazCastingOperandos(num1);
            double* op2 = fazCastingOperandos(num2);
            char* simbolo = fazCastingOperandos(op);

            liberaCelula(num1);
            liberaCelula(num2);
            liberaCelula(simbolo);

            op1 = realizaOperacao(op1, op2, simbolo);
            Celula* nova = criaCelula(op1);
            adicionaCelulaPilha(pilhaOperandos, nova);

            pFecha++;
        }
        else if(c == ' ');
        else if(c >= '0' && c <= '9'){
            Celula* nova = criaCelula(&c);
            adicionaCelulaPilha(pilhaOperandos, nova);
        }
        else{
            Celula* nova = criaCelula(&c);
            adicionaCelulaPilha(pilhaOperadores, nova);
        }

        if(pAbre == pFecha) break;
        
    }
}

void imprimeResultado(Pilha* pilhaOperandos){
    printf("Resultado: %d\n", *(double*)(pilhaOperandos->prim->op));
}