#include <stdio.h>

void main() {
  
  int a = 1234;
  printf("a = %d \n", a);
  printf("sizeof(a) = %d \n", sizeof(a));
  
  int* ptr = &a;
  // &a is the address of variable a
  // the int* means a pointer to the address of a type int variable
  
  printf("ptr = %d \n", ptr);
  // the memory address of the variable a, &a
  
  printf("*ptr = %d \n", *ptr);
  // What is stored in the memory address ptr? Exactly the value of a
    
}
