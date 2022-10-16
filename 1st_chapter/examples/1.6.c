//!! This program will show the status of nested loop and its time and space complexity

#include <stdio.h>

int main (){
    //Declaration of variable
    int i,j,n,count=0;
    //Input variable from the user
    printf("Input value of n :\n");
    scanf("%d",&n);

    // declaring an array of n`th length
    int nList[n+1];

    // Calculating "count" for how many time a nested loop executing an operation
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            count++;
            nList[i]=count;
        }

    }
    //printing what was the  count's value at which  iteration
    for(i=1; i<=n; i++){
        printf("count at %3d iteration of i :  %d\n",i,nList[i]);
    }
    // printing total calculation of  count
     printf("count : %d \n",count);
    return 0;
    }
/*!! Conclusion : when ever we input a number as n we can see the output we get which is equivalent to the n^2. so the number of execution of an operation is relative for nested loop and iteration count is equivalent to n^2 thats mean it will take n^2 times to execute the code and we declared an array call "nList", this array's memory space depends on n.
                                            So,
                                            Time complexity of this program = O(n^2);
                                            Space complexity of this program = O(n);
!!*/
