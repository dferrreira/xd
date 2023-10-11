#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int atual = 0, maior = 0;
    //int arr[] = {-1, -2, -3, -4};
    //int arr[] = {1, 2, 3, -2, 5};
    int arr[] = {1, 2, 3, -8, 5, 6};
    //int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    //int arr[] = {74, -72, 94, -53, -59, -3, -66, 36, -13, 22, 73, 15, -52, 75};
    //int arr[] = {9, -51, -20, -13, -51, 40, -21, 75, -24, 29, -86, 5, -38, 15, 48, -87, -9, 42, 39, 64, 47, -63, 22, -81, -20, -100, 28};
    //int arr[] = {23, 41, 84, -8, 42, -54, 1, 2, 28, 49, -32, -16, -33, -44, -100, -30, 68, -47, 59, -94, 35, -18};
    maior = arr[0];
    for(int i = 0; i < sizeof(arr)/4; i++) {
        
        printf("INTERACAO %d: \n\n", i);
        /*
        if(arr[i] < 0){
            if(atual > 0){

                if(atual > maior)
                    maior = atual;
                if(atual <= abs(arr[i]))
                    atual = abs(arr[i]);
            
            }else if(atual < 0){
                
                if(atual > arr[i])
                    maior = atual;

            }
        }else if(arr[i] > 0){
            if(atual < 0){

                if(arr[i] > maior)
                    atual = 0;
                else if(abs(atual) <= arr[i])
                    atual = 0;

                maior = arr[i];
            }

        }

        */

        if(atual < 0 && arr[i] > 0)
            atual = 0;

        atual += arr[i];

        if(atual > maior)
            maior = atual;
        printf("%d %d\n", atual, maior);

    }

    printf("%d\n", maior);
    return 0;
}