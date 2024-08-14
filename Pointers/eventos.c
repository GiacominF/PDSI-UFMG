#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{

int dia;
int mes;
int ano;

} datas;

typedef struct eventos {

char nome[100];
char local [100];
datas dias;

} evento;

void cadastroeventos(int numero, evento *acontecimento){

    for (int i = 0; i < numero; i++){
    scanf ("%s %s %d %d %d", acontecimento[i].nome, acontecimento[i].local, &acontecimento[i].dias.dia,
        &acontecimento[i].dias.mes, &acontecimento[i].dias.ano);}


}

void buscardata (int dia, int mes, int ano, int numero, evento *acontecimento){


    int encontrado = 0;
    for (int i = 0; i < numero; i++){
    if (dia == acontecimento[i].dias.dia && mes == acontecimento[i].dias.mes &&
        ano == acontecimento[i].dias.ano){

            printf ("%s %s\n", acontecimento[i].nome, acontecimento[i].local);
            encontrado = 1;
        }
        } if (encontrado == 0)
            printf ("Nenhum evento encontrado!");

}


int main()
{
int numero;
evento acontecimento[100];
datas databusca;


scanf ("%d", &numero);

cadastroeventos (numero, acontecimento);

scanf ("%d %d %d", &databusca.dia, &databusca.mes, &databusca.ano);

buscardata (databusca.dia, databusca.mes, databusca.ano, numero, acontecimento);



return 0;
}