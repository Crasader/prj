
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
		printf("��ȸ�� %d�� ���ҽ��ϴ�.\n", tryCount - idx);
		printf("0 ~ 100������ �� �ϳ� �Է� : ");
		scanf("%d", &input);

		result = match(Correct, input);
		switch (result)
		{
			case 0: printf("������ %d���� Ů�ϴ�.\n", input);	break;
			case 1: printf("����!\n", input);	break;
			case 2: printf("������ %d���� �۽��ϴ�.\n", input);	break;
		}

		printf("\n");
	}

	if (Correct != input)
	{
		printf("����! ������ %d�����ϴ�!\n",Correct);
	}
	else
	{
		printf("%d������ �����߽��ϴ�!\n", idx);
	}
	
	return 0;
}