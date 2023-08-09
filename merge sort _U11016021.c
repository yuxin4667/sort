#include<stdio.h>

void MergeSort(int*, int*, int, int);
void Merge(int*, int*, int, int, int);

void MergeSort(int *A, int* B, int low, int high)
{
	int m = (low + high) / 2;
	if (low < high)
	{
		MergeSort(A, B, low, m);
		MergeSort(A, B, m + 1, high);
		Merge(A, B, low, m, high);
	}
	else
		return;
}

void Merge(int* A, int* B, int low, int m, int high)
{
	int i = low, j = m + 1, k = low;
	while (i <= m && j <= high)
	{
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		}
		else {
			B[k] = A[j];
			j++;
		}
		k++;
	}

	while (i <= m) {
		B[k] = A[i];
		i++;
		k++;
	}

	while (j <= high) {
		B[k] = A[j];
		j++;
		k++;
	}

	for (int i = low; i <= high; i++)
		A[i] = B[i];
}

int main(void)
{
	int A[9] = { 3, 6, 5, 8, 7, 1, 2, 0, 4 };
	int B[9];

	printf("BEFORE MERGE SORT:");
	for (int i = 0; i < 9; i++)
		printf("%d ", A[i]);

	MergeSort(A, B, 0, 8);

	printf("\n AFTER MERGE SORT:");
	for (int i = 0; i < 9; i++)
		printf("%d ", A[i]);

	return 0;
}