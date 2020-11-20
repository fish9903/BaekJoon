#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	char arr[51];
	char numarr[6];
	int result = 0;
	bool is_sub = false;

	scanf("%s", arr);

	int i = 0;
	int j = 0;
	int flag = 0;

	while (arr[i] != '\0')
	{
		if (arr[i] == '-' || arr[i] == '+')	//arr[i] is character
		{
			flag ? (result -= atoi(numarr)) : (result += atoi(numarr));

			memset(numarr, NULL, 6);
			j = 0;

			if (arr[i] == '-')	
				flag = 1;
		}
		else	//arr[i] is number
		{
			numarr[j] = arr[i];
			j++;
		}
				
		i++;
	}
	flag ? (result -= atoi(numarr)) : (result += atoi(numarr));

	printf("%d\n", result);

	return 0;
}