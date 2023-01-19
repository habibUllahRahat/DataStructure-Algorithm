/* This program designed to find out is the number is the number ODD or EVEN by using an array;
If (n%2)== 0 then the number is EVEN, if it is not then the number is ODD
Here,
    Time complexity = O(1) cause here operation count is constant;
    Space complexity = O(1) Cause here we used only one variable for use memory space;
*/

#include <stdio.h>

int main(){

    int n,odd[100];

    //Input a number from User
    printf("Input a number :\a\n");
    scanf("%d",&n);
    //array initialization using loop
    for(int i=0 ; i<=100 ; i++){
        odd[i]=1;
    }
    for(int i=0 ; i<=100 ; i+=2){
        odd[i]=0;
    }

    //output and condition
    if(odd[n]){//check the value with If the value is 1(True) or 0(False) then the number is EVEN
        printf("This Number is a Odd\n\n");
    }else{//if it is not then the number is ODD
        printf("This Number is a Even\n\n");
    }
    //The benefit of this kind of program than 1.4 program is it can we use this repeat by this we can maintain the DRY principle. For Example :

    int m;
    //Input again another number from User
    printf("Input a number :\a\n");
    scanf("%d",&m);

    // second output
    if(odd[m]){//check the value with If (n%2)== 0 then the number is EVEN
        printf("This Number is a Odd\n");
    }else{//if it is not then the number is ODD
        printf("This Number is a Even\n");
    }
    return 0;
}
