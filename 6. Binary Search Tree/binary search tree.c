#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct Node {
	int data;
	struct Node *L;
	struct Node *R;
}Node;
Node *del(Node *tree,int item) {
	Node *parent, *temp, *child, *succ_p, *succ;
	parent = NULL;
	temp = tree;
	while (temp!=NULL && temp->data != item) {
		parent = temp;
		if (item < temp->data)
			temp = temp->L;
		else
			temp = temp->R;
	}
	if (temp->R == NULL && temp->L==NULL) {
		if (parent->L == temp)
			parent->L = NULL;
		else
			parent->R = NULL;
	}
	else if (temp->R==NULL || temp->L==NULL) {
		if (temp->L == NULL) {
			child = temp->R;
		}
		else {
			child = temp->L;
		}
		if (parent->L == temp)
			parent->L = child;
		else
			parent->R = child;
	}
	else {
		succ_p = temp;
		succ = temp->R;
		while (succ->L != NULL) {
			succ_p = succ;
			succ = succ->L;
		}
		if (succ_p->L == succ)
			succ_p->L = succ->R;
		else
			succ_p->R = succ->R;
		temp->data = succ->data;
		temp = succ;
	}
	return tree;
}
Node *insert(Node *tree,int item) {
	Node *temp, *parent;
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->L = newnode->R = NULL;
	newnode->data = item;
	temp = tree;
	parent = NULL;
	while (temp != NULL) {
		if (item == temp->data)return 0;
		parent = temp;
		if (item < temp->data)
			temp = temp->L;
		else
			temp = temp->R;
	}
	if (parent != NULL)
		if (item < parent->data)
			parent->L = newnode;
		else
			parent->R = newnode;
	else
		tree = newnode;

	return tree;
}
//////////전위순회////////////
void disp(Node *tree) {
	if (tree) {
		printf("%d  ", tree->data);
		disp(tree->L);
		disp(tree->R);
	}
}
//////////중위순회////////////
void disp1(Node *tree) {
	if (tree) {
		disp1(tree->L);
		printf("%d  ", tree->data);
		disp1(tree->R);
	}
}
//////////후위순회////////////
void disp2(Node *tree) {
	if (tree) {
		disp2(tree->L);
		disp2(tree->R);
		printf("%d  ", tree->data);
	}
}
int main(void) {
	Node *tree=NULL;
	int data[10];
	//srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 10+1;
		for (int j = 0; j < i; j++) {
			if (data[i] == data[j]) {
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++)
		tree = insert(tree, data[i]);
	disp(tree);
	printf("\n");
	disp1(tree);
	printf("\n");
	disp2(tree);
	printf("\n");
	printf("\n");
	tree = del(tree, 9);
	disp(tree);
	printf("\n");
	disp1(tree);
	printf("\n");
	disp2(tree);
	printf("\n");
	printf("\n");
	tree = del(tree, 3);
	disp(tree);
	printf("\n");
	disp1(tree);
	printf("\n");
	disp2(tree);
	printf("\n");
	printf("\n");
	tree = del(tree, 2);
	disp(tree);
	printf("\n");
	disp1(tree);
	printf("\n");
	disp2(tree);
	printf("\n");
	return 0;
}