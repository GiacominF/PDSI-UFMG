#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primo(long long int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (long long int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}



int main()
{

    long long int x;
   while (scanf("%lld", &x) != EOF) {
        
    
    if (x<2) printf ("-1\n");

    else if (primo(x)) printf ("1\n");

    else printf ("0\n");

    }




    return 0;
}