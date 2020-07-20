#ifndef _FILAC_H_
#define _FILAC_H_
#define TRUE 1
#define FALSE 0
#include <stdlib.h>
#include <stdio.h>

typedef struct queue{
  void **elms;
  int front;
  int rear;
  int maxElms;
  int nElms;
}Queue;

#ifndef _fila_c_
  Queue *qCreate(int n);
  int qEnqueueC(Queue *q,void *elm);
  void *qDequeueC(Queue *q);
  int qDestroyC(Queue *q);
  int IncrementoC(int pos,int max);
  int DecrementoC(int pos,int max);
  int qInsertKAfterFirst(Queue *q,int k,void *elm);
  void imprimirFila(Queue *q);
#else
  extern Queue *qCreate(int n);
  extern int qEnqueueC(Queue *q,void *elm);
  extern void *qDequeueC(Queue *q);
  extern int qDestroyC(Queue *q);
  extern int IncrementoC(int pos,int max);
  extern int DecrementoC(int pos,int mac);
  extern int qInsertKAfterFirst(Queue *q,int k,void *elm);
  extern void imprimirFila(Queue *q);
#endif
#endif //fila_h_
