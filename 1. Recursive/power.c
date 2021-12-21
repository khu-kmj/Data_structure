#include <stdio.h>

int power(int x, int n) {
	if (n == 0) 
		return 1;
	else if (n % 2 == 0) 
		return power(x * x, n / 2);
	else 
		return x * power(x * x, (n - 1) / 2);
}

int main() {
	printf("3^5 : %d\n", power(3, 5));
	return 0;
}