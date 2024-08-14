#include <stdio.h>
#include <stdlib.h>

int main (){

int numAeds, numCalculo;
scanf ("%d", &numAeds);
int AEDS1 [numAeds];

for (int i = 0; i < numAeds; i++)
scanf ("%d", &AEDS1[i]);


scanf ("%d", &numCalculo);
int CALCULO1 [numCalculo];
for (int i = 0; i<numCalculo; i++)
    scanf ("%d", &CALCULO1[i]);


     for (int i = 0; i< numAeds; i++){
            for (int j = 0; j< numCalculo; j++){
            
    if (AEDS1[i] == CALCULO1[j])
        printf ("%d\n", AEDS1[i]);}}





return 0;
}