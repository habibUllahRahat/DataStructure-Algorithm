//This a program about Binary searching in c language;

#include <stdio.h>

int binarySearch (int A[] ,int valueToFind ,int sizeOfA);
int selectionSort(int sizeOfArr, int *p);

int main(){
    int n,i,valueToSearch,temp; //declaring the variable for store size of array, iteration controller & store what user searching array;

    printf("How Many Element you want for the Array : ");
    scanf("%d",&n);//taking the size of desired array

    int arr[n];
    int *p;
    p = &arr[0];

    printf("Input Element for the Array :\n");
    for(i=0; i<n ; i++){ // taking array elements as input from user
        scanf("%d",&arr[i]);
    }

    printf("Value to search on array :\n");
    scanf("%d",&valueToSearch);//taking input for which element user want to find element want to search;


    temp = binarySearch(arr, n, valueToSearch);
    (temp == -1) ? printf("not found") : printf("found at %d", temp);
    return 0;
}

//Sorting Function(Selection sorting)

int selectionSort(int sizeOfArr, int *p){

    int i,j, indexMin, temp;

    for(i=0; i<sizeOfArr-1;i++){

            indexMin = i;

                for(j=i+1;j<sizeOfArr;j++){
                    if(*(p+j) < *(p+indexMin)){
                        indexMin=j;
                    }
                }

                if(indexMin != i){
                    /*temp = *(p+i);
                    *(p+i) = *(p+indexMin);
                    *(p+indexMin) = temp;*/
                    *(p+i) += *(p+indexMin);
                    *(p+indexMin) = *(p+i) - *(p+indexMin);
                    *(p+i) = *(p+i) - *(p+indexMin);

                }
    }
}

int binarySearch(int A[], int sizeOf, int searchFor){
    selectionSort(sizeOf , &A[0]);
    int left, mid, right;

    left = 0;
    right = sizeOf-1;

    while(left <= right){
        mid = (left+right)/2;
        if(A[mid]==searchFor){
            return mid;
        }
        if(A[mid]<searchFor){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }

return -1;
}








