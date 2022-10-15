/*This is same program as 1.2 but using formula here Loop used */

int  main(){
    int n, sum=0;

    //taking input from user
    printf("Please input a number you wanna result for : \n");
    scanf("%d",&n);
    //calculation
    for(int i=1; i<=n; i++){
        sum +=i;
    }
    printf("The Result is : %d \n \a",sum);
return 0;
}
