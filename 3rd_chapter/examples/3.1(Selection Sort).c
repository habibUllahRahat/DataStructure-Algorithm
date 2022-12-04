///This a program about Selection sort in c language;

#include <stdio.h>


int selectionSort(int sizeOfArr, int *p);
void printArr(int a[], int sizeOfArr);

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
    selectionSort(n, &arr[0]);// calling function for the sort array using Selection sort function
    printArr(arr,n);// calling printArr for print sorted array
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


void printArr(int a[], int sizeOfArr){
    int i;
    for(i=0; i<sizeOfArr; i++){
        printf("%d, ",a[i]);
    }
    printf("\n");
}
