#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
int top = -1;
int ST[MAX];

int is_empty() {
	return top == -1;
}
int is_full() {
	return ST[top] == MAX - 1;
}
char pop() {
	if (is_empty()) {
		printf("괄호가 맞지 않습니다!\n");
		exit(1);
	}
	else return ST[top--];
}
void push(char item) {
	if (is_full()) {
		printf("ST FULL!!\n");
		exit(1);
	}
	else ST[++top] = item;
}
int main(void) {
	char a[] = { "{a[bc](e(fg))}" };
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] == '}' || a[i] == ')' || a[i] == ']') {
			char check = pop();
			if (a[i]=='}' &&(check=='(' || check=='[') || a[i] == ')' && (check == '[' || check == '{') || a[i] == ']' && (check == '(' || check == '{')) {
				printf("괄호가 맞지 않습니다!");
				exit(1);
			}
		}
		if (a[i] == '{'  || a[i] == '(' || a[i] == '[')
			push(a[i]);
	}
	if (!is_empty())
		printf("괄호가 맞지 않습니다!");
	else
		printf("괄호가 맞습니다!");
	return 0;
}