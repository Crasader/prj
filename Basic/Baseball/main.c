#pragma warning( disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Set();
int Match(int Correct, int input1, int input2, int input3);
int ShowResult(int Result);

int main()
{
	srand((int)time(NULL));

	int input1, input2, input3;
	int NofS = 0, Result;

	int Correct = Set();
	printf("야구게임 시작!\n\n");

	for (NofS = 1;; NofS++)
	{
		printf("세 수 입력 : a b c\n");
		scanf("%d %d %d", &input1, &input2, &input3);

		Result = Match(Correct, input1, input2, input3);
		ShowResult(Result);

		if (Result == 300)
		{
			break;
		}
	}

	printf("정답! : %d%d%d\n", input1, input2, input3);
	printf("시도회수 : %d\n", NofS);

	return 0;
}

int Set()
{
	int A, B, C;

	A = rand() % 10;
	B = A; C = A;

	for (; A == B || A == C || B == C;)
	{
		B = rand() % 10;
		C = rand() % 10;
	}

	return 100 * A + 10 * B + C;
}

int Match(int Correct, int input1, int input2, int input3)
{
	int Result = 0;

	//Check Strike
	for (int i = 0; i < 3; i++)
	{
		int number = CutNumber(Correct, i);

		for (int j = 0; j < 3; j++)
		{
			int try;
			if (j == 0) try = input1;
			if (j == 1) try = input2;
			if (j == 2) try = input3;

			if (try == number)
			{
				if (i == j)	Result += 100;
				else Result += 10;
			}

			//printf("%d : %d\n", j, Result);
		}
	}

	return Result;
}

int ShowResult(int Result)
{
	printf("\n%d 스트라이크\n", Result / 100);
	printf("%d 볼\n", Result / 10 % 10);
	printf("%d 아웃\n\n", 3 - Result / 100 - Result / 10 % 10);
}

int CutNumber(int number, int sub)
{
	if (sub == 0) number = number / 100;
	else if (sub == 1) number = number / 10 % 10;
	else if (sub == 2) number = number % 10;

	return number;
}





// 0 ~ 9 까지 세 수를 순서대로 저장
// 세개씩 번호를 순서대로 부름
// 순서가 틀리고 셋 안에 있으면 볼
// 순서도 맞으면 스트라이크
// 하나도 안맞으면 아웃

// 100x -> 스트라이크
// 10x -> 볼
// 1x -> 아웃