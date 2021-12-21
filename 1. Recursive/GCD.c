#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	if (a == 0)
		return b;
	else 
		return gcd(b, a % b);
}

int main() {
	printf("GCD(15,12) : %d\n", gcd(15,12));
	return 0;
}