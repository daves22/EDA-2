#include <stdlib.h>
#include <stdio.h>

typedef struct celula
{
  int dado;
  struct celula *prox;
} celula;

celula *cria_lista(){
  celula *p = malloc(sizeof(celula));
  if (p == NULL)
    exit(1);
  p->prox = NULL;
  return p;
}

void insere_inicio(celula *le, int x){
  celula *novo = malloc(sizeof(celula));
  if (novo == NULL){
    printf("NULL");
  }

  novo->dado = x;
  novo->prox = le->prox;
  le->prox = novo;
}

void insere_antes(celula *le, int x, int y){
  celula *p = le->prox;
  celula *antes = le;
  if (p == NULL || p -> dado == y){
    insere_inicio(le, x);
  }
  while (p != NULL){
    /* if( ptr->prox->dado == y) {
       insere_inicio(ptr->prox, x);
     } */
    if(p->dado == y){
      insere_inicio(antes, x);
      break;
    } 
    if(p->prox == NULL){
      //printf ("%d -", ptr->dado);
      insere_inicio(p, x);
      break;
    }
    /*printf ("%d -", ptr->dado); */
    antes = p;
    p = p->prox;
  }
}

int lista_vazia(celula *le){
  return le->prox == NULL;
}

int remove_inicio(celula *le){
  celula *lixo = le->prox;
  int dado = lixo->dado;
  le->prox = lixo->prox;
  free(lixo);
  return dado;
}

void destroi_lista(celula *le){
  while (le->prox != NULL)
  remove_inicio(le);
}

void imprime (celula *le){
  celula *ptr = le->prox;
  while (ptr != NULL){
    printf ("%d", ptr->dado);
    printf (" -> ");
    ptr = ptr->prox;
  }
  printf ("NULL\n");
  
}

void imprime_rec (celula *le){
  celula *ptr = le->prox;     
  if (ptr != NULL){
    printf ("%d", ptr->dado);
    printf (" -> ");
    imprime_rec(ptr); 
  }
  else{
    printf ("NULL\n");
  }
}

int main(){
  char op;
  int dado;
  int y;

  celula *p = cria_lista();
  //celula *ptr = cria_lista();
    printf("O que voce deseja fazer?\n");
    printf("(I)nserir\n"); 
    printf("(M)ultiplos numeros\n");
    printf("(R)emover\n");
    printf("im(P)rimir\n"); 
    printf("imprimeRe(C)ursiva\n"); 
    printf("(A)nte\n");
    printf("(S)air\n\n");
    scanf(" %c", &op);
  
  while (op != 'S'){ 
    switch (op){
      case 'I':
        printf("Digite o dado: ");
        scanf("%d", &dado);
        insere_inicio(p, dado);
        break;
        
      case 'M':
        printf("Inserindo varios numeros: \n");
        //Declarando vetor
        int lista[10] = {1,2,3,4,5,6,7,8,9,10};
        for(int i = 0;i<10;i++){
          dado= lista[i];
          insere_inicio(p, dado);
        }
        break;

      case 'R':
        if (!lista_vazia(p)){
          printf("%d", remove_inicio(p));
          printf("\n");
        }
        else{
          printf("A lista esta vazia.\n");
        }
        break;

      case 'P':
        imprime(p);
        break;

      case 'C':
        imprime_rec(p);
        break;
      case 'A':
        insere_antes(p,dado);
        break;

      default:
        printf("Escolha uma opcao valida.\n");
    }
    printf("O que voce deseja fazer?\n");
    printf("(I)nserir\n"); 
    printf("(M)ultiplos numeros\n");
    printf("(R)emover\n");
    printf("im(P)rimir\n"); 
    printf("imprimeRe(C)ursiva\n"); 
    printf("(A)nte\n");
    printf("(S)air\n\n");
    scanf(" %c", &op);
  }
  destroi_lista(p);
  free(p);
  return 0;
}