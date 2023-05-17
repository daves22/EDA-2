#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void imprime(celula *le){
  celula *num = le->prox;
  while(num != NULL){
    printf ("%d", num->dado);
    printf (" -> ");
    num = num->prox;
  }
  printf ("NULL");
}

void imprime_rec (celula *le){
  celula *num = le->prox;
  if (num != NULL){
      printf ("%d", num->dado);
      printf (" -> ");
      imprime_rec(num->prox);
  }
  else{
     printf ("NULL\n");
  }
}