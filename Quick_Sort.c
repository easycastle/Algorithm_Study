#include <stdio.h>

int number = 10;
int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}

	int key = start;
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (array[i] <= array[key]) {
			i++;
		}
		while (array[j] >= array[key] && j > start) {
			j--;
		}
		if (i > j) {
			temp = array[j];
			array[j] = array[key];
			array[key] = temp;
		}
		else {
			temp = array[j];
			array[j] = array[i];
			array[i] = temp;
		}
	}

	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main() {
	quickSort(array, 0, number - 1);

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}

	return 0;
}