#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//Criar a struct dos produtos
typedef struct produtos {

int codigo;
char nome[100];
int quantidade;
float preco;
char estado[3];

} p;

void ordenacao(int quantidadeprodutos, p *prod){
    for (int i = 0; i < quantidadeprodutos; i++){
        for (int j = i + 1; j < quantidadeprodutos; j++){
           if (strcmp (prod[i].nome, prod[j].nome) > 0){
               p temp = prod[i];
               prod[i] = prod[j];
               prod[j] = temp;
           }
            
        }
    }
}



void caso1(int quantidadeprodutos, p *prod, char *parametro){


    ordenacao (quantidadeprodutos, prod);
    FILE *arquivo2 = fopen (parametro, "w");

    for (int i = 0; i < quantidadeprodutos; i++){
        fprintf (arquivo2, "%d\n%s\n%d\n%.2f\n%s\n", prod[i].codigo, prod[i].nome, prod[i].quantidade, prod[i].preco, prod[i].estado);

    } fclose (arquivo2);

}


void caso2 (int quantidadeprodutos, p *prod, char *parametro){

    int procurarcodigo;
    procurarcodigo = atoi(parametro);

    for (int i = 0; i < quantidadeprodutos; i++){

    if (prod[i].codigo == procurarcodigo)
    printf ("%d\n%s\n%d\n%.2f\n%s\n", prod[i].codigo, prod[i].nome, prod[i].quantidade, prod[i].preco, prod[i].estado);
}

}


void caso3 (int quantidadeprodutos, p *prod){

    int menor = 0;
    for (int i = 1; i < quantidadeprodutos; i++){
        if (prod[i].quantidade < prod[menor].quantidade)
            menor = i;
    }

    printf ("%d\n%s\n%d\n%.2f\n%s\n", prod[menor].codigo, prod[menor].nome,
            prod[menor].quantidade, prod[menor].preco, prod[menor].estado);



}


void caso4 (int quantidadeprodutos, p *prod, char *parametro){

    ordenacao (quantidadeprodutos, prod);

    for (int i = 0; i < quantidadeprodutos; i++){
    if (strcmp (parametro, prod[i].estado) == 0){
        printf ("%d\n%s\n%d\n%.2f\n%s\n", prod[i].codigo, prod[i].nome, prod[i].quantidade, prod[i].preco, prod[i].estado);
        }
    }


}

void caso5 (int quantidadeprodutos, p *prod, char *parametro){

    int menor = -1;
    for (int i = 1; i < quantidadeprodutos; i++){
        if (strcmp (parametro, prod[i].estado) == 0){
                
           if (menor == -1 || prod[i].quantidade < prod[menor].quantidade)
           menor = i;
        
    }} printf ("%d\n%s\n%d\n%.2f\n%s\n", prod[menor].codigo, prod[menor].nome, prod[menor].quantidade, prod[menor].preco, prod[menor].estado);


}

void caso6 (int quantidadeprodutos, p *prod){
    
    int total = 0;
    for (int i = 0; i < quantidadeprodutos; i++)
        total += prod[i].quantidade;

        printf ("%d", total);
}



int main(int argc, char *argv[])

{
    //NomeArquivo:
    char *nomearquivo = argv[1];
    //Numero operação:
    int operacao = atoi(argv[2]);
    //Parametro:
    char *parametro = argv[3];

    //Criar as 1000 structs:
    p prod[1000];


        char quantidadeprodutos[5];
        int numeroprodutos;
        FILE *arquivo = fopen (nomearquivo, "r");

        fscanf (arquivo, "%s", quantidadeprodutos);
        numeroprodutos = atoi(quantidadeprodutos);

        for (int i = 0; i < numeroprodutos; i++){
            fscanf(arquivo, "%d\n%[^\n]\n%d\n%f\n%s\n", &prod[i].codigo, prod[i].nome, &prod[i].quantidade, &prod[i].preco, prod[i].estado);

        } fclose (arquivo);


        if (operacao == 1)

        caso1(numeroprodutos, prod, parametro);


        else if (operacao == 2)

        caso2 (numeroprodutos, prod, parametro);


        else if (operacao == 3)

        caso3 (numeroprodutos, prod);


        else if (operacao == 4)

        caso4 (numeroprodutos, prod, parametro);


        else if (operacao == 5)
        
        caso5 (numeroprodutos, prod, parametro);
        
        
        else if (operacao == 6)
            
        caso6 (numeroprodutos, prod);

    return 0;
}