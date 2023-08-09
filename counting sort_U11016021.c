#include<stdio.h>
#define RANGE 5

int main(void)
{
	int A[11] = { 0, 3, 1, 1, 5, 3, 5, 4, 1, 4, 1 };
	int B[11] = { 0 };
	int C[RANGE+1] = { 0 };

	printf("BEFORE COUNTING SORT:\n");
	for (int i = 1; i <= 10; i++)
		printf("%d ", A[i]);
	printf("\n");

	for (int i = 1; i <= 10; i++)
		C[A[i]]++;

	for (int i = 1; i <= RANGE; i++)
		C[i] = C[i - 1] + C[i];

	for (int i = 1; i <= 10; i++)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	printf("AFTER COUNTING SORT:\n");
	for (int i = 1; i <= 10; i++)
		printf("%d ", B[i]);
	printf("\n");

	return 0;

}
