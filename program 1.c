#include <stdio.h>


struct Student {
    char name[20];
    int marks;
};

int main() {
    struct Student s1, s2;
    printf("Enter name of Student 1: ");
    scanf("%s", &s1.name);
    printf("Enter marks of Student 1: ");
    scanf("%d", &s1.marks);

    printf("Enter name of Student 2: ");
    scanf("%s", s2.name);
    printf("Enter marks of Student 2: ");
    scanf("%d", &s2.marks);


    printf("\nResult:\n");
    if (s1.marks > s2.marks) {
        printf("%s scored more \n", s1.name, s1.marks);
    } else if (s2.marks > s1.marks) {
        printf("%s scored more \n", s2.name, s2.marks);
    } else {
        printf("Both students scored the same marks.\n", s1.marks);
    }

    return 0;
}



