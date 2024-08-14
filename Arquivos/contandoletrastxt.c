#include <stdio.h>
#include <stdlib.h>


//Função para calcular 'a'
//Não retorna nada


//nomearquivo armazena o nome do arquivo a ser processado
void contarletra (char *nomearquivo){
    FILE *frase = fopen (nomearquivo, "r");




        //Analisa a quantidade do carácter 'a' na frase:
        int contagem = 0;
        int caracter;
        while ((caracter = fgetc(frase)) != EOF) {
                if (caracter == 'a')
                    contagem++;}


    fclose(frase);

        printf ("%d", contagem);

}


//Main recebe como argumentos de entrada:
int main(int qtdarquivos, char *nomedosarquivos[]) {

for (int i = 1; i < qtdarquivos; i++) {
        //"Escaneia" o nome do arquivo enquanto for menor que a quantidade
        //Chamar a função para contar as letras 'a' na frase
        char *nomearquivo = nomedosarquivos[i];
        contarletra (nomearquivo);}
        
    return 0;

}