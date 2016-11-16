#include <stdio.h>
#include <stdlib.h>

int main(void) {
    
    int*** arr;
    int row =3,col =3, height =3;
    int i=0, j=0,k=0;
    arr = malloc(sizeof(int)* row);
    for ( i=0;i<row;i++)
    {
        arr[i] = malloc(sizeof(int) * col);
    }
    for (i =0;i<row;i++){
        for (j =0;j<col;j++){
            arr[i][j] = malloc(sizeof(int) * height);
        }
    }
    for (i=0;i<row;i++){
        for (j=0;j<col;j++){
            for (k=0;k<height;k++){
                printf("address: %p\t", &arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
   
    return 0;
}
