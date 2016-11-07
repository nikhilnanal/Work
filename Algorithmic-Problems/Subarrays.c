#include <stdio.h>
#include <stdlib.h>

void printsubarrays(int Arr[], int N) 
{
        int power = 1<<N; //2^N
        int i =0;
        int tmp =1;
        while (tmp < power) {
                
                for ( i = 0; i < N; i++) {
                        if (tmp & (1<<i)){
                                printf("%d\t",Arr[i]);
                        }
                }
                printf("\n");
                tmp++;
        } 
}
int main() {

int N;
printf(" enter the size of the array\n");
scanf("%d",&N);
int *Arr= malloc(sizeof(int) * N);
int x;
int i =0;
        for(i = 0; i < N; i++) {
                scanf("%d",&x);
                Arr[i] = x;
        }
        printsubarrays(Arr,N);

}
