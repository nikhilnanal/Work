*******************************************************************************/

#include <iostream>

using namespace std;



int partition(int A[], int start, int end){
    
    int pIndex = start;
    int pivot = A[end];
    int  i = start;
    int temp;
    while (i < end) {
            if (A[i] <= pivot){
                temp = A[pIndex];
                A[pIndex] = A[i];
                A[i] = temp;
                pIndex++;
            }
            i++;
    }

    temp = A[pIndex];
    A[pIndex] = A[end];
    A[end] = temp;
    return pIndex;
    
}
void quicksort(int A[], int start, int end){
    
    if(start < end) {
            int pIndex = partition(A,start, end);
            quicksort(A, start, pIndex-1);
            quicksort(A,pIndex+1, end);
    }
    
}
int main()
{
    int A[6] = {13,2,7,6,9,4};
    quicksort(A,0,5);
    
    for (int i = 0; i < 6; i++){
        cout << A[i] <<" ";
    }
    return 0;
}
