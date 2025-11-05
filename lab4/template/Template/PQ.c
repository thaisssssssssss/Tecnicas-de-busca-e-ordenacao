#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"


#define exch(A, B) { Event* t = A; A = B; B = t; }

// TODO: Aqui você deve implementar uma fila com prioridade mínima para
//       ordenar os eventos por tempo, isto é, o evento com o menor tempo tem
//       a maior prioridade. Veja as funções definidas em 'event.h' para
//       a manipulação das estruturas de evento. A princípio, as funções já
//       existentes em 'event.h' são suficientes para implementar a simulação,
//       isto é, você não precisa implementar mais nada lá.
//
//       Você é livre para implementar a fila com prioridade da forma que quiser
//       mas é recomendado usar um min-heap para obter um bom desempenho. As
//       simulações maiores geram uma quantidade grande de eventos: um
//       limite superior frouxo (mas seguro) para o número máximo simultâneo de
//       eventos é N^3, aonde N é o número de partículas.

// TODO: Crie a struct pq.

struct pq{
    Event** minHeap;
    int max_N;
    int pos;
};


/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ* PQ_create(int max_N) {
    // TODO: Implemente a criação da fila que suporta no máximo o número de
    //       de eventos informados no parâmetro.

    PQ* pq = malloc(sizeof(struct pq));
    pq->max_N = max_N;
    pq->minHeap = malloc(sizeof(struct event*) * (pq->max_N + 1));
    int i;
    for(i = 1; i <= pq->max_N; i++){
        pq->minHeap[i] = NULL;
    }
    pq->pos = 0;
    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq) {
    // TODO: Implemente essa função que libera toda a memória da fila,
    //       destruindo inclusive os eventos que estavam na fila.
    int i;
    for(i = 1; i <= pq->max_N; i++){
        if(pq->minHeap[i] != NULL) destroy_event(pq->minHeap[i]);
    }
    free(pq->minHeap);
    free(pq);
}

//reoordena a estrutura apos adicionar novo evento
static void fixUp(PQ* pq){
    int k = pq->pos;
    while(k > 1 && (compare(pq->minHeap[k], pq->minHeap[k/2]) < 0)){
        exch(pq->minHeap[k], pq->minHeap[k/2]);
        k = k / 2;
    }
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e) {
    // TODO: Implemente essa função que insere o evento dado na fila segundo
    //       o tempo do evento.
    //       Assuma que 'e' não é nulo. É importante testar overflow (inserção
    //       em uma fila que já contém o número máximo de eventos) para evitar
    //       dores de cabeça com acessos inválidos na memória.
    if(pq->pos < pq->max_N){
        pq->pos++;
        pq->minHeap[pq->pos] = e;
        fixUp(pq);
    }
}

//reordena a estrutura apos remover evento
static void fixDown(PQ* pq){
    int k = 1;
    while(2 * k <= pq->pos){
        int j = 2 * k;
        if(j < pq->pos){
            if(compare(pq->minHeap[j + 1], pq->minHeap[j]) < 0) j++;
        }

        if(compare(pq->minHeap[j], pq->minHeap[k]) < 0){
            exch(pq->minHeap[j], pq->minHeap[k]);
            k = j;
        }
        else break;
    }
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event* PQ_delmin(PQ *pq) {
    // TODO: Implemente essa função que remove o evento com o menor tempo da
    //       fila e o retorna.
    if(pq->pos >= 1){
        Event* min = pq->minHeap[1];
        exch(pq->minHeap[1], pq->minHeap[pq->pos]);
        pq->minHeap[pq->pos] = NULL;
        pq->pos--;
        fixDown(pq);
        return min;
    }
    else return NULL;
}


/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq) {
    // TODO: Implemente essa função.
    return (!pq->pos);
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq) {
    // TODO: Implemente essa função.
    return pq->pos;
}
