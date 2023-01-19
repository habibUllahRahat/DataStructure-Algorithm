///This a program about Insertion sort in c language;

#include <stdio.h>

void bubblSort (int sizeOfA , int *p);

int main(){
    int n,i,valueToSearch; //declaring the variable for store size of array, iteration controller & store what user searching array;

    printf("How Many Element you want for the Array : ");
    scanf("%d",&n);//taking the size of desired array

    int arr[n]; // declaring

    printf("Input Element for the Array :\n");
    for(i=0; i<n ; i++){ // taking array elements as input from user
        scanf("%d",&arr[i]);
    }

    insertionSort(n, &arr[0]);// calling function for the sort array using Insertion sort function
    printArr(arr,n);// calling printArr for print sorted array
    return 0;
}

//function for sort an array using Insertion sort
void insertionSort (int sizeOfA , int *p){
    int i, j;
    for(i=0 ; i < sizeOfA ; i++){
            int item;
            item = *(p+i);
            j=i-1;
            while (j>=0 && *(p+j) > item){

                    *(p+(j+1)) = *(p+j)  ;
                    j--;
                }

                *(p+(j+1)) = item;
        }
    }


//function for print an array
void printArr(int a[], int sizeOfArr){
    int i;
    for(i=0; i<sizeOfArr; i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
}

