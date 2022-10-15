/* This program designed to find out is the number is the number ODD or EVEN by using 'mod'/'%' operator;
If (n%2)== 0 then the number is EVEN, if it is not then the number is ODD
Here,
    Time complexity = O(1) cause here operation count is constant;
    Space complexity = O(1) Cause here we used only one variable for use memory space;
*/

#include <stdio.h>

int main(){

    int n=0;
    //Input a number from User
    printf("Input a number :\a\n");
    scanf("%d",&n);

    //output and condition
    if((n%2)== 0){//check the value with If (n%2)== 0 then the number is EVEN
        printf("This Number is a Even\n");
    }else{//if it is not then the number is ODD
        printf("This Number is a Odd\n");
    }

    return 0;
}
