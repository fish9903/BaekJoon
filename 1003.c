#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int rep;
	int n;
	int arr[41] = { 0,1,1 }; // Using recursion function takes too much memory and time. 
							 // So, we make an array which contains fibonacci's values.
							 // We can access fibonacci's values through this array.

	for (int i = 3; i < 41; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	scanf("%d", &rep);

	while (rep--)
	{
		scanf("%d", &n);

		if (n == 0)
			printf("%d %d\n", 1, 0);
		else if (n == 1)
			printf("%d %d\n", 0, 1);
		else
			printf("%d %d\n", arr[n - 1], arr[n]);
	}

	return 0;
}