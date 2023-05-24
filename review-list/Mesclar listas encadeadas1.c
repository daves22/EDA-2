#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

celula *reverse(celula *l){
  celula *revHead;
  if(l == NULL || l -> prox == NULL){
    return l;
  }

  revHead = reverse(l->prox);
  l -> prox -> prox = l;
  l -> prox = NULL; 

  return revHead;
}

void mescla_listas(celula *l1, celula *l2, celula *l3){
    for(celula *elem = l -> prox; elem != NULL; elem = elem -> prox){
        if(l1 > l2){
            l1 -> prox = l2-> prox;
            l2 -> prox= l3;
            l3 = elem;
        }
        else{
            l2 -> prox = l1 -> prox;
            l1 -> prox= l3;
            l3 = elem;
        }
    }
    if(l1 > l2){
        l1 -> prox = l2 -> prox;
        l2 -> prox= l3;
    }
    else{
        l2 -> prox = l1 -> prox;
        l1 -> prox= l3;
    }
    l3->prox = reverse(l3->prox);
}