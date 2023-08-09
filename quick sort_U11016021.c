#include<stdio.h>

int partition(int A[], int p, int r)
{
	int i = p, j = r, x = A[p];

	while (i < j) 
	{
		while (A[i] < x)
			i++;
		while (A[j] > x)
			j--;

		int temp;
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	return j;
}

void QuickSort(int A[], int p, int r)
{
	int cut;
	if (p < r) 
	{
		cut = partition(A, p, r);
		QuickSort(A, p, cut);
		QuickSort(A, cut+1, r);
	}

}

int main(void)
{
	int A[10] = { -1, 3, 6, 5, 8, 7, 1, 2, 0, 4 };

	printf("BEFORE　QUICKSORT:\n");
	for (int i = 1; i <= 9; i++)
		printf("%d ", A[i]);
	printf("\n\n");

	QuickSort(A, 1, 9);

	printf("\nAFTER　QUICKSORT:\n");
	for (int i = 1; i <= 9; i++)
		printf("%d ", A[i]);
	printf("\n");
	return 0;
}
