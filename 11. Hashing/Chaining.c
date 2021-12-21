#include <stdio.h>
#include <stdlib.h>
#define HSZ 7
#define HASHING(x) ((x)%HSZ)
typedef struct node_t {
	int val;
	struct node_t *next;
}node;
node *hash_table[HSZ];
void init(void) {
	for (int i = 0; i < HSZ; i++)
		hash_table[i] = NULL;
}
void insert_hash(int value) {
	node *newnode = (node *)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->val = value;
	int mod = HASHING(value);
	node *temp = hash_table[mod];
	if (hash_table[mod] == NULL) {
		hash_table[mod] = newnode;
	}
	else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
	}
}
int delete_hash(int value) {
	int mod = HASHING(value);
		if (hash_table[mod]->val == value) {
			hash_table[mod] = hash_table[mod]->next;
			return 1;
		}
		else {
			node *cur = hash_table[mod]->next;
			node *bef = hash_table[mod];
			if (cur == NULL) {
				return 0;
			}
			while (cur->val != value ) {
				cur = cur->next;
				bef = bef->next;
				if (cur == NULL)
					return 0;
			}
			if (cur == NULL) {
				return 0;
			}
			else {
				bef->next = cur->next;
				free(cur);
				return 1;
			}
		}
	
}
void Display() {
	for (int i = 0; i < HSZ; i++) {
		node *temp = hash_table[i];
		printf("hash_table[%d] : ", i);
		while (temp != NULL) {
			printf("%d->", temp->val);
			temp = temp->next;
		}
		printf("\n");
	}
}
void main(void) {
	init();
	insert_hash(8);
	insert_hash(1);
	insert_hash(9);
	insert_hash(6);
	insert_hash(13);
	insert_hash(15);
	Display();
	int a = delete_hash(22);
	Display();
	printf("%d", a);

}