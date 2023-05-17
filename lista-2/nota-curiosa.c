#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, nota_alta;
    scanf("%d",&n);

    int *v = malloc(1001*sizeof(int)),i,nota;
    for(i=0;i<1001;i++){
        v[i]=0;
    }
    while(scanf("%d",&nota)!=EOF){
        nota = nota % 1001;
        v[nota]++;
    }
    int maior = 0;
    for(i=0;i<1001;i++){
        if(v[i]>=maior){
            maior = v[i];
            nota_alta = i;
        }
    }
    printf("%d\n",nota_alta);
    free(v);
    return 0;
}