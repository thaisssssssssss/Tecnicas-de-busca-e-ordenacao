// Thais Gomes Brandão 
// Matrícula:  2024102657

#include "pilhaOperadores.h"
#include "pilhaOperandos.h"

double realizaOperacao(double op1, double op2, char op){
    if(op == '+'){
        op1 = op1 + op2;
    }
    else if(op == '-'){
        op1 = op1 - op2;
    }
    else if(op == '*'){
        op1 = op1 * op2;
    }
    else if(op == '/'){
        op1 = op1 / op2;
    }
    return op1;
}

int comparaString(char* str, char* comp){
    return strcmp(str, comp);
}

int confereStringOperador(char* str){
    return (!comparaString(str, "+") || !comparaString(str, "-") || !comparaString(str, "*") || !comparaString(str, "/"));
}


void lePilha(PilhaOperandos* pilhaOperandos, PilhaOperadores* pilhaOperadores){

    int pAbre = 0, pFecha = 0;
    char c[10];

    while(1){
        scanf(" %s", c);

        if(!comparaString(c, "(")) pAbre++;
        else if(!comparaString(c, ")")){
            double num1 = retornaValor(pilhaOperandos);
            double num2 = retornaValor(pilhaOperandos);
            char op = retornaOperacao(pilhaOperadores);

            num1 = realizaOperacao(num2, num1, op);
            adicionaValorPilha(pilhaOperandos, "\0", num1, DOUBLE);

            pFecha++;
        }
        else if(confereStringOperador(c)) adicionaOperadorPilha(pilhaOperadores, c);
        else adicionaValorPilha(pilhaOperandos, c, 0, CHAR);
            
        
        if(pAbre == pFecha) break;
        
    }
}

int main(){
    PilhaOperandos* pilhaOperandos = criaPilhaOperandos();
    PilhaOperadores* pilhaOperadores = criaPilhaOperadores();

    lePilha(pilhaOperandos, pilhaOperadores);

    imprimePilha(pilhaOperandos);
    liberaPilhaOperandos(pilhaOperandos);
    liberaPilhaOperadores(pilhaOperadores);

    return 0;
}