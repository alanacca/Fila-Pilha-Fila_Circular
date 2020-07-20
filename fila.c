#ifndef _FILA_C_
#define _FILA_C_
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Quere *qCreate(int n){
    Quere *q;
    if(n>0){
        q = (Quere*)malloc(sizeof(Quere));
        if(q!=NULL){
            q->elms = (void**)malloc(sizeof(void*)*n);
            if(q->elms!=NULL){
                q->front = 0;
                q->maxElms = n;
                q->rear = -1;
                q->nElms = 0;
                return q;
            }
        }
    }
    return NULL;
}

int qEnquere(Quere *q,void *elm){
    if(q!=NULL){
        if(q->rear<q->maxElms-1){
            q->rear++;
            q->elms[q->rear] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void *qDequere(Quere *q){
    void *aux;
    if(q!=NULL){
        if(q->rear>=0){
            aux = q->elms[q->front];
            for(int i=q->front;i<q->rear-1;i++){
                q->elms[i] = q->elms[i+1];
            }
            q->rear--;
            return aux;
        }
    }
    return NULL;
}

int qDestroy(Quere *q){
    if(q!=NULL){
        if(q->rear<0){
            free(q->elms);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}
#endif // _FILA_C_
