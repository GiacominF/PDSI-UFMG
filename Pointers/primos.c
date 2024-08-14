#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


    bool primo(int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

    void primos (int m, int *p1, int *p2){

    int menorPrimo = m - 1;
    int maiorPrimo = m + 1;

    while (menorPrimo > 1 && !primo(menorPrimo)) {
        menorPrimo--;
    }
    *p1 = menorPrimo;

     while (!primo(maiorPrimo)) {
        maiorPrimo++;
    }
    *p2 = maiorPrimo;


    printf ("%d\n", *p1);
    printf ("%d", *p2);

    }

int main()
{
    int m;
    int p1, p2;
    scanf ("%d", &m);

    primos (m, &p1, &p2);





    return 0;
}