#ifndef _FILAC_C_
#define _FILAC_C_
#include <stdio.h>
#include <stdlib.h>
#include "filac.h"

Queue *qCreate(int n){
    Queue *q;
    if(n>0){
        q = (Queue*)malloc(sizeof(Queue));
        if(q!=NULL){
            q->elms = (void**)malloc(sizeof(void*)*n);
            if(q->elms!=NULL){
                q->maxElms = n;
                q->nElms = 0;
                q->front = 0;
                q->rear = -1;
                return q;
            }
        }
    }
    return NULL;
}

int IncrementoC(int pos,int max){
    if(pos==max-1){
        return 0;
    }else{
        pos++;
        return pos;
    }
}

int DecrementoC(int pos,int max){
    if(pos==0){
        return max-1;
    }else{
        pos--;
        return pos;
    }
}


int qEnqueueC(Queue *q,void *elm){
    if(q!=NULL){
        if(q->rear<q->maxElms-1){
            q->rear = IncrementoC(q->rear,q->maxElms);
            q->elms[q->rear] = elm;
            return TRUE;
        }
    }
    return FALSE;
}

void *qDequeueC(Queue *q){
    void *aux;
    if(q!=NULL){
        if(q->rear>=0){
            aux = q->elms[q->front];
            q->front = IncrementoC(q->front,q->maxElms);
            return aux;
        }
    }
    return NULL;
}

int qInsertKAfterFirst(Queue *q,int k,void *elm){
  int aux,posQueue;
  if(q != NULL){
    if(k<q->maxElms){
      aux = IncrementoC(q->rear,q->maxElms);
      posQueue = q->front;
      for (int i = 0 ; i<k; i++){
        posQueue = IncrementoC(posQueue,q->maxElms);
      }
      while(aux!=posQueue){
        q->elms[aux] = q->elms[DecrementoC(aux,q->maxElms)];
        aux = DecrementoC(aux, q->maxElms);
      }
      q->elms[aux] = elm;//aux = posQueue
      q->rear = IncrementoC(q->rear,q->maxElms);
      q->nElms++;
    }else{
      aux = IncrementoC(q->rear,q->maxElms);
      q->elms[aux] = elm;
    }
    return TRUE;

  }
  return FALSE;
}

void imprimirFila(Queue *q){
  for(int i=0;i<q->maxElms;i++){
    printf("queue: %d\n",(int)q->elms[i]);
  }
}


#endif