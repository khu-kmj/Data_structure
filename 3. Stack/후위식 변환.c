#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
int ST[MAX];
int top = -1;

int is_empty() {
	return top == -1;
}
int is_full() {
	return ST[top] == MAX - 1;
}
char pop() {
	if (is_empty()) {
		printf("ST EM!!!");
		exit(1);
	}
	else return ST[top--];
}
void push(char a) {
	if (is_full()) {
		printf("ST FULL!!!");
		exit(1);
	}
	else ST[++top]=a;
}
char peek() {
	return ST[top];
}
int prec(char ch) {
	switch (ch) {
	case '(':
		return 0;
	case ')':
		return 0;
	case '+' :
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 3;
	}
}
int main(void) {
	char a[] = { "a+b*c-(d*e+f)*g" }; 
	char ch, top_ch;
	for (int i = 0; i < strlen(a); i++) {
		ch = a[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			while (!is_empty() && (prec(ch) <= prec(peek())))
				printf("%c", pop());
			push(ch);
		}
		else if (ch == '(')
			push(ch);
		else if (ch == ')') {
			top_ch = pop();
			while (top_ch != '(') {
				printf("%c", top_ch);
				top_ch = pop();
			}
		}
		else
			printf("%c", ch);
	
	}
	while (!is_empty()) {
		printf("%c", pop());
	}

	return 0;
}