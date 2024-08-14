#include <stdio.h>
#include <stdlib.h>

int main (){
    int A [1000][1000];
    int i, j;
    int x, y;
    scanf ("%d %d", &x, &y);

    for (i= 0; i<x ; i++){
        for (j = 0; j < y; j++)
        scanf ("%d", &A[i][j]);
    }
int B [1000][1000];
        for (int i= 0; i<x ; i++){
            for (int j = 0; j < y; j++) {
                 B[i][j]= -1 * A[i][j];
            printf ("%d\n", B[i][j]);
            }
           
    }


 return 0;
}
