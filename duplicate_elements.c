#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int maxi(int A[], int a)
{
	int m = A[0];
	for (int i = 1; i < a; i++)
	{
		if (A[i] > m)
			m = A[i];
	}
	return m;
}
int mini(int A[], int a)
{
	int m = A[0];
	for (int i = 1; i < a; i++)
	{
		if (A[i] < m)
			m = A[i];
	}
	return m;
}
int main()
{
	int l, h, n;
	printf("Enter no. of elements in array : ");
	scanf("%d", &n);
	int* A = (int*)malloc(n * sizeof(int));
	printf("Enter elements: ");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	h = maxi(A, n);
	l = mini(A, n);
	int range = h - l + 1;
	int* H = (int*)calloc(range, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		H[A[i]]++;
	}
	for (int i = 0; i <= h; i++)
	{
		if (H[i] > 1)
		{
			printf("%d has %d duplicates\n",i,H[i]);
		}
	}
	free(A);
	free(H);
	return 0;
}
