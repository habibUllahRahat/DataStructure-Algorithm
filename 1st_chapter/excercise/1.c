//!! What is the Space Complexity and  Complexity ( usually when we use only  the word "Complexity"  it's refer to "Time Complexity" ) of the program given below;

//stdio.h is a library header file which stands for Standard Input Output this library contains all standard input & output functions
/*This #include section call preprocessing module and #include <stdio.h> will load before the  start the execution of int main (which is the main function)*/

#include <stdio.h>

int main()
{
    //declaring the variable for use
    int i,n,count=0;

    //Taking Output from the user
    printf("Please input the n : \n");
    scanf("%d",&n);

    //processing section
    for(i=0; i<n ; i++){
        count++;
    }

    //output
    printf("n = %d,\nCount = %d",n,count);
    return 0;
}










































































/*!!Conclusion : The usage of space here is constant and time to execution is it iterate n times
        so,
        Space Complexity = O(1);
           Complexity = O(1)+O(n)=O(n);
