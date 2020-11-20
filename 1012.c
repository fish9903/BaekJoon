#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
	int T;		// rep number of times
	int m, n;	// size (m * n)
	int cabbage;		// number of cabbage
	
	scanf("%d", &T);

	while (T--)
	{
		bool extend = true;

		int arr[50][50] = { 0, };
		int worm = 0;

		scanf("%d %d %d", &m, &n, &cabbage);

		for (int i = 0; i < cabbage; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);

			arr[x][y] = 1;
		}

		while (true)
		{
			bool find = false;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (arr[i][j] == 1)
					{
						worm++;
						arr[i][j] = 2;
						find = true;
						break;
					}
				}
				if (find == true) break;
			}
			if (find == false) break;

			do
			{
				extend = false;

				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						if (arr[i][j] == 2)
						{
							if (i > 0 && arr[i - 1][j] == 1) { arr[i - 1][j] = 2; extend = true; }
							if (i < m - 1 && arr[i + 1][j] == 1) { arr[i + 1][j] = 2; extend = true; }
							if (j > 0 && arr[i][j - 1] == 1) { arr[i][j - 1] = 2; extend = true; }
							if (j < n - 1 && arr[i][j + 1] == 1) { arr[i][j + 1] = 2; extend = true; }
						}
					}
				}
			} while (extend == true);
		}
		printf("%d\n", worm);
	}



	

	return 0;
}