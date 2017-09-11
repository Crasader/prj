
#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int match(int Correct, int input)
{
	if (Correct == input)
		return 1;
	else if (Correct < input)
		return 2;
	else return 0;
}

int main()
{
	int tryCount = 7;
	int Correct, input, result = 0;
	int idx = 0;

	srand((int)time(NULL));
	Correct = rand() % 101;

	//printf("%d\n", Correct);

	for (idx = 0; idx < tryCount && result != 1; idx++)
	{
		printf("기회가 %d번 남았습니다.\n", tryCount - idx);
		printf("0 ~ 100까지의 수 하나 입력 : ");
		scanf("%d", &input);

		result = match(Correct, input);
		switch (result)
		{
			case 0: printf("정답은 %d보다 큽니다.\n", input);	break;
			case 1: printf("정답!\n", input);	break;
			case 2: printf("정답은 %d보다 작습니다.\n", input);	break;
		}

		printf("\n");
	}

	if (Correct != input)
	{
		printf("실패! 정답은 %d였습니다!\n",Correct);
	}
	else
	{
		printf("%d번만에 성공했습니다!\n", idx);
	}
	
	return 0;
}