#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool anobissexto (int ano){

//Se não for divisível por 4
    if (ano % 4 != 0)
        return false;

//Se não for divisível por 100
    else if (ano % 100 != 0)
        return true;
    
    
    else if (ano % 400 != 0) 
        return false;
        
        else return true;
}

int main()
{
    int ano;
    while (scanf ("%d", &ano) != EOF){
            
            
            if (anobissexto(ano) == 1)
                printf ("1\n");
        
            else printf ("0\n");
        
    }
    
    return 0;
}