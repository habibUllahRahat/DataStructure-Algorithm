//This a program about linear searching in c language;

#include <stdio.h>

void linearSearch (int A[] ,int valueToFind ,int sizeOfA);

int main(){
    int n,i,valueToSearch; //declaring the variable for store size of array, iteration controller & store what user searching array;

    printf("How Many Element you want for the Array : ");
    scanf("%d",&n);//taking the size of desired array

    int arr[n];

    printf("Input Element for the Array :\n");
    for(i=0; i<n ; i++){ // taking array elements as input from user
        scanf("%d",&arr[i]);
    }

    printf("Value to search on array :\n");
    scanf("%d",&valueToSearch);// desired element to find the index of

    linearSearch(arr, valueToSearch, n);// function for the linear searching

    return 0;
}

//function for linear function
void linearSearch(int A[],int valueToFind ,int sizeOfA){
    int i;
    for(i=0 ; i<sizeOfA ; i++){
        if(A[i] == valueToFind){
            printf("The index of %d found at %d no index",valueToFind,i);
            break;
        }
    }
    printf("The index of %d not found in this array",valueToFind);

}
