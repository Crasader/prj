#include <stdio.h>

typedef struct Guess
{
	int Answer;
	int Max;
	int Min;
}Guess;

void check(Guess *guess, char Input);

int main()
{
	Guess guess = { 50, 100, 1 };

	int oldAnswer = 0;
	int oldOLDAnswer = 0;
	int NoT = 0;
	char Input;

	printf("1���� 100 ������ �� �ϳ��� �������� �����ּ���.\n");
	printf("������ �����ϴ� ������ ũ�� h��, ������ l�� �����ּ���.\n");
	printf("���� �����̶��, y�� �Է����ּ���.\n");

	for (;;)
	{
		printf("������ %d�ΰ���?\n", guess.Answer);
		Input = getch();
		printf("%c\n", Input);

		if (Input == 'y' || Input == 'h' || Input == 'l')
		{
			NoT++;
			if (Input == 'y')
			{
				printf("%d������ ����! XD\n", NoT);
				break;
			}
			else
			{
				check(&guess, Input);
			}

			//

			if (oldAnswer == guess.Answer || oldOLDAnswer == guess.Answer)
			{
				printf("�Ѥ�\n");
				break;
			}
			oldOLDAnswer = oldAnswer;
			oldAnswer = guess.Answer;
		}

	}

	return 0;
}

void check(Guess *guess, char Input)
{
	int mid;
	if (Input == 'h')
	{
		guess->Min = guess->Answer;

		mid = guess->Max + guess->Min;
		
		if (mid == 199)	mid = 100;
		else mid /= 2;

		guess->Answer = mid;
	}
	else
	{
		guess->Max = guess->Answer;

		mid = guess->Max + guess->Min;;
		mid /= 2;

		guess->Answer = mid;
	}
}
