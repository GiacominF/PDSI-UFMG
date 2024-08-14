#include <stdio.h>
#include <stdlib.h>

void imprimir (int tamanhovet, int *vet){

    for (int i = 0; i < tamanhovet; i++){
        printf ("%d ", vet[i]);
    } printf ("\n");
}

void multiplicar (int tamanhovet, int *vet, double multiplicador){

    int resultado[tamanhovet];
    int resultado2[tamanhovet];

    int i = 0;
    for (i = 0; i < tamanhovet; i++){
        resultado[i] = vet[i] * multiplicador;
    }

    for (int i = 0; i < tamanhovet; i++){
        resultado2[i] = resultado[i] * (1/multiplicador);
    }

    imprimir (tamanhovet, resultado);
    imprimir (tamanhovet, resultado2);


}

int main()
{

 int tamanhovet;
 scanf ("%d", &tamanhovet);
 int vet[tamanhovet];
 double multiplicador;
 

 for (int i = 0;i < tamanhovet; i++){
    scanf ("%d", &vet[i]);
 }

 scanf ("%lf", &multiplicador);

 imprimir(tamanhovet, vet);
 multiplicar (tamanhovet, vet, multiplicador);

    return 0;
}