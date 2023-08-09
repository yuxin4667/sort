#include<stdio.h>
#define R 10
#define N 12
#define DIGIT 3

void RadixSort(int* A)
{
	int times = 1;
	for (int D = 1; D <= DIGIT; D++)
	{
		int bucket[R][N] = { 0 };
		int count[R] = { 0 };
		int lsd, k = 0;

		for (int i = 0; i < N; i++)
		{
			lsd = A[i] / times % R;
			bucket[lsd][count[lsd]] = A[i];
			count[lsd]++;
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < count[i]; j++)
			{
				A[k] = bucket[i][j];
				k++;
			}
		}
		times = times * R;
	}
}

int main(void)
{
	int A[N] = { 23, 33, 24, 21, 14, 13, 35, 12, 2, 32, 4, 11 };

	printf("BEFORE RADIX SORT:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	RadixSort(A);

	printf("AFTER RADIX SORT:\n");
	for (int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}
