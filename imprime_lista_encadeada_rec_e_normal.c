// #include <stdio.h>
// #include <stdlib.h>

// typedef struct celula{
//     int dado;
//     struct celula *prox;
// }celula;

// void imprime(celula *le){
//     if(le == NULL) printf("lista vazia");
//     printf("le->");
//     for(celula *num = le -> prox; num != NULL; num = num -> prox){
//         printf("%d",num -> dado);
//         printf("->");
//     }
//     printf("NULL");
// }

// void imprime_rec(celula *le){
//     printf("le->");
//     if(le != NULL){
//         imprime_rec (le -> prox);
//         printf("%d",le -> dado);
//         printf("->");
//     }
//     else{
//         printf("NULL");
//     }
// }

// int main(){
//     celula *le = NULL;
//     imprime(le);
//     //imprime_rec(le);
//     return 0;
// }

//certo

#include <stdlib.h>
#include <stdio.h>

typedef struct celula{
  int dado;
  struct celula *prox;
} celula;

void imprime (celula *le) {
  celula *num = le->prox;
  while (num != NULL) {
    printf ("%d", num->dado);
    printf (" -> ");
    num = num->prox;
  }
  printf ("NULL\n");
}

void imprime_rec (celula *le){
  celula *num = le->prox;
     
  if (num != NULL){
    printf ("%d", num->dado);
    printf (" -> ");
    imprime_rec(num); 
  }
  else{
    printf ("NULL\n");
  } 
}