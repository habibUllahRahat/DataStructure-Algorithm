#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name [40];
};

int main() {
    struct Student one, two;

    one.id = 10;
    // one.name = "Habib Ullah Rahat";// this will show error char[40] not accessable cause we can only asign a value to aarray when we first time declear it;

    // We can solve this using strcpy() function;
    strcpy(one.name, "Habib Ullah Rahat");
    printf("ID : %d\n", one.id);
    printf("Name : %s\n", one.name);

    // Strcuture with input
    scanf("%d", &two.id);
    scanf(" %[^\n]", two.name);

    printf("ID : %d\n", two.id);
    printf("Name : %s\n", two.name);


    return 0;
}