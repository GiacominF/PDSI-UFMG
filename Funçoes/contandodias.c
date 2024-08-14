#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool anobissexto (int ano){

    if (ano % 4 != 0)
        return false;

    else if (ano % 100 != 0)
        return true;

    else if (ano % 400 != 0)
        return false;

        else return true;
}

int qtddiasmes (int mes, int ano){

    switch (mes){

    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        return 31;

    case 4: case 6: case 9: case 11:
        return 30;

    case 2:
    return anobissexto(ano) ? 29 : 28;

    return 0;

    }
}

int calculardias(int dia, int mes, int ano){

    //Inicializar a diferença de dias igual a 0
    //Estabelecer a data limite
    int diferenca = 0;
    int anofinal = 2020, mesfinal = 9, diafinal = 17;


    //Enquanto houver diferenca entre as datas:
    while (ano < anofinal
           || (ano == anofinal && mes < mesfinal)
           || (ano == anofinal && mes == mesfinal && dia < diafinal)) {

            diferenca++;
            dia++;


            //Caso dia = 30, reseta para 1 e o mes aumenta
            //Caso mês = 12, reseta para 1 e o ano aumenta

            if (dia > qtddiasmes(mes, ano)){
                dia = 1;
                mes++;

            if (mes > 12){
                mes = 1;
                ano ++;
                }

            }
           }

           diferenca += 1;

           return diferenca;


}

int main (){

    int dia, mes, ano;

    while (scanf ("%d %d %d", &dia, &mes, &ano) != EOF){

        int diasdecorridos = calculardias (dia, mes, ano);

        printf ("%d\n", diasdecorridos);



    }
return 0;
}