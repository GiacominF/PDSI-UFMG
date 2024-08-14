#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    float salario;
} cadastro;

int main() {
    char entrada[15];
    cadastro c[4];
    int contagem = 0;

    while (scanf("%s", entrada) != EOF) {

        if (strcmp(entrada, "inserir") == 0) {
            if (contagem < 4) {
                scanf("%s %d %f", c[contagem].nome, &c[contagem].idade, &c[contagem].salario);
                printf("Registro %s %d %.2f inserido\n", c[contagem].nome, c[contagem].idade, c[contagem].salario);
                contagem++;
            } else {
                printf("Espaco insuficiente\n");
            }
        } else if (strcmp(entrada, "mostrar") == 0) {
            char nomeinserido[50];
            scanf("%s", nomeinserido);

            int encontrado = 0;
            for (int i = 0; i < contagem; i++) {
                if (strcmp(c[i].nome, nomeinserido) == 0) {
                    printf("Registro %s %d %.2f\n", c[i].nome, c[i].idade, c[i].salario);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("Registro ausente\n");
            }
        } 
    }

    return 0;
}