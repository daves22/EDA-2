/*  Arvore Binária */
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;
typedef int tipochave;

typedef struct aux{
    tipochave chave;
    /* Dados armazenados vão aqui */
    struct aux *esq, *dir;
}NO;
typedef NO* pont;
 