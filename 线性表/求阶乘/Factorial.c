/*
*求阶乘
*/
#include <stdio.h>
int Factorial(int n) {
	if (n == 0 || n == 1)
		return 1;
	else return n * Factorial(n - 1);
}
void main() {
	printf("%d", Factorial(10));
}
