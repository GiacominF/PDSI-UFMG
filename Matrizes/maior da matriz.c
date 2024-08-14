#include <stdio.h>
#include <stdlib.h>

int main (){
int x, y;
int A[1000][1000];
scanf ("%d %d", &x , &y);
int i, j;
int maior;

for (i = 0; i < x; i++){
for (j = 0; j < y; j++)
scanf ("%d", &A[i][j]);
}

maior = A[0][0];
for (i = 0; i < x; i++){
     for (j = 0; j < y; j++)

        if (A [i][j] > maior)
        maior = A[i][j];
}
printf ("%d", maior);

return 0;
}