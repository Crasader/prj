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

	printf("1에서 100 사이의 값 하나를 정답으로 정해주세요.\n");
	printf("정답이 제시하는 값보다 크면 h를, 작으면 l을 눌러주세요.\n");
	printf("만약 정답이라면, y를 입력해주세요.\n");

	for (;;)
	{
		printf("정답은 %d인가요?\n", guess.Answer);
		Input = getch();
		printf("%c\n", Input);

		if (Input == 'y' || Input == 'h' || Input == 'l')
		{
			NoT++;
			if (Input == 'y')
			{
				printf("%d번만에 정답! XD\n", NoT);
				break;
			}
			else
			{
				check(&guess, Input);
			}

			//

			if (oldAnswer == guess.Answer || oldOLDAnswer == guess.Answer)
			{
				printf("ㅡㅡ\n");
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
