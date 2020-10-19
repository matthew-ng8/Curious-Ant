#include <stdio.h>
#include "stack.h"

pos stack [MAX_SIZE];     
int top = 0;     

int isempty () {

   if (top == 0)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if (top == MAX_SIZE)
      return 1;
   else
      return 0;
}

pos peek () {
  if (top != 0)
   return stack[top - 1];
  else 
  	printf ("Stack is empty\n");
}

pos pop () {
   pos data;

   if (isempty() != 1) {
      data = stack [top - 1];
      top = top - 1;   
      return data;
   } 
   else
      printf("Error: Stack is empty\n");
}

void push (pos data) {

   if (isfull() == 0)
   	  stack[top++] = data;   
    else 
      printf("Error: Stack is full\n");
}

void clear () {
	top = 0;
}
