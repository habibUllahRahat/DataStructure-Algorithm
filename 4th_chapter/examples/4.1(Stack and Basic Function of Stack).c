///This a program about to how to define a Stack structure in c language;

#include <stdio.h>
#define MaxDataSize 20 /// this is a global variable which for define the max length of the stack array

typedef struct{// defining a structure
    int top;//for track the stack top or last index
    int data[MaxDataSize];//array for the store the data
}StackCustom;

void push(StackCustom *s, int item);
int pop(StackCustom *s);

int main(){

    StackCustom aStack;// declaring a stack Name "aStck"
    int item;


    aStack.top=0;//Setting top to 0 cause the stack is empty at first

    printf("top is now (in push) : %2d\n",aStack.top); //checking changes of "top" "of aStack"
    push(&aStack,18); /// push(first_Argument, second_argument)first argument : we are sending address of "aStack" cause we will add the value to the address and push accept pointer cause it will change directly "aStack"
                    /// second Argument : its take a integer value which will  be stored in stack;

    printf("top is now (in push) : %2d\n",aStack.top);
    push(&aStack,47);

    printf("top is now (in push) : %2d\n",aStack.top);
    push(&aStack,22);



    ///pop() Function also take address as a parameter;
    item = pop(&aStack);
    printf("top is now (in pop) : %2d\n",aStack.top); //checking changes of "top" "of aStack"
    (item == -1)? printf("There is nothing found\n"): printf("Returned value from stack : %3d \n" ,item);


    item = pop(&aStack);
    printf("top is now (in pop) : %2d\n",aStack.top);
    (item == -1)? printf("There is nothing found\n"): printf("Returned value from stack : %3d \n" ,item);


    item = pop(&aStack);
    printf("top is now (in pop) : %2d\n",aStack.top);
    (item == -1)? printf("There is nothing found\n"): printf("Returned value from stack : %3d \n" ,item);


    return 0;
}

void push(StackCustom *s, int item){

    if (s->top < MaxDataSize){//checking is stack is full

        s->data[s->top] = item;//storing data to the top or the last index
        s->top++;// moving top by 1 index

    }else{

        printf("This stack is full!");//Showing index is full to the user
    }
}

int pop(StackCustom *s){

    int item;

    if(s->top == 0){//Checking is the stack is empty or not
        printf("Stack is Empty !! Insert something to print");
        return -1;
    }else{

        s->top = s->top-1;
        return item = s->data[s->top];
    }
}
