#include <stdio.h>
#include <stdlib.h>

int main (){

    //Entradas:
  int qtdjogos, n , nmrjogadas, x,y;

  //Ler quantidade de jogos e **limitar**:
  scanf ("%d", &qtdjogos);



  //Tamanho matriz com tamanho maximo:
 int matriz [100][100];




    for (int jogo = 0; jogo < qtdjogos; jogo++){
        //Ler tamanho matriz (n) e **limitar**:
    scanf ("%d", &n);
    int m = n;



  //Ler elementos inseridos:

  int i, j;
  for (i = 0; i < n; i++){
        for (j = 0; j < m; j++)
            scanf(" %c", (char*)&matriz[i][j]);
        }



   //Ler número jogadas:
   scanf ("%d", &nmrjogadas);


   //Ler as jogadas: limitejogadas: k
   //Criar matriz dos pares ordenados: [x][y]
   //Verificar se os quadrados adjacentes contem a bomba:
    int k;
        int encontrouB = 0;
        for (k = 0; k < nmrjogadas; k++){
            scanf("%d %d", &x, &y);


            //testa se o par ordenado escolhido é bomba
            //Se não for, ele revela todos x adjacentes
                  if (matriz[x][y] == 'b'){


                        encontrouB = 1;}

                            if (matriz[x-1][y-1] != 'b')
                            matriz[x-1][y-1] = 0;

                            if (matriz[x-1][y] != 'b')
                            matriz[x-1][y] = 0;

                            if (matriz[x-1][y+1] != 'b')
                            matriz[x-1][y+1] = 0;

                            if (matriz[x][y-1] != 'b')
                            matriz[x][y-1] = 0;

                            if (matriz[x][y+1] != 'b')
                            matriz[x][y+1] = 0;

                            if (matriz[x+1][y-1] != 'b')
                            matriz[x+1][y-1] = 0;

                            if (matriz[x+1][y] != 'b')
                            matriz[x+1][y] = 0;

                            if (matriz[x+1][y+1] != 'b')
                            matriz[x+1][y+1] = 0;}


                                if (encontrouB == 1)
                                    printf ("PERDEU\n");



                                        else{

//Avaliar se falta algum lugar ainda não descoberto:

int a, b;
int valor = 0;
for (a=0; a <= n; a++){
      for (b = 0; b<= m; b++){
            if (matriz[a][b] == 'x'){
               valor = 1;
            }

      }
}
if (valor == 1)
    printf ("FALTOU TERMINAR\n");

        else printf ("GANHOU\n");







                                        }}
return 0;
}