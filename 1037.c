#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N_n;	// N�� ��¥ ��� ����
	int min, max;	// ��¥ ��� �� �ִ�, �ּ�

	scanf("%d", &N_n);

	int* arr = malloc(sizeof(int) * N_n);

	for (int i = 0; i < N_n; i++)
	{
		scanf("%d", &arr[i]);
	}

	min = arr[0];

	for (int i = 0; i < N_n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}

	max = arr[0];

	for (int i = 0; i < N_n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	printf("%d", min * max);
	
	return 0;
}