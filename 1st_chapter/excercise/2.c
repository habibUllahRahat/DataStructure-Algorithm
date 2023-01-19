//stdio.h is a library header file which stands for Standard Input Output this library contains all standard input & output functions
#include <stdio.h>

int main(){
    //declaring the variable for use
    	int i,j,k,n;
    	int count=0;

    //Taking input from user
    	printf("Please input the n : \n");
    	scanf("%d",&n);

    //Declaring an array of n+1 size
    long nList[n][n][n];
    //Processing section
	for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
        	for(k=0 ; k<n ; k++){
                count++;
                nList[i][j][k]=count;
            }
        }
	}
    //Output what was the  count's value at which  iteration
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
        	for(k=0 ; k<n ; k++){
             printf("Iteration of i :  %3d\nIteration of j :  %3d\nIteration of k :  %3d\nAt this point Count is : %3d \n\n",i,j,k,nList[i][j][k]);
            }
        }
	}
	//output
    printf("n = %d,\n Count = %d",n,count);
    return 0;
}
