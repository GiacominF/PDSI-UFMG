#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome [50];
    char marca [50];
    float valor;

} produto;

typedef struct {
    char marca[50];
    int contagem;
    float valores;

} contagem_marca;

int main()
{
   produto p[8];
   contagem_marca marcas[8];
   int nummarcas = 0;
   //Ler os 8:

   for (int i=0; i < 8; i++){
    scanf ("%s %s %f", p[i].nome, p[i].marca, &p[i].valor);
   }


   //Definir a quantidade de todas as marcas igual a 0:
   for (int i = 0; i < 8; i++){
    marcas[i].contagem = 0;
    marcas[i].valores = 0;
    }


    //Contar a quantidade de produtos de cada marca:
    for (int i = 0; i< 8; i++){
        int j;
        for (j = 0; j <nummarcas; j++){
                //Verifica se a marca do produto já está na lista
            if (strcmp (marcas[j].marca, p[i].marca) == 0){
                //Se estiver, incrementa a contagem da marca
                //Acrescenta valor a marca:
                marcas[j].valores += p[i].valor;
                marcas[j].contagem ++;
                break;
            }
        }


        //Se a marca não estava na lista:
    if (j == nummarcas){
        strcpy(marcas[nummarcas].marca, p[i].marca);
        marcas[nummarcas].valores = p[i].valor;
        marcas[nummarcas].contagem = 1;
        nummarcas++;
    }}

    for (int i = 0; i < nummarcas; i++) {
        printf("%s %d\n", marcas[i].marca, marcas[i].contagem);
    }

    //Média total:
    float soma;

    for (int m = 0; m<8 ; m++){
        soma += p[m].valor;
    }
     float media = soma / 8.0;
     printf ("media total %.2f\n", media);



     for (int v = 0; v < nummarcas; v++) {
        float mediamarcas = marcas[v].valores / marcas[v].contagem;
        printf("media %s %.2f\n", marcas[v].marca, mediamarcas);
    }

    return 0;
}