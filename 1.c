#include <stdio.h>

int comparisons = 0;
int swaps = 0;

void SelectionSort(int A[], int n);

int main(void)
{
	int a[] = {6, 8, 14, 17, 23};
	int b[] = {17, 23, 14, 6, 8};
	int c[] = {23, 17, 14, 8, 6};

	SelectionSort(a, 5);
	printf("%d, %d\n", comparisons, swaps);
	comparisons = 0;
	swaps = 0;

	SelectionSort(b, 5);
	printf("%d, %d\n", comparisons, swaps);
	comparisons = 0;
	swaps = 0;

	SelectionSort(c, 5);
	printf("%d, %d\n", comparisons, swaps);
}

void SelectionSort(int A[], int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		int small = i;
		for (int j = i+1; j < n; ++j)
		{
			if (A[j] < A[small])
				small = j;
			++comparisons;
		}

		// count number of meaningful swaps
		if (A[small] != A[i])
			++swaps;

		int temp = A[small];
		A[small] = A[i];
		A[i] = temp;
	}
}