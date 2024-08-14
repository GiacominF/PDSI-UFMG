#include <stdio.h>
#include <stdlib.h>

void soma (int matriz1[5][5], int matriz2[5][5], int matrizsoma[5][5]){


    for (int g = 0; g < 5; g++){
        for (int h = 0; h < 5; h++)
            matrizsoma[g][h] = matriz1[g][h] + matriz2[g][h];
    }

}

void matrizes (char *nome){

    int matriz1[5][5];
    int matriz2[5][5];
    int matrizsoma [5][5];

    FILE *numeros = fopen (nome, "r");

     for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(numeros, "%u", &matriz1[i][j]) != 1) {
                perror("Erro ao ler a matriz1 do arquivo");
                fclose(numeros);
                return;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (fscanf(numeros, "%u", &matriz2[i][j]) != 1) {
                perror("Erro ao ler a matriz2 do arquivo");
                fclose(numeros);
                return;
            }
        }
    }
    
    
    fclose (numeros);

    soma (matriz1, matriz2, matrizsoma);

    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++)
            printf ("%u ", matrizsoma[i][j]);
            printf ("\n");
    }

}

int main()
{
    char nome[100];

    while (scanf("%s", nome) != EOF){


    matrizes (nome);

    }
    return 0;
}