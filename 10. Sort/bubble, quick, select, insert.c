#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
////////////////버블 정렬/////////////////////
void bubble_sort(int *list, int n) {
	int i, j;
	for (i = n - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				swap(&list[j], &list[j + 1]);
			}
		}
	}
}
////////////////퀵 정렬///////////////////////
int partition(int *list, int left, int right) {
	int pivot;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (low <= right && list[low] < pivot);
		do
			high--;
		while (high >= left && list[high] > pivot);
		if (low < high) swap(&list[low], &list[high]);
	} while (low < high);
	swap(&list[left], &list[high]);
	return high;
}
void quick_sort(int *arr,int left, int right) {
	if (left < right) {
		int q = partition(arr, left, right);
		quick_sort(arr, left, q - 1);
		quick_sort(arr, q + 1, right);
	}
}
//////////선택 정렬/////////////////
void select_sort(int *arr,int n) {
	int min;
	int J;
	for (int i = 0; i < n-1; i++) {
		min = arr[i];
		J = 0;
		for (int j = i+1; j < n; j++) {
			if (min > arr[j]) {
				min = arr[j];
				J = j;
			}
		}
		if (J != 0) {
			swap(&arr[i], &arr[J]);
		}
	}
}
////////////삽입정렬/////////////////
void Insert_sort(int *arr, int n) {
	int key,j,i;
	for (i = 1; i < n; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
		}
}
////////////////////////////////////
int main(void) {
	int arr[9] = { 5,2,3,1,7,6,4,9,8};
	//Insert_sort(arr,9);
	//quick_sort(arr, 0,8);
	bubble_sort(arr, 9);
	for (int i = 0; i < 9; i++) {
		printf("%d->", arr[i]);
	}
	return 0;
}