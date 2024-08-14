#include <stdio.h>
#include <stdlib.h>

void lerelementos(int tamanho, int *vetor){

    for (int i = 0; i < tamanho; i++)
        scanf("%d", &vetor[i]);

return 0;
}

int main()
{
    int tamanho;
    scanf ("%d", &tamanho);

    int *vetor;
    vetor =(int *) malloc (tamanho * sizeof(int));

    lerelementos(tamanho, vetor);

    for (int i = 0; i < tamanho; i++){
        printf ("%d\n", vetor[i]);
    }

    free (vetor);


    return 0;
}