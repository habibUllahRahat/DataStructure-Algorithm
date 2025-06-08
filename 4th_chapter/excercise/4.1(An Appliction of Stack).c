//This a program about Application of Stack to find out if the sequence of brackets are symmetric in c language;

#include <stdio.h>
#include <string.h>

int isBalanced(char input[]);

int main() {
    char input[100];
    //scanf("%[^\n]", str);
    scanf("%s", input);

    if(isBalanced(input)) {
        printf("%s is Balanced \n", input);
    } else {
        printf("%s is not Balanced \n", input);
    }

    return 0;
}

int isBalanced(char input[]) {

    char stack[100], lastChar;
    int top, i, lengthStr;

    top = 0;

    lengthStr = strlen(input);

    for(i = 0; i < lengthStr ; i++) {

        if(input[i] == '(') {

            stack[top] = '(';
            top++;

        } else if(input[i] == '{') {

            stack[top] = '{';
            top++;

        } else if(input[i] == '[') {

            stack[top] = '[';
            top++;

        } else if(input[i] == ')') {

            if(top == 0) { //checking is stack is empty
                return 0;
            }
            top--;
            lastChar = stack[top];
            if(lastChar != '(') {
                return 0;
            }
        } else if(input[i] == '}') {
            if(top == 0) { //checking is stack is empty
                return 0;
            }
            top--;
            lastChar = stack[top];
            if(lastChar != '{') {
                return 0;
            }
        } else if(input[i] == ']') {
            if(top == 0) { //checking is stack is empty
                return 0;
            }
            top--;
            lastChar = stack[top];
            if(lastChar != '[') {
                return 0;
            }
        }

    }
    if(top == 0) {

        return 1;

    } else {

        return 0;

    }

}
