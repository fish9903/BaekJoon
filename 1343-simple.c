#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char arr[500] = { 0, };
    int start = 0, end = 0;
    int count = 0;

    scanf("%s%*c", arr);

    for (int i = 0; i < strlen(arr) + 1; i++)
    {        
        if (arr[i] == 'X')
        {
            count++;
        }
        else
        {
            int j = 0;

            if (count % 2 != 0) // È¦¼ö
            {
                printf("-1\n");
                return 0;
            }
            else if (count == 2)    // ¿©±â¼­ ºÎÅÍ Â¦¼ö
            {
                for (j = start; j < start + count; j++)
                {
                    arr[j] = 'B';
                }
                start = j + 1;
                count = 0;
            }
            else if (count % 4 == 0)
            {
                for (j = start; j < start + count; j++)
                {
                    arr[j] = 'A';
                }
                start = j + 1;
                count = 0;
            }
            else
            {
                for (j = start; j < start + count - 2; j++)
                {
                    arr[j] = 'A';
                }
                
                for (; j < start + count; j++)
                {
                    arr[j] = 'B';
                }
                start = j + 1;
                count = 0;
            }
        }
    }

    printf("%s", arr);

    return 0;
}