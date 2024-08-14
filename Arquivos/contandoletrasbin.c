#include <stdio.h>
#include <stdlib.h>

void contarletra (char *nome){

   FILE *frase = fopen(nome, "rb");

    int contagem = 0;
    int caracter;
    while ((caracter = fgetc(frase)) != EOF){

        if (caracter == 'a')
            contagem++;
        
        
    } fclose (frase);

    printf ("%d", contagem);

}


int main()
{
  char nome[100];

  while ((scanf ("%s", nome)) != EOF)
    contarletra (nome);


    return 0;
}