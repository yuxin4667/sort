//insertion sort code

#include<stdio.h>

int main(void)
{
	int A[9] = { 3, 6, 5, 8, 7, 1, 2, 0, 4 };
	int i, j;

	//A[i]:插入值
	for (i = 1; i < 9; i++) 
	{
		//尋找插入點
		for (j = 0; j < i; j++) 
		{
			if (A[i] < A[j])
				break;
		}

		//插入
		if (j < i) 
		{
			int temp = A[i];
			for (int k = i - 1; k >= j; k--)
				A[k + 1] = A[k];
			A[j] = temp;
		}
	}

	for (int i = 0; i < 9; i++)
		printf("%d ", A[i]);

	return 0;
}
