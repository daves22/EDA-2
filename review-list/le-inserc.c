#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *num= malloc(sizeof(celula));
    num->dado=x;
    num->prox = le->prox;
    le->prox = num;
}

void insere_antes (celula *le, int x, int y){
    celula *num= le->prox;
    celula *antes = le;
    if (num == NULL || num -> dado == y)
    {
        insere_inicio(le,x);
    }
    while (num!=NULL)
    {
        if (num->dado == y)
        {
            insere_inicio(antes,x);
            break;
        }
        if (num->prox==NULL)
        {
            insere_inicio(num,x);
            break;
        }
        antes = num;
        num = num->prox;
    }
}
