#include<stdio.h>
#include<malloc.h>

void printArray(int* A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1); 
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp; 
            }
        }  
    } 
}

void bubbleSortAdaptive(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++) // For number of pass
    {
        printf("Working on pass number %d\n", i+1);
        isSorted = 1;
        for (int j = 0; j <n-1-i ; j++) // For comparison in each pass
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        } 
        //isSorted kadhi 0 zalach nahi mnje ekpn swap zal nahi
        if(isSorted) //if(True i.e. 1)
        {
            return;
        }
    } 
}

int main()
{
    int size = 0;
    int *A;
    int i=0;
    printf("Eneter size of Array\n");
    scanf("%d",&size);
    A=(int*)malloc(size*sizeof(int));

    for(i=0;i<size;i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Array before sorting\n");
    printArray(A, size); // Printing the array before sorting

    printf("Array After sorting\n");
    bubbleSort(A, size); // Function to sort the array
    printArray(A, size);

    printf("Array after adaptive sorting\n");
    bubbleSortAdaptive(A,size);
    printArray(A, size);                                         
    return 0;
}