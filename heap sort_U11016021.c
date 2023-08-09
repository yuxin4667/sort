#include<stdio.h>

void heapify(int a[], int length)
{
	int large, i = length / 2, j = length /2;
	while (j >= 1)
	{
		while (i * 2 <= length)
		{
			if (a[i] < a[i * 2] || (a[i] < a[i * 2 + 1] && i * 2 + 1 < length))
			{
				if (i * 2 + 1 <= length)
					large = a[i * 2] > a[i * 2 + 1] ? i * 2 : i * 2 + 1;
				else
					large = i * 2; //只有左子樹的情況

				int temp;
				temp = a[i];
				a[i] = a[large];
				a[large] = temp;

				if (large % 2 == 0)
					i = i * 2; //和左子樹交換，往左子樹的下層比較
				else
					i = i * 2 + 1; //和右子樹交換，往右子樹的下層比較
			}
			else
				break;
		}
		j--;
		i = j;
	}
}

void heapsort(int a[], int length)
{
	int temp;
	while (length != 0)
	{
		heapify(a, length);

		temp = a[1];
		a[1] = a[length];
		a[length] = temp;

		length--;
	}
}

int main(void)
{
	int a[13] = { -1, 3, 10, 12, 8, 7, 11, 2, 0, 4, 1, 6, 5};
	int length = 12;
	printf("BEFORE　HEAPSORT:\n");
	for (int i = 1; i <= length; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	heapsort(a, length);

	printf("\nAFTER　HEAPSORT:\n");
	for (int i = 1; i <= length; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
