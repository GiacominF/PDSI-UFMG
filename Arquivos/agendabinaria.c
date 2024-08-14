#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 100
#define MAX_NOME 50
#define MAX_TELEFONE 20

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char telefone[MAX_TELEFONE];
} Contato;

void salvar_contatos(FILE *arquivo, Contato contatos[], int total_contatos) {
    fseek(arquivo, 0, SEEK_SET);
    fwrite(contatos, sizeof(Contato), total_contatos, arquivo);
    fflush(arquivo);
}

void inserir_contato(FILE *arquivo, Contato contatos[], int *total_contatos, char *nome, int idade, char *telefone) {
    if (*total_contatos >= MAX_CONTATOS) {
        printf("Espaco insuficiente\n");
        return;
    }
    strcpy(contatos[*total_contatos].nome, nome);
    contatos[*total_contatos].idade = idade;
    strcpy(contatos[*total_contatos].telefone, telefone);
    (*total_contatos)++;
    printf("Registro %s %d %s inserido\n", nome, idade, telefone);
    salvar_contatos(arquivo, contatos, *total_contatos);
}

void alterar_contato(FILE *arquivo, Contato contatos[], int total_contatos, char *nome, int idade, char *telefone) {
    for (int i = 0; i < total_contatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            contatos[i].idade = idade;
            strcpy(contatos[i].telefone, telefone);
            printf("Registro %s %d %s alterado\n", nome, idade, telefone);
            salvar_contatos(arquivo, contatos, total_contatos);
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

void excluir_contato(FILE *arquivo, Contato contatos[], int *total_contatos, char *nome) {
    for (int i = 0; i < *total_contatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Registro %s %d %s excluido\n", contatos[i].nome, contatos[i].idade, contatos[i].telefone);
            for (int j = i; j < *total_contatos - 1; j++) {
                contatos[j] = contatos[j + 1];
            }
            (*total_contatos)--;
            salvar_contatos(arquivo, contatos, *total_contatos);
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

void exibir_contato(Contato contatos[], int total_contatos, char *nome) {
    for (int i = 0; i < total_contatos; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            printf("Registro %s %d %s exibido\n", contatos[i].nome, contatos[i].idade, contatos[i].telefone);
            return;
        }
    }
    printf("Registro %s invalido\n", nome);
}

int main() {
    char nome_arquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    FILE *arquivo = fopen(nome_arquivo, "rb+");
    if (!arquivo) {
        arquivo = fopen(nome_arquivo, "wb+");
        if (!arquivo) {
            printf("Erro ao abrir o arquivo\n");
            return 1;
        }
    }

    Contato contatos[MAX_CONTATOS];
    int total_contatos = 0;

    fseek(arquivo, 0, SEEK_END);
    long tamanho_arquivo = ftell(arquivo);
    if (tamanho_arquivo > 0) {
        fseek(arquivo, 0, SEEK_SET);
        total_contatos = fread(contatos, sizeof(Contato), MAX_CONTATOS, arquivo);
    }

    char operacao[10];
    char nome[MAX_NOME];
    int idade;
    char telefone[MAX_TELEFONE];

    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "Inserir") == 0) {
            scanf("%s %d %s", nome, &idade, telefone);
            inserir_contato(arquivo, contatos, &total_contatos, nome, idade, telefone);
        } else if (strcmp(operacao, "Alterar") == 0) {
            scanf("%s %d %s", nome, &idade, telefone);
            alterar_contato(arquivo, contatos, total_contatos, nome, idade, telefone);
        } else if (strcmp(operacao, "Excluir") == 0) {
            scanf("%s", nome);
            excluir_contato(arquivo, contatos, &total_contatos, nome);
        } else if (strcmp(operacao, "Exibir") == 0) {
            scanf("%s", nome);
            exibir_contato(contatos, total_contatos, nome);
        }
    }

    fclose(arquivo);
    return 0;
}