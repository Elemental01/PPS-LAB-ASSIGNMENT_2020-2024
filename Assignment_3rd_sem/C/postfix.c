
#include<stdio.h> 
#include<ctype.h> 
#include<math.h> 
#define MAXSIZE 10 
int stack[MAXSIZE],tos=-1; 
void push(int x){ 
 if(tos==MAXSIZE-1){ 
  printf("Stack overflow\n"); 
 } 
 else{ 
  tos++; 
  stack[tos]=x; 
 } 
} 
 
int pop(){ 
 int y=-1; 
 if(tos==-1){ 
  printf("Stack underflow\n"); 
 } 
 else{ 
  y=stack[tos]; 
  tos--; 
 } 
 return y; 
} 
 
int main(){ 
 char s[100]; 
 int i,v=0,x=0,y=0,z=0; 
 printf("Enter a postfix expression-"); 
 gets(s); 
 while(s[i]!='\0'){ 
  if(isalpha(s[i])){ 
   printf("Enter the value of operand %c-\n",s[i]); 
   scanf("%d",&v); 
   push(v); 
  } 
  else{ 
   x=pop(); 
   y=pop(); 
   switch (s[i]){ 
    case '+':z=y+x; 
    break; 
    case '-':z=y-x; 
    break;  
    case '*':z=y*x; 
    break;  
    case '/':z=y/x; 
    break; 
    case '^':z=pow(y,x); 
    break; 
   } 
   push(z); 
  } 
  i++; 
 } 
 printf("\nThe evaluated value of postfix expression is- %d",stack[tos]); 
 return 0; 
}