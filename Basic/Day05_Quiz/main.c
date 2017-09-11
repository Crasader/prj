
#pragma warning( disable : 4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Ai_Pick();
void numToStr(int num);
void showHand(int input, int AiPick);
void Judge(int Player, int Ai);

int main()
{
	srand((int)time(NULL));

	int input = -1;
	for (;;)
	{
		printf("1.가위\n2.바위\n3.보\n\n0.그만!\n");
		scanf("%d", &input);

		if (input >= 1 && input <= 3)
		{
			Judge(input, Ai_Pick());
		}
		else if (input == 0)
		{
			break;
		}
		else
		{
			printf("\n!잘못된 입력입니다!\n\n");
		}
	}

	printf("끝!\n");

	return 0;
}


int Ai_Pick()
{
	int pick;
	pick = rand() % 3 + 1;
	return pick;
}

void Judge(int Player, int Ai)
{
	int result;

	if (Player == Ai)	result = 0;
	else
	{
		int temp = Player - Ai;
		if (temp == 1 || temp == -2)
		{
			result = 1;
		}
		else
			result = 2;
	}

	showHand(Player, Ai);
	switch (result)
	{
		case 0:printf("비겼습니다."); break;
		case 1:printf("이겼습니다."); break;
		case 2:printf("졌습니다."); break;
	}
	printf("\n\n");
}

void showHand(int input, int AiPick)
{
	printf("\n플레이어 : ");
	numToStr(input);

	printf("Ai : ");
	numToStr(AiPick);

	printf("\n");
}

void numToStr(int num)
{
	switch (num)
	{
		case 1: printf("가위"); break;
		case 2: printf("바위"); break;
		case 3: printf("보"); break;
	}
	printf("\n");
}
