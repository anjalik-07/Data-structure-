#include<stdio.h>
#include<string.h>
int pValidation (char str[])
{
  int i ,top=-1;
  char s[20];
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

    }


    void main()
    {
     char str[20];
     printf("enter a sequence of parenthesis:\n");
     scanf("%s",&str);
     if(pValidation(str))
        printf("\nparenthesis sucessfully validated");
     else
        printf("\invalid parenthesis sequence");
  }



