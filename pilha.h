#ifndef _pilha_h_
#define _pilha_h_
#define TRUE 1
#define FALSE 0
typedef struct _stack_{
  int top;//utilma posição ocupada
  int maxElms;//quantidade de elementos da pilha
  void **elms;
}Stack;
#ifndef _pilha_c
  Stack *stkCreate(int n);
  int stkDestroy(Stack *s);
  int stkPush(Stack *s,void *elem);
  void *stkPop(Stack *s);
  int stkEmpty(Stack *s);
  int AvaliaParenteses(char *str,int n);
#else
  extern Stack *stkCreate(int n);
  extern int stkDestroy(Stack *s);
  extern int stkPush(Stack *s,void *elem);
  extern void *stkPop(Stack *s);
  extern int stkEmpty(Stack *s);
  extern int AvaliaParenteses(char *str,int n);
#endif
#endif //_pilha_h_