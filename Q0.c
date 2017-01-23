/* CS261 - Assignment 1 - Q. 0*/
/* Name: Kristine Catimbang
 * Date: 1/23/2017
 * Solution Description: fooA prints the value and address pointed to by iptr, and the address of iptr. 
 * fooB assigns c to the value of a+b, assigns a to b, b to double its value, and returns the value of c.
 * The main function gets an integer x, and prints the address and value of x.
 */

#include <stdio.h>
#include <stdlib.h>

int fooB(int* a, int* b, int c){
	c = *a + *b;
	*a = *b;
	*b = (2)*(*b);

	return c;
}

void fooA(int* iptr){
	printf("Value pointed to by iptr: %d\n", *iptr);
	printf("Address pointed to by iptr: %p\n", iptr);
	printf("Address of iptr: %p\n", &iptr);

}

int main(){
	int x;

	printf("Address of x: %p\n", &x);
	fooA(&x);

	printf("Value of x: %d\n", x);

	return 0;
}
