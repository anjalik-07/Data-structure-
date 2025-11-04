#include<stdio.h>
#define SIZE 10
void push(int);
void pop();
void display();
int stack [SIZE];
 int top=-1;

void main()
{
int n,ch;
while (1)
{
  printf("\n 1.push ,2.pop,3.display,4.exit\n");
  printf("enter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:printf("enter value to insert:");
          scanf("%d",&n);
          push(n);
          break;
    case 2:pop();
          break;
    case 3:display();
          break;
    case 4:exit(0);
    default:printf("invalid");
  }
}
}
void push ( int n )
{
  if (top==SIZE-1)
  {
     printf("stack full");
  }
  else
  {
    top++;
    stack[top]=n;
    printf("\n insertion sccesful \n");
  }
}
void pop()
{
   if (top==-1)
   {
      printf("stack empty ");
   }
   else
   {
      printf("\n deleted %d",stack[top]);
      top--;
   }
}

void display(){
if (top == -1 )
  printf("\nstack is empty!!!");
else{
     int i ;
     printf("\n stack elements are:\n");
     for(i=top;i>=0;i--)
        printf("%d\n",stack[i]);
    }
  }
