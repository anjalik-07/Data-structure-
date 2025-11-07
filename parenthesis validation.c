#include <stdio.h>
#include <string.h>

int pValidation(char str[]) {
    int i, top = -1;
    char s[20];

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            s[++top] = str[i];
        else if (str[i] == ')' && top != -1 && s[top] == '(')
            top--;
        else if (str[i] == ']' && top != -1 && s[top] == '[')
            top--;
        else if (str[i] == '}' && top != -1 && s[top] == '{')
            top--;
        else
            return 0;
    }

    return top == -1;
}

void main() {
    char str[20];
    printf("Enter a sequence of parentheses:\n");
    scanf("%s", str);  // No need for & with arrays
    if (pValidation(str))
        printf("\nParentheses successfully validated\n");
    else
        printf("\nInvalid parentheses sequence\n");
}
