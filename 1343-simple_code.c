#include <stdio.h>
#include <string.h>

int main(void)
{
	int i=0;
	int mode=1;
	char board[500];
	scanf("%s",board);
	while(i!=strlen(board))
	{
		if(board[i]=='X'&&board[i+1]=='X'&&board[i+2]=='X'&&board[i+3]=='X')
		{
			board[i]='A';
			board[i+1]='A';
			board[i+2]='A';
			board[i+3]='A';
			i+=4;
		}
		else if(board[i]=='X'&&board[i+1]=='X')
		{
			board[i]='B';
			board[i+1]='B';
			i+=2;
		}
		else if(board[i]=='.')
		{
			i+=1;
		}
		else
		{
			mode=0;
			break;
		}
	}
	if(mode==0)
		printf("-1");
	else
		printf("%s",board);
	return 0;
}