#include <stdio.h>
#include <stdlib.h>

void somarvetores(int tamanho, int *vetor, int *vetor2, int *vetor3){

    for (int i = 0; i < tamanho; i++)
    scanf ("%d", &vetor[i]);

    for (int i = 0; i < tamanho; i++)
    scanf ("%d", &vetor2[i]);

    for (int i = 0; i < tamanho; i++)
    vetor3[i] = vetor[i] + vetor2[i];

}

int main()
{
   int tamanho;
   scanf ("%d", &tamanho);

   int *vetor;
   int *vetor2;
   int *vetor3;

   vetor  = (int *) malloc(tamanho * sizeof (int));

   vetor2 = (int *) malloc(tamanho * sizeof (int));

   vetor3 = (int *) malloc(tamanho * sizeof (int));

   somarvetores (tamanho, vetor, vetor2, vetor3);

   for (int i = 0; i < tamanho; i++)
        printf ("%d\n", vetor3[i]);

   free (vetor2);
   free (vetor3);
   free (vetor);

    return 0;
}