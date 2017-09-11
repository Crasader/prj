
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
int replay();

int main()
{
	int tryCount = 6;
	int Correct, input, result = 0;
	int idx = 0;

	int end = 0;

	srand((int)time(NULL));

	for (;end == 0;)
	{
		Correct = rand() % 101;

		printf("나는 지금 0부터 100사이의 값 중에 하나를 생각하겠습니다.\n");
		printf("당신은 그 숫자를 %d회 안에 맞추시면 됩니다!\n\n", tryCount);

		//printf("%d\n", Correct);

		for (idx = 0; idx < tryCount && result != 1; idx++)
		{
			printf("0 ~ 100까지의 수 하나 입력 : ");
			scanf("%d", &input);

			result = match(Correct, input);
			switch (result)
			{
				case 0: printf("정답은 %d보다 큽니다.\n", input);	break;
				case 1: printf("정답!\n", input);	break;
				case 2: printf("정답은 %d보다 작습니다.\n", input);	break;
			}

			if (Correct != input)
			{
				printf("기회가 [ %d ]번 남았습니다.\n", tryCount - idx - 1);
			}

			printf("\n");
		}

		if (Correct != input)
		{
			printf("실패! 정답은 %d였습니다!\n", Correct);
		}
		else
		{
			printf("%d번만에 성공했습니다!\n", idx);
		}

		////////////////////////////////////////////////

		printf("다시 하시겠습니까? (y/n)\n");
		end = replay();
	}

	
	return 0;
}

int replay()
{
	char input;
	for (;;)
	{
		rewind(stdin);
		scanf("%c", &input);
		if (input == 'n' || input == 'N')
		{
			return 1;
		}
		else if (input == 'y' || input == 'Y')
		{
			return 0;
		}
		else
		{
			printf("다시 입력해주세요 : \n");
		}
	}
}