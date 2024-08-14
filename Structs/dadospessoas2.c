#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[50];
    int idade;
    float salario;
    char rua[50];
    int numero;
    char estado[50];

} cadastro;

int main() {
    char entrada[15];
    cadastro c[5];
    int contagem = 0;

    while (scanf("%s", entrada) != EOF) {

        if (strcmp(entrada, "inserir") == 0) {
            if (contagem < 5) {
                scanf("%s %d %f %s %d %s", c[contagem].nome, &c[contagem].idade, &c[contagem].salario, c[contagem].rua, &c[contagem].numero, c[contagem].estado);
                printf("Registro %s %d %.2f %s %d %s inserido\n", c[contagem].nome, c[contagem].idade, c[contagem].salario, c[contagem].rua, c[contagem].numero, c[contagem].estado);
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
                    printf("Registro %s %d %.2f %s %d %s\n", c[i].nome, c[i].idade, c[i].salario, c[i].rua, c[i].numero, c[i].estado);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
                printf("Registro ausente\n");

        }

            else if (strcmp(entrada, "alterar")== 0){
                char nomeinserido[50];
                scanf ("%s", nomeinserido);


                int encontrado = 0;
            for (int i = 0; i < contagem; i++) {
                if (strcmp(c[i].nome, nomeinserido) == 0) {


                        int novaidade;
                        float novosalario;
                        char novarua[50];
                        int novonumero;
                        char novoestado[50];

                    scanf("%d %f %s %d %s", &novaidade, &novosalario, novarua, &novonumero, novoestado);

                    c[i].idade = novaidade;
                    c[i].salario = novosalario;
                    strcpy(c[i].rua, novarua);
                    c[i].numero = novonumero;
                    strcpy(c[i].estado, novoestado);


                    printf("Registro %s %d %.2f %s %d %s alterado\n", c[i].nome, c[i].idade, c[i].salario, c[i].rua, c[i].numero, c[i].estado);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado)
                printf("Registro ausente para alteracao\n");

            }
    }

    return 0;
}