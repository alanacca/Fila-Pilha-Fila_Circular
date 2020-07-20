#ifndef _FILA_H_
#define _FILA_H_
#define TRUE 1
#define FALSE 0
typedef struct quere{
    int maxElms;
    int front;
    int rear;
    void **elms;
    int nElms;
}Quere;

#ifdef _FILA_C_
    Quere *qCreate(int n);
    int qEnquere(Quere *q,void *elm);
    void *qDequere(Quere*q);
    int qDestroy(Quere *q);
#else
    extern Quere *qCreate(int n);
    extern int qEnquere(Quere *q,void *elm);
    extern void *qDequere(Quere*q);
    extern int qDestroy(Quere *q);
#endif
#endif // _FILA_H_
