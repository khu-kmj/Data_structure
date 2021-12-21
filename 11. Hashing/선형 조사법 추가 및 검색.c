#include <stdio.h>
#define MAX 7
#define hash_function(x) ((x) % MAX)
int hash_table[MAX] = { 0 };

void insert(int num) {
	int i;
	int hash_index = i =hash_function(num);
	while (hash_table[i] != 0) {
		i = (i + 1) % MAX;
		if (i == hash_index)
			printf("Table is overflowed\n");
	}
	hash_table[i] = num;
}

	//====================이차 조사법====================
	void hash_insert(int item) {
		int i;
		int a = 1;
		int index = i = hash_function(item);
		while (ht[i] != 0) {
			i = (index + a * a) % MAX;
			a++;
			if (i == index)
				printf("Table is overflowed\n");
		}
		ht[i] = item;

	}
	//==================이중 해시법=========================
	void hash_insert(int item) {
		int i;
		int a = 1;
		int index = i = hash_function(item);
		int j = C - item % C;
		while (ht[i] != 0) {
			i = (index + j * a) % MAX;
			a++;
			if (i == index)
				printf("Table is overflowed\n");
		}
		ht[i] = item;
	}
int search(int num) {
	int i;
	int hash_index = i = hash_function(num);
	while (hash_table[i] != 0) {
		if (num == hash_table[i])
			return i;
		i = (i + 1) % MAX;
		if (i == hash_index)
			return -1;
	}
	return -1;
}
void main(void) {
	insert(8);
	insert(1);
	insert(9);
	insert(6);
	insert(13);
	for (int i = 0; i < MAX; i++)
		printf("[%d] : %d\n",i, hash_table[i]);
	printf("index : [%d]",search(1));
}