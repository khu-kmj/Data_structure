#include <stdio.h>

int fibo(int n) {
	if (n < 2) 
		return n;
	else 
		return fibo(n - 2) + fibo(n - 1);
}

int main() {
	printf("fibo(15) : %d\n", fibo(15));
	return 0;
}