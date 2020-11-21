#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

void swap(int* left, int* right);
void bubble_sort(int arr[], int count);

#define SIZE 26

int main(void)
{
	int n;	// Size of map
	int map[SIZE][SIZE] = { 0, };	// Initialize map to 0
	int arr[SIZE*(SIZE/2) + 1] = { 0 };	// This array stores number of type of apartment

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	int count = 0;	// Number of type of apartment
	int tmp1 = 2;	// Number to change (1 -> 2, 1->3, ...)
	int tmp2;		// Store tmp1
	int number = 0;	// Index of arr

	while (true)
	{
		bool flag = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] == 1)
				{
					map[i][j] = tmp1;
					tmp2 = tmp1;
					tmp1++;
					count++;
					flag = true;
					break;
				}
			}
			if (flag)	break;
		}
		if (flag == false)	break;	// no more 1 left

		bool extend;

		do
		{
			extend = false;
			
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (map[i][j] == tmp2)
					{
						if (arr[number] == 0)
							arr[number]++;

						if (i > 0 && map[i - 1][j] == 1)	//	left
						{
							arr[number]++;
							map[i - 1][j] = tmp2;
							extend = true;
						}
						else if (i < n - 1 && map[i + 1][j] == 1)	//	right
						{
							arr[number]++;
							map[i + 1][j] = tmp2;
							extend = true;
						}
						else if (j > 0 && map[i][j - 1] == 1)	//	above
						{
							arr[number]++;
							map[i][j - 1] = tmp2;
							extend = true;
						}
						else if (j < n - 1 && map[i][j + 1] == 1)	//	bottom
						{
							arr[number]++;
							map[i][j + 1] = tmp2;
							extend = true;
						}
					}
				}
			}
		} while (extend);

		number++;
	}

	printf("%d\n", count);

	bubble_sort(arr, count);

	for (int i = 0; i < count; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}

void swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void bubble_sort(int arr[], int count)
{
	for (int i = 0; i < count; i++)
	{
		for (int j = i; j < count; j++)
		{
			if (arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
		}
	}
}