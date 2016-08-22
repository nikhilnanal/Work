/* This file contains Heap creation and heap sort
algorithm implementation. 
A Heap is a Data structure which can be imagined to be in the form of a Binary tree. A Heap Data structure follows 
the following property, the value of the root node is greaterthan both its left child and the right child. Also both 
the left subtree and the right subtree of the root follow this property. Also the left sub tree 
Although it can be visualized easily like a binary tree, it is often stored as an array, where if the parent node is at the
ith index the children are at (left : 2*i + 1; right : 2*i + 2)th location. Also note that elements at indices N/2+1 to N 
are all leaft nodes in the Binary tree visualization ( Ref: CLRS for diagrams)

#include <stdio.h>
#include <stdlib.h>

// A possible way to store Heap.
typedef struct Heap
{
        int heapsize;
        int* Array;
} Heap;
// find the left child of the nth index
int left(int n)
{
        return ((2 * n) + 1);
}
// find the right child of the nth index
int right(int n) 
{
        return ((2 * n) + 2);
}

// This is  a recursive algorithm which makes the root node maximum if it is not and then recursively ensure that the child node
// also satisfies the Heap property.
static void MaxHeapify(Heap H, int i)
{
        int l = left(i);
        int r = right(i);
        int largest;

        if (( H.Array[l] >= H.Array[i]) && l < H.heapsize) {
                largest = l;
        }
        else {
                largest = i;
        }
        if ((H.Array[r] >= H.Array[largest]) && (r < H.heapsize)) {
                largest = r;
        }       
        if (largest != i) {
                int temp = H.Array[i];
                H.Array[i] = H.Array[largest];
                H.Array[largest] = temp;
                MaxHeapify(H, largest);
        }

}
/* Heap Sort operates on a Heap. swaps the Max element (0th index/first element of the array) with the last element 
to place the max value in the end. Then reduces the heapsize by 1 and applies MaxHeapify to the remaining N-1 elements
of the heap. Eventually, the largest elements are placed towards the right and smallest to the left.
void Heapsort(Heap H)
{
        int j = H.heapsize - 1;
        while (j>=0) {
                int temp = H.Array[0];
                H.Array[0] = H.Array[j];
                H.Array[j] = temp;
                H.heapsize--;
                MaxHeapify(H, 0);
                j--;
        }
}


// It defines an array, calls max-heapify from n/2 to 0 to make a heap out of the array. Then Invokes the heapsort
// algorithm to sort the array in ascending order.
int main()
{
        Heap H;
        int n,i;
        printf("enter the size of the heap you want to construct\n");
        scanf("%d\n",&n);
        H.Array = malloc(sizeof(int) * n);
        H.heapsize = n;

        for (i = 0; i < H.heapsize; i++) {
                scanf("%d", &(H.Array[i]));
                printf("\t%d\n",H.Array[i]);
                        }

        printf(" Heap:  ");
        for (i = (H.heapsize/2); i >= 0; i--) {
        MaxHeapify(H,i);
        }
        for (i = 0; i < H.heapsize; i++) {
                printf("%d\t", H.Array[i]);
        }
        Heapsort(H);
        printf("\nSorted Array: ");
        for (i = 0; i < H.heapsize; i++) {
                printf("%d\t", H.Array[i]);
        }

free (H.Array);
}


