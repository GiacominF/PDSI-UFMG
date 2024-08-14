#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// n = valor que o usuário insere
// x = todos números até o primo n (apenas incrementa o valor caso seja primo)



//Avaliar se é primo:
//Recebe x como parâmetro e retorna 0 ou 1
bool primo(long long int x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (long long int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

//Somar os n primeiros numeros primos:
//Recebe o valor digitado pelo usuario e retorna sua soma
long long int somaprimos (int n){
        long long int contagem = 0;
        long long int valor = 0;
        long long int x = 2;

        //Enquanto a contagem de numeros for menor que a qual o usuario inseriu:
        while (contagem < n){
            if (primo(x)){
            valor += x;
            contagem ++;
        }
            x++;
     }

        return valor;
}

int main()
{
    int n;

    //Enquanto o usuario digita:
   while (scanf("%d", &n) != EOF) {
         long long int valor = somaprimos(n);


         printf ("%lld\n", valor);



    }




    return 0;
}