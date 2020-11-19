#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int rep;
	int a, b;

	scanf("%d", &rep);

	while (rep--)
	{
		scanf("%d %d", &a, &b);

		int result = a;

		while (b > 4)
			b = b % 4;

		if (b == 0) b = 4;

		for (int i = 0; i < b - 1; i++)
			result = result * a;

		result %= 10;
		if (result == 0) result = 10;

		printf("%d\n", result);
	}
	
	return 0;
}