#include <stdio.h>
#include <stdlib.h>

int* fill(int* array, int length) {
	for (int i = 1; i < length; i++) {
		array[i] = rand() % 100;
	}
	return array;
}

void print(int* array, int length) {
	for (int i = 1; i < length; i++) {
		printf("%d ", array[i]);
	}
}

int* sort(int* array, int length) {
	int compare = 0, rearrange = 0, i, j, element;
	for (i = 1; i < length; i++) {
		element = array[i];
		array[0] = element;
		j = i - 1;
		while (array[j] > element) {
			compare++;
			rearrange++;
			array[j + 1] = array[j];
			j = j - 1;
		}
		rearrange++;
		array[j + 1] = element;
	}

	printf("\ncompare: %d, rearrange: %d\n", compare, rearrange);
	return array;
}

int main()
{
	int* array, *array2, length = 30;
	array = (int*)malloc(sizeof(int*) * length + 1);
	array = fill(array, length + 1);
	print(array, length + 1);
	array2 = sort(array, length + 1);
	print(array2, length + 1);
}