//A program to count 1+2+3+4+5+.......+n using formula n*((n+1)/2)
//Here the time complexity T = O(1);

#include <stdio.h>

int main(){
    int n, sum=0;

    //taking input from user
    printf("Please input a number you wanna result for : \a \n");
    scanf("%d",&n);
    //calculation
    sum = n* ((n+1)/2);
    printf("The Result is : %d",sum);

return 0;
}
