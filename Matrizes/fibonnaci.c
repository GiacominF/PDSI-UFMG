#include <stdio.h>
#include <stdlib.h>


void sequenciafib (int fib[], int n){
    
    fib [0] = 0;
    fib [1] = 1;
    
    for (int i = 2; i <= n; i++)
    fib [i] = fib [i-1] + fib [i-2];
    
}

int main (){
    
    int n;
    int fib [801];
    
while (1){
    scanf ("%d", &n);
    if (n<0 || n > 800) break;
    sequenciafib (fib, n);
 printf ("%d\n", fib[n]);
}
    
    
    
    
    return 0;
}