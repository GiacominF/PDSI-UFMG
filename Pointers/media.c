#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calcularmedia(double vet[], int tamanho, int *i){

    double media = 0;

    for (int j = 0; j < tamanho; j++)
        media += vet[j];

    media = media / tamanho;

    double diferenca = fabs (vet[0] - media);
    //Inicialmente, a primeira posição é assumida como a mais próxima da média
    *i = 0;

    for (int j = 1; j < tamanho; j++){

        double diferencaatual = fabs (vet[j] - media);
        if (diferencaatual < diferenca){
            diferenca = diferencaatual;
            *i = j;
        }
    }

    printf ("%d", *i);

}


int main()
{

   int tamanho;
   scanf ("%d", &tamanho);

   double vet[tamanho];
   int i = 0;
   for (i = 0; i < tamanho; i++)
    scanf ("%lf", &vet[i]);

    calcularmedia(vet, tamanho, &i);

    return 0;
}