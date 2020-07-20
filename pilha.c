#ifndef _pilha_c_
#define _pilha_c_
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

Stack *stkCreate(int n){
  Stack *s;
  if(n>0){
    s = (Stack*)malloc(sizeof(Stack));
    if(s!=NULL){
      s->elms = (void**)malloc(sizeof(void*)*n);
      if(s->elms!=NULL){
        s->top = -1;
        s->maxElms=n;
        return s;
      }
    }
  }
  return NULL;
}

int stkDestroy(Stack *s){
  if(s!=NULL){
    if(s->top<0){
      free(s->elms);
      free(s);
      return TRUE;
    }
  }
  return FALSE;
}

int stkPush(Stack *s,void *elm){
  if(s!=NULL){
    if(s->top<s->maxElms){
      s->top++;
      s->elms[s->top] = elm;
      return TRUE;
    }
  }
  return FALSE;
}

void *stkPop(Stack *s){
  void *aux;
  if(s!=NULL){
    if(s->top>=0){
      aux = s->elms[s->top];
      s->top--;
      return aux;
    }
  }
  return NULL;
}

int stkIsEmpty(Stack *s){
  if(s==NULL){
    if(s->top<0){
      return TRUE;
    }
  }
  return FALSE;
}

int AvaliaParenteses(char *str,int n){
  Stack *s1;
  int ver,stat;
  void *aux;
  s1 = stkCreate(n);
  if(str!=NULL){
    if(n>0){
      for(int i=0;i<n || stat!=TRUE;i++){
        if(str[i] == '('){
          ver = stkPush(s1,(void*)&str[i]); 
        }else if(str[i] == ')'){
          if(s1->top<0){
            aux = stkPop(s1);
          }
        }
        stat = stkIsEmpty(s1);
      }
      if(stat == TRUE){
        return TRUE;
      }else{
        return FALSE;
      } 
    }
  }
}


#endif