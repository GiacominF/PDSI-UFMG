#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct flor{

 float comprimentosepala;
 float largurasepala;
 float comprimentopetala;
 float largurapetala;
 char tipo[50];

} iris;

void distancia(iris *flornaoidentificada, iris *flores, int n){

    float valor[n];

     for (int i = 0; i < n; i++) {
        valor[i] = sqrt(
            pow(flores[i].comprimentosepala - flornaoidentificada->comprimentosepala, 2) +
            pow(flores[i].largurasepala - flornaoidentificada->largurasepala, 2) +
            pow(flores[i].comprimentopetala - flornaoidentificada->comprimentopetala, 2) +
            pow(flores[i].largurapetala - flornaoidentificada->largurapetala, 2)
        );
    }


    float menor = valor[0];
    int posicaoflormenor = 0;

    for (int i = 1; i < n; i++){
        if (valor[i] < menor){
        menor = valor[i];
        posicaoflormenor = i;
    }}

    printf ("%s", flores[posicaoflormenor].tipo);


}


int main()
{
   int n;
   scanf ("%d", &n);

   iris flores[n];
   iris flornaoidentificada;

   int i = 0;
   for (i = 0; i < n; i++)
    scanf ("%f %f %f %f %s", &flores[i].comprimentosepala, &flores[i].largurasepala, &flores[i].comprimentopetala,
           &flores[i].largurapetala, flores[i].tipo);

    scanf ("%f %f %f %f", &flornaoidentificada.comprimentosepala, &flornaoidentificada.largurasepala,
           &flornaoidentificada.comprimentopetala, &flornaoidentificada.largurapetala);


    distancia (&flornaoidentificada, flores, n);

    return 0;
}