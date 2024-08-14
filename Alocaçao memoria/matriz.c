#include <stdio.h>
#include <stdlib.h>

int main()
{
    int qtdlinhas;
    int qtdcolunas;

    scanf ("%d", &qtdlinhas);
    scanf ("%d", &qtdcolunas);

    int **matriz;
    matriz = (int **) malloc(qtdlinhas* sizeof(int *));

    for (int i = 0; i <qtdlinhas; i++){
        matriz[i] = (int *) malloc(qtdcolunas * sizeof(int));
        for (int j = 0; j < qtdcolunas; j++){
            scanf (" %d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < qtdlinhas; i++){
        for (int j = 0; j < qtdcolunas; j++){
        printf ("%d ", matriz[i][j]);

        } printf ("\n");
    }


    for (int i = 0; i < qtdlinhas; i++)
        free (matriz[i]);

    free (matriz);




    return 0;
}