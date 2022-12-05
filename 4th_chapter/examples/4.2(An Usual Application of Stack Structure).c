//This a program about Application of Stack to find out if the sequence of brackets are symmetric in c language;

#include <stdio.h>
#include <string.h>

int isBalanced(char input[]);

int main(){
    char input[100];//declaring array for store bracket "()"

    //scanf("%[^\n]", str);

    scanf("%s",input);

    if(isBalanced(input)){//depends on what is returning it show the result on the terminal;
        printf("%s is Balanced \n",input);
    }else{
        printf("%s is not Balanced \n",input);
    }

    return 0;
}

int isBalanced(char input[]){

    char stack[100], lastChar;
    int top, i, lengthStr;

    top = 0;//setting top to the 0;

    lengthStr = strlen(input);//taking length using string function;

    for(i=0; i<lengthStr ; i++){

        if(input[i]=='('){

                stack[top]='(';
                top++;

       }else if(input[i]==')'){

            if(top==0){//checking is stack is empty

                return 0;
            }

            top--;//tehe

            lastChar = stack[top];

            if(lastChar != '('){//here we are checking that is the sequence are okay go to before that we are setting top decreasing by -1 cause if the count of first parenthesis "(" sequence is match the second parenthesis sequence ")" then the sequence is blanced

                return 0;

                }
           }
    }

    if(top == 0){
        return 1;
    }else{
        return 0;
    }
}
